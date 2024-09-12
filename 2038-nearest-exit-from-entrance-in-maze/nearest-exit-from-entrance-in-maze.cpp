#include "bits/stdc++.h"
using namespace std;

class Solution {
public:
    int nearestExit(vector<vector<char>>& maze, vector<int>& entrance) {
        queue<vector<int>> bfs;
        int currenty=entrance[0];
        int currentx=entrance[1];
        int distance=0;
        int m=maze.size();
        int n=maze[0].size();
        //m for y and n for x
        vector<vector<int>> ways={{-1,0},{1,0},{0,1},{0,-1}};
        //0 for y / 1 for x/ 2 for distance
        bfs.push({currenty,currentx,distance});
        maze[currenty][currentx]='-';
        while (!bfs.empty())
        {
            
            currenty=bfs.front()[0];
            currentx=bfs.front()[1];
            distance=bfs.front()[2];
            bfs.pop();

            for(int i=0;i<4;i++)
            {
                int newy=currenty+ways[i][0];
                int newx=currentx+ways[i][1];
                if(newy>=0 &&newy<m &&newx>=0 &&newx<n )
                {
                    if(maze[newy][newx]=='.')
                    {
                        if(newy==0||newy==m-1||newx==0||newx==n-1)
                        {
                            return distance+1;
                        }
                        else
                        {
                            bfs.push({newy,newx,distance+1});
                            maze[newy][newx]='-';
                        }
                    }

                } 
            }
        }
        



        return -1;
        
    }
};
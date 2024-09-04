#include "bits/stdc++.h"
using namespace std;
class Solution {
public:

    long long int myHash(int x,int y)
    {
        return x+60001*y;//x,y=-30000~30000 60001可以覆蓋它們所有的差額 變成以y為座標 向x偏移多少 這個結果必定是獨特的
    }
    int robotSim(vector<int>& commands, vector<vector<int>>& obstacles) {
        int n=commands.size();
        vector<pair<int,int>> direction={{0,1},{1,0},{0,-1},{-1,0}};
        int currentDirection=0;
        int currentx=0;
        int currenty=0;
        unordered_set<long long int> obstacleSet;
        long long int farrest=0;
        for(auto obstacle:obstacles)
        {
            obstacleSet.insert(myHash(obstacle[0],obstacle[1]));
        }

        for(int i=0;i<n;i++)
        {
            if(commands[i]==-1)
            {
                currentDirection++;
                if(currentDirection>=4)
                {
                    currentDirection=0;
                }
            }
            else if(commands[i]==-2)
            {
                currentDirection--;
                if(currentDirection<0)
                {
                    currentDirection=3;
                }

            }
            else
            {
                for(int j=0;j<commands[i];j++)
                {
                    if(obstacleSet.count(myHash(currentx+direction[currentDirection].first,currenty+direction[currentDirection].second)))
                    {
                        //meet obstacle
                        break;
                    }
                    else
                    {
                        currentx+=direction[currentDirection].first;
                        currenty+=direction[currentDirection].second;
                        farrest=max(farrest,(long long int)currentx*(long long int)currentx+(long long int)currenty*(long long int)currenty);
                    }

                }
            }
        }

        return farrest;


        
    }
};
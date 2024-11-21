#include "bits/stdc++.h"
using namespace std;
class Solution {
public:
    int countUnguarded(int m, int n, vector<vector<int>>& guards, vector<vector<int>>& walls) {
        vector< vector<int> >grid(m,vector<int>(n,0));
        int ans=0;
        for(vector<int> &guard:guards)
        {
            grid[guard[0]][guard[1]]=-1;
        }
        for(vector<int> &wall:walls)
        {
            grid[wall[0]][wall[1]]=-2;
        }
        for(vector<int> &guard:guards)
        {
            int current_m=guard[0];
            int current_n=guard[1];

            //up
            for(int i=current_m-1;i>=0;i--)
            {
                if(grid[i][current_n]<0)
                {
                    break;
                }
                else
                {
                    grid[i][current_n]=1;
                }   
            }
            //down
            for(int i=current_m+1;i<m;i++)
            {
                if(grid[i][current_n]<0)
                {
                    break;
                }
                else
                {
                    grid[i][current_n]=1;
                }   
            }
            //left
            for(int i=current_n-1;i>=0;i--)
            {
                if(grid[current_m][i]<0)
                {
                    break;
                }
                else
                {
                    grid[current_m][i]=1;
                }   
            }
            //right 
            for(int i=current_n+1;i<n;i++)
            {
                if(grid[current_m][i]<0)
                {
                    break;
                }
                else
                {
                    grid[current_m][i]=1;
                }   
            }                       
        }

        for(auto &x:grid)
        {
            for(auto &y:x)
            {
                if(y==0)
                {
                    ans++;
                }
            }
        }

        return ans;
        
    }
};
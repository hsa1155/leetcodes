#include "bits/stdc++.h"
using namespace std;
class Solution {
public:

    vector<int> row = {0, 0, 1, -1};
    vector<int> col = {1, -1, 0, 0};
    int bfs(vector<vector<int>>& grid,vector<vector<bool>> &visited,int i,int j)
    {
        queue<pair<int,int>> q;
        int m=grid.size();
        int n=grid[0].size();
        q.push({i,j});
        visited[i][j]=true;
        int ans=0;

        while (!q.empty())
        {
            pair<int,int> current=q.front();
            q.pop();
            visited[current.first][current.second]=true;
            ans+=grid[current.first][current.second];
            
            for(int k=0;k<4;k++)
            {
                int nexti=current.first+row[k];
                int nextj=current.second+col[k];

                if(nexti>=0&&nextj>=0&&nexti<m&&nextj<n&&!visited[nexti][nextj]&&grid[nexti][nextj]>0)
                {
                    q.push({nexti,nextj});
                    visited[nexti][nextj]=true;
                }
            }

        }

        return ans;
        
    }

    int findMaxFish(vector<vector<int>>& grid) {
        int m=grid.size();
        int n=grid[0].size();
        vector<vector<bool>> visited(m,vector<bool>(n,false));

        int ans=0;

        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(!visited[i][j]&&grid[i][j]!=0)
                {
                    ans=max(ans,bfs(grid,visited,i,j));
                }
            }
        }

        return ans;

        
    }
};
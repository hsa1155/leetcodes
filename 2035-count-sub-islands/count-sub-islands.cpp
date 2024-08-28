#include "bits/stdc++.h"
using namespace std;

class Solution
{
public:
    struct island
    {
        vector<vector<int>> location; //[blocks][0]=x [1]=y
        int blocks = 0;
        int index = -1;
    };

    void dfs(island *newisnald, vector<vector<int>> &grid, int i, int j)
    {
        int x = grid[0].size();
        int y = grid.size();
        newisnald->blocks++;
        newisnald->location.push_back({i, j});
        grid[i][j] = newisnald->index;

        if (i - 1 >= 0)
        {
            if (grid[i - 1][j] == 1)
            {
                dfs(newisnald, grid, i - 1, j);
            }
        }
        if (j - 1 >= 0)
        {
            if (grid[i][j - 1] == 1)
            {
                dfs(newisnald, grid, i, j - 1);
            }
        }
        if (i + 1 < y)
        {
            if (grid[i + 1][j] == 1)
            {
                dfs(newisnald, grid, i + 1, j);
            }
        }
        if (j + 1 < x)
        {
            if (grid[i][j + 1] == 1)
            {
                dfs(newisnald, grid, i, j + 1);
            }
        }
    }

    int countSubIslands(vector<vector<int>> &grid1, vector<vector<int>> &grid2)
    {
        vector<island> island1, island2;

        int x = grid1[0].size();
        int y = grid1.size();
        int island1count = 0;
        int island2count = 0;
        int subislands=0;

        for (int i = 0; i < y; i++)
        {
            for (int j = 0; j < x; j++)
            {
                if (grid1[i][j] == 1)
                {
                    // find new island
                    island *newisnald = new island();
                    newisnald->index = island1count + 2;
                    island1count++;
                    dfs(newisnald, grid1, i, j);
                    island1.push_back(*newisnald);
                }

                if (grid2[i][j] == 1)
                {
                    // find new island
                    island *newisnald = new island();
                    newisnald->index = island2count + 2;
                    island2count++;
                    dfs(newisnald, grid2, i, j);
                    island2.push_back(*newisnald);
                    
                }
            }
        }

        for(int k=0;k<island2count;k++)
        {
            bool issub=true;
            int subindex=grid1[island2[k].location[0][0]][island2[k].location[0][1]];
            if(subindex==0) continue;
            for(auto x:island2[k].location)
            {
                if(grid1[x[0]][x[1]]!=subindex)
                {
                    issub=false;
                    break;
                }
            }
            if(issub)
            {
                subislands++;
            }
        }
        

        return subislands;
    }
};
/*
 for (int q = 0; q < x; q++)
                    {
                        for (int k = 0; k < y; k++)
                        {
                            cout << grid1[q][k] << " ";
                        }
                        cout << endl;
                    }

                    */
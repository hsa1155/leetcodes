#include "bits/stdc++.h"
using namespace std;

class Solution
{
public:
    int maxMoves(vector<vector<int>> &grid)
    {
        int m = grid.size();
        int n = grid[0].size();
        vector<int> dp(m, 0);
        vector<int> tmp(m, 0);
        int ans=0;

        for (int i = 0; i < m; i++)
        {
            if (i == 0)
            {
                if (grid[i][1] > grid[i][0] || grid[i + 1][1] > grid[i][0])
                {
                    dp[i] = 1;
                    ans=1;
                    tmp[i] = 1;
                }
                continue;
            }
            if (i == m - 1)
            {
                if (grid[i][1] > grid[i][0] || grid[i - 1][1] > grid[i][0])
                {
                    dp[i] = 1;
                    ans=1;
                    tmp[i] = 1;
                }
                continue;
            }

            if (grid[i][1] > grid[i][0] || grid[i - 1][1] > grid[i][0] || grid[i + 1][1] > grid[i][0])
            {
                dp[i] = 1;
                ans=1;
                tmp[i] = 1;
            }
        }

        for (int j = 1; j < n - 1; j++)
        {

            for (int i = 0; i < m; i++)
            {
                int current=0;
                if (i == 0)
                {
                    if(grid[i][j]>grid[i][j-1])
                    {
                        current=max(current,tmp[i]);
                    }
                    if(grid[i][j]>grid[i+1][j-1])
                    {
                        current=max(current,tmp[i+1]);
                    }
                }
                else if (i == m - 1)
                {
                    if(grid[i][j]>grid[i][j-1])
                    {
                        current=max(current,tmp[i]);
                    }
                    if(grid[i][j]>grid[i-1][j-1])
                    {
                        current=max(current,tmp[i-1]);
                    }
                }
                else
                {
                    if(grid[i][j]>grid[i][j-1])
                    {
                        current=max(current,tmp[i]);
                    }
                    if(grid[i][j]>grid[i+1][j-1])
                    {
                        current=max(current,tmp[i+1]);
                    }
                    if(grid[i][j]>grid[i-1][j-1])
                    {
                        current=max(current,tmp[i-1]);
                    }
                }
                if (current == 0)
                {
                    dp[i] = 0;
                    continue;
                }
                else
                {
                    if (i == 0)
                    {
                        if (grid[i][j+1] > grid[i][j] || grid[i + 1][j+1] > grid[i][j])
                        {
                            dp[i] = current+1;
                            ans=max(ans,dp[i]);
                        }
                        continue;
                    }
                    if (i == m - 1)
                    {
                        if (grid[i][j+1] > grid[i][j] || grid[i - 1][j+1] > grid[i][j])
                        {
                            dp[i] = current+1;
                            ans=max(ans,dp[i]);
                        }
                        continue;
                    }
                    if (grid[i][j+1] > grid[i][j] || grid[i - 1][j+1] > grid[i][j] || grid[i + 1][j+1] > grid[i][j])
                    {
                        dp[i] = current+1;
                        ans=max(ans,dp[i]);
                    }
                }
            }
            swap(dp,tmp);
        }


        return ans;
    }
};
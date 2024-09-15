#include "bits/stdc++.h"
using namespace std;

class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {
        int m=text1.size();
        int n=text2.size();
        vector<vector<int>> dp(n+1,vector<int>(m+1,0));

        for(int i=1;i<=m;i++)
        {
            for(int j=1;j<=n;j++)
            {
                if(text1[i-1]==text2[j-1])
                {
                    dp[j][i]=dp[j-1][i-1]+1;
                }
                else
                {
                    dp[j][i]=max(dp[j][i-1],dp[j-1][i]);
                }
            }
        }
        return dp[n][m];
        
    }
};
#include "bits/stdc++.h"
using namespace std;
class Solution {
public:
    vector<vector<char>> rotateTheBox(vector<vector<char>>& box) {
        int m=box.size();
        int n=box[0].size();
        vector<vector<char>> ans(n,vector<char>(m,'.'));
        for(int i=0;i<m;i++)
        {
            //each row

            int current=n-1;
            int last_obs=-1;
            
            for(int j=n-1;j>=0;j--)
            {
                if(box[i][j]=='.')
                {
                    continue;
                }
                if(box[i][j]=='*')
                {
                    current=j-1;
                    ans[j][m-1-i]='*';
                    continue;
                }
                if(box[i][j]=='#')
                {
                    ans[current--][m-1-i]='#';
                }
            }
        }

        return ans;
    }
};
#include "bits/stdc++.h"
using namespace std;
class Solution {
public:
    int equalPairs(vector<vector<int>>& grid) {
        unordered_map<string,int> mp;
        int n=grid.size();
        int count=0;

        for(int i=0;i<n;i++)
        {
            string tmp;
            for(int j=0;j<n;j++)
            {
                tmp.append(to_string(grid[i][j]));
                tmp.append("/");
            }
            cout<<tmp<<endl;
            mp[tmp]++;
        }

        for(int j=0;j<n;j++)
        {
            string tmp;
            for(int i=0;i<n;i++)
            {
                tmp.append(to_string(grid[i][j]));
                tmp.append("/");
            }
            cout<<tmp<<endl;
            count+=mp[tmp];
        }

        return count;
        
    }
};
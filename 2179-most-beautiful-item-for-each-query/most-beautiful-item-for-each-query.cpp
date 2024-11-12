#include "bits/stdc++.h"
using namespace std;
class Solution
{
public:
    vector<int> maximumBeauty(vector<vector<int>> &items, vector<int> &queries)
    {
        int n = queries.size();
        unordered_map<int,int> mp;
        vector<int> ans;
        vector<pair<int, int>> tmp(n);
        for (int i = 0; i < n; i++)
        {
            tmp[i].first = queries[i];
            tmp[i].second = INT_MIN;
        }
        sort(tmp.begin(), tmp.end());
        sort(items.begin(), items.end());
        int maxi = INT_MIN;
        int current = 0;

        for (vector<int> &item : items)
        {
            while (current < n && tmp[current].first < item[0])
            {
                tmp[current++].second = maxi;
            }
            if (current == n)
            {
                current--;
            }
            if (tmp[current].first >= item[0])
            {
                maxi = max(maxi, item[1]);
            }
            tmp[current].second = max(tmp[current].second, maxi);
        }
        maxi = INT_MIN;

        for(pair<int,int> &x:tmp)
        {
            maxi=max(maxi,x.second);
            x.second=max(x.second,maxi);
        }
        for (pair<int, int> &x : tmp)
        {
            mp[x.first]=x.second;
        }

        for(int x:queries)
        {
            if(mp[x]<0)
            {
                ans.push_back(0);
            }
            else
            {
                ans.push_back(mp[x]);
            }
        }

        return ans;
    }
};
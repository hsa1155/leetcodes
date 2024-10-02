#include "bits/stdc++.h"
using namespace std;


class Solution {
public:
    vector<int> arrayRankTransform(vector<int>& arr) {

        int n=arr.size();
        if(n==0) return {};

        vector<pair<int,int>> index(n);

        for(int i=0;i<n;i++)
        {
            index[i].first=arr[i];
            index[i].second=i;
        }
        sort(index.begin(),index.end());
        int count=1;
        vector<int> ans(n);
        ans[index[0].second]=count;
        for(int i=1;i<n;i++)
        {
            if(index[i-1].first!=index[i].first)
            {
                count++;
            }
            ans[index[i].second]=count;
        }


        return ans;

        
    }
};
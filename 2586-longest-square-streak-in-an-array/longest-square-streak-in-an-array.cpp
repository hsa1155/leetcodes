#include "bits/stdc++.h"
using namespace std;

class Solution {
public:
    int longestSquareStreak(vector<int>& nums) {
        int len=1;
        unordered_map<long long int,int> mp;
        sort(nums.begin(),nums.end(),greater<int>());

        for(long long int x:nums)
        {
            if(mp.find(x*x)!=mp.end())
            {
                mp[x]=mp[x*x]+1;
                len=max(len,mp[x]);
            }
            else
            {
                mp[x]=1;
            }
        }

        if(len==1)
        {
            return -1;
        }
        else
        {
            return len;
        }

        
    }
};
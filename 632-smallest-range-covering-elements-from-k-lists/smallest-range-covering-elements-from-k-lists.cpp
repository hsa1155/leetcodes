#include "bits/stdc++.h"
using namespace std;

class Solution {
public:
    vector<int> smallestRange(vector<vector<int>>& nums) {
        int k=nums.size();
        vector<pair<int,int>> all;
        bitset<3500> b1,b2;
        unordered_map<int,int> mp;// first = index of kth array / second = how many nums of kth array in window
        int left=0;



        for(int i=0;i<k;i++)
        {
            for(int &x:nums[i])
            {
                all.push_back({x,i});
            }
            b1[i]=1;
        }
        sort(all.begin(),all.end());
        int n=all.size();
        int ansLength=INT_MAX;
        vector<int> ans(2);


        for(int i=0;i<n;i++)
        {
            b2[all[i].second]=1;
            mp[all[i].second]++;

            while (mp[all[left].second]>1 )
            {
                mp[all[left].second]--;
                left++;
            }

            if(b1==b2)
            {
                if(all[i].first-all[left].first<ansLength)
                {
                    ansLength=all[i].first-all[left].first;
                    ans[0]=all[left].first;
                    ans[1]=all[i].first;
                }
            }
            

        }




        return ans;
        
    }
};
#include "bits/stdc++.h"
using namespace std;


class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_multimap<int,int> um;//value,index
        int n=nums.size();

        for(int i=0;i<n;i++)
        {
            unordered_multimap<int,int>::iterator it=um.find(target-nums[i]);
            if(it!=um.end())
            {
                return {i,it->second};
            }
            else
            {
                um.insert(pair<int,int>(nums[i],i));
            }

        }

        return {};

        
    }
};
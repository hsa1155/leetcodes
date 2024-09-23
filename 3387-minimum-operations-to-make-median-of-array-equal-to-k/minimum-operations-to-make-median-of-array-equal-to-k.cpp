#include "bits/stdc++.h"
using namespace std;


class Solution {
public:
    long long minOperationsToMakeMedianK(vector<int>& nums, int k) {

        int n=nums.size();
        sort(nums.begin(),nums.end());
        int mid=ceil((n-1.)/2.);
        long long int ans=0;
        
        if(nums[mid]==k)
        {
            return 0;
        }


        if(nums[mid]<k)
        {

            for(int i=mid;i<n;i++)
            {
                if(nums[i]<k)
                ans+=k-nums[i];
            }
        }
        else
        {
            for(int i=0;i<=mid;i++)
            {
                if(nums[i]>k)
                {
                    ans+=nums[i]-k;
                }
            }
        }




        return ans;
    }
};
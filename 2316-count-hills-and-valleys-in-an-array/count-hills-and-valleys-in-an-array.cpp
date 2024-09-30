#include "bits/stdc++.h"
using namespace std;

class Solution {
public:
    int countHillValley(vector<int>& nums) {

        int last=nums[0];
        int n=nums.size();
        int ans=0;

        for(int i=1;i<=n-2;i++)
        {
            if(nums[i]>last&&nums[i]>nums[i+1])
            {
                ans++;
                last=nums[i];
            }
            else if(nums[i]<last&&nums[i]<nums[i+1])
            {
                ans++;
                last=nums[i];
            }
            else if(nums[i]!=nums[i+1])
            {
                last=nums[i];
            }
        }

        return ans;
        
    }
};
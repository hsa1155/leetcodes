#include "bits/stdc++.h"
using namespace std;
class Solution {
public:
    vector<int> getMaximumXor(vector<int>& nums, int maximumBit) {
        int n=nums.size();
        vector<int> ans(n,0);
        int target=(1<<maximumBit) -1;
        int current=0;
        for(int x:nums)
        {
            current^=x;
        }

        for(int i=n-1;i>=0;i--)
        {
            ans[n-1-i]=target^current;

            current^=nums[i];
        }

        return ans;
    }
};
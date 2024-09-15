#include "bits/stdc++.h"
using namespace std;

class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        int n=nums.size();
        vector<int> prefix(n,0);
        prefix[0]=nums[0];

        for(int i=1;i<n;i++)
        {
            prefix[i]=prefix[i-1]+nums[i];
        }
        if((prefix[n-1]-nums[0])==0)
        {
            return 0;
        }

        for(int i=1;i<n;i++)
        {
            if((prefix[n-1]-prefix[i])==prefix[i-1])
            {   
                return i;

            }
        }

        return -1;
        
    }
};
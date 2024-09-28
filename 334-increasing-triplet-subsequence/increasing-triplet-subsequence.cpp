#include "bits/stdc++.h"
using namespace std;
class Solution {
public:
    bool increasingTriplet(vector<int>& nums) {
        int n=nums.size();
        int prev[3];
        int current=0;
        prev[0]=nums[0];

        for(int i=1;i<n;i++)
        {
            if(nums[i]>prev[current])
            {
                prev[++current]=nums[i];
                if(current==2)
                {
                    return true;
                }
            }
            if(nums[i]<prev[current])
            {
                if(current==0)
                {
                    prev[0]=nums[i];
                }
                else if(current==1)
                {
                    if(prev[0]>=nums[i])
                    {
                        prev[0]=nums[i];
                    }
                    else
                    {
                        prev[1]=nums[i];
                    }

                }

            }
        }
       
        
        return false;
        
    }
};

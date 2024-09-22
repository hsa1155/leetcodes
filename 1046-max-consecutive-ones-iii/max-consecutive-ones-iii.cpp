#include "bits/stdc++.h"
using namespace std;


class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int left=0;
        int n=nums.size();
        

        int one=0;
        int zero=0;
        int ans=0;

        for(int i=0;i<n;i++)
        {

            if(nums[i]==1)
            {
                one++;
            }
            else
            {
                while (zero+1>k&&left<i)
                {
                    //exceeds
                    if(nums[left]==0)
                    {
                        left++;
                        zero--;
                    }
                    else
                    {
                        left++;
                        one--;
                    }
                }
                zero++;                        
            }





            ans=max(ans,one+min(zero,k));
        }

        return ans;



        
    }
};
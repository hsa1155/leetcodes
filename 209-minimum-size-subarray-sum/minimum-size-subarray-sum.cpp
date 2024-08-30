#include "bits/stdc++.h"
using namespace std;
class Solution
{
public:
    int minSubArrayLen(int target, vector<int> &nums)
    {
        int start = 0;
        int end = 0;
        int minLength = INT_MAX;
        int currentSum = 0;
        int n = nums.size();

        for (int i = 0; i < n; i++)
        {
           currentSum+=nums[i];

            if(currentSum< target )
            {   
                continue;
            }
            else
            {

                while(start<i)
                {
                    if(currentSum-nums[start]>target)
                    {
                        currentSum-=nums[start++];
                    }
                    else if(currentSum-nums[start]==target)
                    {
                        currentSum-=nums[start++];
                        minLength=min(minLength,i-start+1);
                    }
                    else
                    {
                        minLength=min(minLength,i-start+1);
                        currentSum-=nums[start++];
                        break;
                    }
                }
                if(start==i)
                {
                    currentSum=nums[i];
                    if(currentSum>=target)
                    {
                        minLength=min(minLength,1);
                    }

                }
            }



        }
        if(minLength==INT_MAX) return 0;

        return minLength;
    }
};
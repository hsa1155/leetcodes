#include "bits/stdc++.h"
using namespace std;
class Solution
{
public:
    int minSubArrayLen(int k, vector<int> &nums)
    {
        long long int current=0;
        int ans=INT_MAX;
        int n=nums.size();
        int left=0;

        for(int i=0;i<n;i++)
        {
            current+=nums[i];
            cout<<current<<current-nums[left]<<endl;
            while (current-nums[left]>=k&&left<i)
            {
                current-=nums[left++];
                cout<<current<<endl;
            }

            if(current>=k)
            {
                ans=min(ans,i-left+1);
            }
            
        }

        if(ans==INT_MAX)
        {
            return 0;
        }
        else
        {
            return ans;
        }
    }
};
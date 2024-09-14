#include "bits/stdc++.h"
using namespace std;

class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int maximum=INT_MIN;
        int maxcount=0;
        int count=0;

        for(int x:nums)
        {
            if(x>maximum)
            {
                maximum=x;
                maxcount=1;
                count=1;
            }
            else if(x<maximum)
            {
                maxcount=max(maxcount,count);
                count=0;
                continue;
            }
            else
            {
                count++;
            }
        }
        maxcount=max(maxcount,count);
        return maxcount;


        
    }
};
#include "bits/stdc++.h"
using namespace std;


class Solution {
public:
    bool isPalindrome(int x) {
        
        if(x<0)
        {
            return false;
        }
        vector<int> nums;

        while (x>0)
        {
            nums.push_back(x%10);
            x/=10;
        }
        int n=nums.size();
        if(n==1)
        {
            return true;
        }

        for(int i=0;i<n/2;i++)
        {
            if(nums[i]==nums[n-1-i])
            {
                continue;
            }
            else
            {
                return false;
            }
        }

        return true;
        
    }
};
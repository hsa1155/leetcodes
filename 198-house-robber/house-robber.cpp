#include "bits/stdc++.h"
using namespace std;

class Solution {
public:
    int rob(vector<int>& nums) {
        int n=nums.size();
        int current;
        int first=0;
        int second=0;

        for(int i=n-1;i>=0;i--)
        {
            current=max(nums[i]+second,first);
            second=first;
            first=current;
        }   

        return current;

        
    }
};
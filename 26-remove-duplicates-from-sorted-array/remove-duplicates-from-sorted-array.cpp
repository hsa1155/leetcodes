#include "bits/stdc++.h"
using namespace std;

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int left=0;
        unordered_set<int> st;

        for(int &x:nums)
        {
            if(st.find(x)==st.end())
            {
                nums[left++]=x;
                st.insert(x);
            }
        }

        return left;
        
    }
};
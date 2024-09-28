#include "bits/stdc++.h"
using namespace std;
class Solution {
public:
    int maxOperations(vector<int>& nums, int k) {
        unordered_map<int,int> mp;
        int count=0;

        for(int &x:nums)
        {
            if(mp[k-x]>=1)
            {
                mp[k-x]--;
                count++;
            }
            else
            {
                mp[x]++;
            }
        }
        return count;
        
    }
};
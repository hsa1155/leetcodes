#include "bits/stdc++.h"
using namespace std;

class Solution {
public:
    bool uniqueOccurrences(vector<int>& arr) {
        map<int,int> nums;
        for(int x:arr)
        {
            nums[x]++;
        }
        set<int> occur;

        for(pair<int,int> pr:nums)
        {
            if(occur.count(pr.second)==1)
            {
                return false;
            }
            else
            {
                occur.insert(pr.second);
            }

        }
        return true;

        
    }
};
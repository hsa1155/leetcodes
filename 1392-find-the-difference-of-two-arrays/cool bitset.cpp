#include "bits/stdc++.h"
using namespace std;

class Solution {
public:
    vector<vector<int>> findDifference(vector<int>& nums1, vector<int>& nums2) {
        vector<vector<int>> result(2);
        int n1=nums1.size();
        int n2=nums2.size();
        bitset<2001> s1,s2,tmp;//-1000=[0] 1000=[2000] x=[x+1000]
        for(int i=0;i<n1;i++)
        {
            s1.set(nums1[i]+1000);
        }
        for(int i=0;i<n2;i++)
        {
            s2.set(nums2[i]+1000);
        }
        tmp=s1&s2;
        s1^=tmp;
        s2^=tmp;

        for(int i=0;i<=2000;i++)
        {
            if(s1[i])
            {
                result[0].push_back(i-1000);
            }
            if(s2[i])
            {
                result[1].push_back(i-1000);
            }
        }
        return result;
        
    }
};
#include "bits/stdc++.h"
using namespace std;

class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        int n1=nums1.size();
        int n2=nums2.size();
        int ans[1001]={0};
        vector<int>result;

        for(int i=0;i<n1;i++)
        {
            if(ans[nums1[i]]==0)
            {
                ans[nums1[i]]=1;
            }
        }
        for(int i=0;i<n2;i++)
        {
            if(ans[nums2[i]]==1)
            {
               ans[nums2[i]]=2;
            }
        }

        for(int i=0;i<1001;i++)
        {
            if(ans[i]==2)
            {
                result.push_back(i);
            }
        }
        return result;
    }
};
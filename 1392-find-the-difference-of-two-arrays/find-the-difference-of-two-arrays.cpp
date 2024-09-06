#include "bits/stdc++.h"
using namespace std;

class Solution {
public:
    vector<vector<int>> findDifference(vector<int>& nums1, vector<int>& nums2) {
        vector<vector<int>> result(2);
        int n1=nums1.size();
        int n2=nums2.size();
        unordered_set<int> s1,s2;

        for(int i=0;i<n1;i++)
        {
            s1.insert(nums1[i]);
        }

        for(int i=0;i<n2;i++)
        {
            s2.insert(nums2[i]);
            s1.erase(nums2[i]);
        }
        for(int i=0;i<n1;i++)
        {
            s2.erase(nums1[i]);
        }

        for(int x:s1)
        {
            result[0].push_back(x);
        }
        for(int x:s2)
        {
            result[1].push_back(x);
        }

        return result;

    }
};
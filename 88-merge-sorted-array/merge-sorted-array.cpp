#include "bits/stdc++.h"
using namespace std;

class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int k=m+n;
        m--;
        n--;

        for(int i=k-1;i>=0;i--)
        {
            if(m<0)
            {
                nums1[i]=nums2[n--];
            }
            else if(n<0)
            {
                nums1[i]=nums1[m--];
            }
            else if(nums2[n]>nums1[m])
            {
                nums1[i]=nums2[n--];
            }
            else
            {
                 nums1[i]=nums1[m--];
            }

        }
        
    }
};
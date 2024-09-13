#include "bits/stdc++.h"
using namespace std;
class Solution {
public:
    static bool cmp(vector<int> &a,vector<int> &b)
    {
        return a[1]<b[1];
    }
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        sort(intervals.begin(),intervals.end(),cmp);

        int n=intervals.size();
        int end=intervals[0][1];
        int count=1;

        for(int i=1;i<n;i++)
        {
            if(intervals[i][0]>=end)
            {
                end=intervals[i][1];
                count++;
            }
        }

        return n-count;
        
    }

};
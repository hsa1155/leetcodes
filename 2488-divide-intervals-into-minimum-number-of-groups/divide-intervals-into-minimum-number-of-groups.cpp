#include "bits/stdc++.h"
using namespace std;

class Solution {
public:
    int minGroups(vector<vector<int>>& intervals) {
        int n=intervals.size();
        int maxi=0;
        int ans=0;
        int current=0;

        for(const vector<int> &interval:intervals)
        {
            maxi=max(maxi,interval[1]);
        }
        vector<int> starts(maxi+1,0);
        vector<int> ends(maxi+1,0);

        for(const vector<int> &interval:intervals)
        {
            starts[interval[0]]++;
            ends[interval[1]]--;
        }

        for(int i=0;i<=maxi;i++)
        {
            current+=starts[i];
            ans=max(ans,current);
            current+=ends[i];
        }

        return ans;


        
    }
};
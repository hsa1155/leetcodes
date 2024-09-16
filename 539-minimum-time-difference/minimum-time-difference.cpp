#include "bits/stdc++.h"
using namespace std;


class Solution {
public:
    int findMinDifference(vector<string>& timePoints) {
        int len=timePoints.size();


        vector<int> mn(len);
        for(int i=0;i<len;i++)
        {
            mn[i]=translate(timePoints[i]);
        }
        sort(mn.begin(),mn.end());
        int mindiff=mn[0]+1440-mn[len-1];

        for(int i=0;i<len-1;i++)
        {
            mindiff=min(mindiff,mn[i+1]-mn[i]);
        }

        return mindiff;

        
    }
    int translate(string &hr)
    {
        return stoi(hr.substr(0,2))*60+stoi(hr.substr(3,2));
    }
};
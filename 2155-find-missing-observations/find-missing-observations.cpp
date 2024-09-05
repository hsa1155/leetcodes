#include "bits/stdc++.h"
using namespace std;

class Solution {
public:
    vector<int> missingRolls(vector<int>& rolls, int mean, int n) {
        int m=rolls.size();
        int sum=0;
        for(int i=0;i<m;i++)
        {
            sum+=rolls[i];
        }
        int require=mean*(n+m);
        int diff=require-sum;
        if(diff<n||diff>6*n)
        {
            return {};
        }
        vector<int> result(n);
        int avg=diff/n;
        int remain=diff%n;
        for(int i=0;i<n;i++)
        {
            result[i]=avg;
            if(remain>0)
            {
                result[i]+=min(6-avg,remain);
                remain-=min(6-avg,remain);
            }
        }


        return result;


    }
};
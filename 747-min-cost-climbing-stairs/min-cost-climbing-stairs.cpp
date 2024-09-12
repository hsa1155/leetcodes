#include "bits/stdc++.h"
using namespace std;

class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        int prev2=0;
        int prev1=0;
        int n=cost.size();
        int current=0;

        for(int i=2;i<=n;i++)
        {
            current=min(prev2+cost[i-2],prev1+cost[i-1]);
            prev2=prev1;
            prev1=current;
        }
        return current;
        
    }
};
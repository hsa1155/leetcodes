#include "bits/stdc++.h"
using namespace std;


class Solution {
public:
    int largestAltitude(vector<int>& gain) {
        int sum=0;
        int highest=0;
        for(int x:gain)
        {
            sum+=x;
            highest=max(highest,sum);
        }
        return highest;
        
    }
};
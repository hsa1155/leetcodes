#include "bits/stdc++.h"
using namespace std;

class Solution {
public:
    long long minimumSteps(string s) {
        long long ans=0,zero=0;
        int n=s.length();
        for(int i=n-1;i>=0;i--)
        {
            if(s[i]=='0')
            {
                zero++;
            }
            else
            {
                ans+=zero;
            }
        }
        return ans;
        
    }
};
#include "bits/stdc++.h"
using namespace std;

class Solution {
public:
    int finalValueAfterOperations(vector<string>& operations) {
        int n=operations.size();
        int ans=0;
        for(int i=0;i<n;i++)
        {
            if(operations[i][0]=='+'||operations[i][2]=='+')
            {
                ans++;
            }
            else
            {
                ans--;
            }

        }
        return ans;
        
    }
};
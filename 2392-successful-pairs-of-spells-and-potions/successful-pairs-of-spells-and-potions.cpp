#include "bits/stdc++.h"
using namespace std;

class Solution {
public:
    vector<int> successfulPairs(vector<int>& spells, vector<int>& potions, long long success) {
        
        sort(potions.begin(),potions.end());
        int n=spells.size();
        int m=potions.size();

        vector<int> result;

        for(int i=0;i<n;i++)
        {
            long long req=success/spells[i];
            if(success%spells[i]!=0)
            {
                req++;
            }
            auto it=lower_bound(potions.begin(),potions.end(),req);
            result.push_back(m-(it-potions.begin()));
        }
        return result;
    }
};
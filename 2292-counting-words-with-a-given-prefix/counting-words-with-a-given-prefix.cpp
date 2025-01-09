#include "bits/stdc++.h"
using namespace std;
class Solution {
public:
    int prefixCount(vector<string>& words, string pref) {
        int ans=0;
        int len=pref.size();

        for(auto word:words)
        {
            if(pref==word.substr(0,len))
            {
                ans++;
            }
        }

        return ans;
        
    }
};
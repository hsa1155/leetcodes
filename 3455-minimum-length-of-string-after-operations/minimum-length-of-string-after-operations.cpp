#include "bits/stdc++.h"
using namespace std;
class Solution {
public:
    int minimumLength(string s) {
        vector<int> frequent(26,0);
        int ans=0;

        for(char &ch:s)
        {
            frequent[ch-'a']++;
        }

        for(int &x:frequent)
        {
            if(x%2==1)
            {
                ans+=1;
            }
            else if(x>0)
            {
                ans+=2;
            }
        }

        return ans;
        
    }
};
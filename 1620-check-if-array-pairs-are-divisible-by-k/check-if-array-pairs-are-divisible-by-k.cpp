#include "bits/stdc++.h"
using namespace std;

class Solution {
public:
    bool canArrange(vector<int>& arr, int k) {
        map<int,int> mp;

        for(int &x:arr)
        {
            mp[(x % k + k) % k]++;
        }

        for(pair<const int,int> &pr:mp)
        {
            if(pr.first==0)
            {
                 if(pr.second%2!=0)
                 {
                    return false;
                 }
            }
            else
            {
                if(mp[k-pr.first]!=pr.second)
                {
                    return false;
                }
            }
        }
        return true;
        
    }
};
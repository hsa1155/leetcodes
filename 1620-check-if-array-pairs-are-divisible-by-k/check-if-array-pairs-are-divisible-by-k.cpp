#include "bits/stdc++.h"
using namespace std;

class Solution {
public:
    bool canArrange(vector<int>& arr, int k) {
        int n=arr.size();
        map<int,int> mp;


        for(int x:arr)
        {
            mp[(x % k + k) % k]++;
        }

        for(pair<int,int> pr:mp)
        {
            cout<<pr.first<<" "<<pr.second<<endl;
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
#include "bits/stdc++.h"
using namespace std;

class Solution {
public:
    long long minDamage(int power, vector<int>& damage, vector<int>& health) {
        
        int n=damage.size();
        vector<int> hits(n,0);
        vector<pair<double,int>> reduct(n);
        long long ans=0;
        long long dps=0;

        for(int i=0;i<n;i++)
        {
            hits[i]=ceil((double)health[i]/(double)power);
            reduct[i].first=double(damage[i])/double(hits[i]);
            reduct[i].second=i;
            dps+=damage[i];
        }
        sort(reduct.begin(),reduct.end());
        
        for(int i=n-1;i>=0;i--)
        {
            ans+=dps*hits[reduct[i].second];
            dps-=damage[reduct[i].second];
        }
        return ans;
        
    }
};
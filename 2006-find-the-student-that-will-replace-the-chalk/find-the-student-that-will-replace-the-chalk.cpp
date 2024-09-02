#include "bits/stdc++.h"
using namespace std;

class Solution {
public:
    int chalkReplacer(vector<int>& chalk, int k) {
        int n=chalk.size();
        long long int sum=0;
        vector<long long int> subsum(n,0);
        subsum[0]=chalk[0];
        for(int i=0;i<n;i++)
        {
            sum+=chalk[i];
            if(i!=0)
            {
                subsum[i]=subsum[i-1]+chalk[i];
            }
        }
        long long int chalkLeft=k%sum;
        cout<<chalkLeft<<endl;
        auto it=upper_bound(subsum.begin(),subsum.end(),chalkLeft);

        cout<<(it-subsum.begin())<<endl;

        return it-subsum.begin();
        
    }
};
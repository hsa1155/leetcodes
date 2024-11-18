#include "bits/stdc++.h"
using namespace std;
class Solution {
public:
    vector<int> decrypt(vector<int>& code, int k) {
        int n=code.size();
        vector<int> ans(n,0);

        if(k==0)
        {
            return ans;
        }

        int left,right;

        if(k>0)
        {
            left=1;
            right=k;
        }
        else if(k<0)
        {
            right=n-1;
            left=n+k;
        }
        int current=0;

        for(int i=left;i<=right;i++)
        {
            current+=code[i];
        }

        ans[0]=current;

        for(int i=1;i<n;i++)
        {
            current-=code[left];
            left++;
            right++;
            left%=n;
            right%=n;
            current+=code[right];

            ans[i]=current;
        }

        return ans;


        
    }
};
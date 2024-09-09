#include "bits/stdc++.h"
using namespace std;

class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {
        int n=nums.size();
        vector<int> prefix(n,0);
        vector<int> sufffix(n,0); 
        prefix[0]=nums[0];
        sufffix[n-1]=nums[n-1];
        int maximum=INT_MIN;

        for(int i=1;i<n;i++)
        {
            prefix[i]=prefix[i-1]+nums[i];
        }
        for(int i=n-2;i>=0;i--)
        {
            sufffix[i]=sufffix[i+1]+nums[i];
        }
        double ans;

        //for(int i=0 ;i<n;i++)
        //{
        //    cout<<prefix[i]<<" ";
        //}
        //cout<<endl;
        //for(int i=0;i<n;i++)
        //{
        //    cout<<sufffix[i]<<" ";
        //}

        if(k==n)
        {
            ans=(double)sufffix[0]/(double)k;
        }
        else
        {
            for(int i=0;i<n-k;i++)
            {
                maximum=max(maximum,sufffix[i]-sufffix[i+k]);
            }
            for(int i=n-1;i>=k;i--)
            {
                 maximum=max(maximum,prefix[i]-prefix[i-k]);
            }

            ans=(double)maximum/(double)k;
        }

        return ans;
    }
};
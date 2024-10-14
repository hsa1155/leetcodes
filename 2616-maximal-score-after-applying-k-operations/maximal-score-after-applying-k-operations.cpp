#include "bits/stdc++.h"
using namespace std;

class Solution {
public:
    long long maxKelements(vector<int>& nums, int k) {
        long long ans=0;
        priority_queue<int> pq;
        for(int x:nums)
        {
            pq.push(x);
        }

        for(int i=0;i<k;i++)
        {
            cout<<pq.top()<<endl;
            ans+=pq.top();
            int tmp=ceil((double)pq.top()/3.0);
            pq.pop();
            pq.push(tmp);
        }
        return ans;
        
    }
};
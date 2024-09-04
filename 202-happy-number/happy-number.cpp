#include "bits/stdc++.h"
using namespace std;

class Solution {
public:
    bool isHappy(int n) {
        unordered_set<long long int> happy;
        long long int sum=getSum(n);

        while (1)
        {
            if(sum==1)
            {
                return true;
            }
            else if(happy.insert(sum).second==false)
            {
                //in a loop
                return false;
            }
            else
            {
                sum=getSum(sum);
            }
        }
        
        
    }

    long long int getSum(long long int n)
    {
        long long int sum=0;
        while (n>0)
        {
            sum+=(n%10)*(n%10);
            n/=10;
        }

        return sum;
    }
};
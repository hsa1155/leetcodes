#include "bits/stdc++.h"
using namespace std;

class Solution {
public:
    int getLucky(string s, int k) {
        int n=s.length();
        string nums;
        for(int i=0;i<n;i++)
        {
            int tmp;
            tmp=int(s[i]-'a'+1);
            nums.append(to_string(tmp));
        }


        return CalDigits(nums,k-1);
        
    }

    int CalDigits(string s,int k)
    {
        int n=s.length();
        int sum=0;
        if(n==1)
        {
            return s[0]-'0';
        }
        for(int i=0;i<n;i++)
        {
            sum+=s[i]-'0';
        }

        if(k==0)
        {
            return sum;
        }
        return CalDigits(to_string(sum),k-1);
        
    }
};
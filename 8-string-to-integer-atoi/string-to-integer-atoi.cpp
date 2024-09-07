#include "bits/stdc++.h"
using namespace std;


class Solution {
public:
    int myAtoi(string s) {
        int len=s.length();
        int start=0;
        int sign=0;

        for(int i=0;i<len;i++)
        {
            if(s[i]==' ')
            {
                continue;
            }
            else
            {
                start=i;
                break;
            }
        }

        if(s[start]=='-')
        {
            sign=-1;
            start++;
        }
        else if(s[start]=='+')
        {
            sign=1;
            start++;
        }
        else
        {
            sign=1;
        }
        int numLength=0;

        for(int i=start;i<len;i++)
        {
            if(!isdigit(s[i]))
            {
                break;
            }
            else 
            {
                numLength++;
            }
        }
        for(int i=start;i<len;i++)
        {
            if(s[i]=='0')
            {
                start++;
                numLength--;
            }
            else
            {
                break;
            }
        }
        if(numLength>=18)
        {
            if(sign==1)
            {
                return INT_MAX;
            }
            else
            {
                return INT_MIN;
            }
        }
        long long int ans=0;

        for(int i=start;i<start+numLength;i++)
        {
            ans*=10;
            ans+=(int)(s[i]-'0');
        }
        ans*=sign;

        if(ans>=INT_MAX)
        {
            return INT_MAX;
        }
        else if(ans<=INT_MIN)
        {
            return INT_MIN;
        }
        else
        {
            return (int)ans;

        }


    }
};
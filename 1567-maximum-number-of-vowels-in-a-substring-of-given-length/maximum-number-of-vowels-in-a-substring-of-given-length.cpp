#include "bits/stdc++.h"
using namespace std;

class Solution {
public:
    int maxVowels(string s, int k) {
        int slow=0;
        int count=0;
        int maxcount=0;
        int n=s.length();

        for(int i=0;i<k;i++)
        {
            if(isvowel(s[i]))
            {
                count++;
            }
        }

        maxcount=count;
        for(int i=k;i<n;i++)
        {
            if(isvowel(s[i]))
            {
                count++;
            }
            if(isvowel(s[i-k]))
            {
                count--;
            }

            maxcount=max(maxcount,count);
        }

        return maxcount;
        
    }
    bool isvowel(char c)
    {
        if(c=='a'||c=='e'||c=='i'||c=='o'||c=='u')
        {
            return true;
        }
        else
        {
            return false;
        }
    }
};
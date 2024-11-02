#include "bits/stdc++.h"
using namespace std;

class Solution {
public:
    bool isCircularSentence(string s) {
        int len=s.size();
        if(len<=1)
        {
            return true;
        }
        if(s[0]!=s[len-1])
        {
            return false;
        }

        for(int i=1;i<len-1;i++)
        {
            if(s[i]==' ')
            {
                if(s[i-1]!=s[i+1])
                {
                    return false;
                }
            }
        }

        return true;
    }
};
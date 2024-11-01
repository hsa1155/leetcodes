#include "bits/stdc++.h"
using namespace std;

class Solution {
public:
    string makeFancyString(string s) {
        int len=s.length();
        if(len<=2)
        {
            return s;
        }
        string ans="";
        ans+=s[0];
        for(int i=1;i<len-1;i++)
        {
            if(s[i]!=s[i-1]||s[i]!=s[i+1])
            {
                ans+=s[i];
            }
        }
        ans+=s[len-1];
        return ans;
        
    }
};
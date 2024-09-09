#include "bits/stdc++.h"
using namespace std;

class Solution {
public:
    string removeStars(string s) {
        stack<char> str;
        int len=s.length();

        for(int i=0;i<len;i++)
        {
            if(s[i]!='*')
            {
                str.push(s[i]);
            }
            else
            {
                str.pop();
            }
        }
        string ans;
        while (!str.empty())
        {
            ans+=str.top();
            str.pop();
        }
        reverse(ans.begin(),ans.end());
        return ans;
        
        
    }
};
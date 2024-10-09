#include "bits/stdc++.h"
using namespace std;

class Solution {
public:
    int minAddToMakeValid(string s) {
        int left=0;
        int right=0;
        for(const char &c:s)
        {
            if(c=='(')
            {
                left++;
            }else
            {
                if(left>0)
                {
                    left--;
                }
                else
                {
                    right++;
                }
            }   
        }
        return right+left;
        
    }
};
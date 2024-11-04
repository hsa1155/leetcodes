#include "bits/stdc++.h"
using namespace std;

class Solution {
public:
    string compressedString(string word) {
        char current='1';
        int count=0;
        string ans="";
        for(char ch:word)
        {
            if(ch!=current||count==9)
            {
                if(current!='1')
                {
                    ans+=to_string(count);
                    ans+=current;
                }
                current=ch;
                count=1;
            }
            else if(current==ch)
            {
                count++;
            }
        }
        ans+=to_string(count);
        ans+=current;

        return ans;
        
    }
};
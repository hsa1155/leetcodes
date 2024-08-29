#include "bits/stdc++.h"
using namespace std;
class Solution {
public:
    string reverseWords(string s) {
        s.insert(0," ");
        s.append(" ");
        int len=s.length();
        string ans;
        int startIndex=len-1;
        int endIndex=len-1;
        bool isword=false;
        int words=0;

        for(int i=len-1;i>=0;i--)
        {
            if(s[i]==' ')
            {
                if(!isword)
                {
                    continue;
                }
                if(isword)
                {
                    if(words!=0)
                    {
                        ans.append(" ");
                    }
                    words++;
                    ans.append(s.substr(startIndex,endIndex-startIndex+1));
                    isword=false;

                }
            }
            else
            {
                if(isword==false)
                {
                    endIndex=i;
                    startIndex=i;
                    isword=true;
                }
                else
                {
                    startIndex=i;
                }
            }
        }


        return ans;
        
    }
};
#include "bits/stdc++.h"
using namespace std;


class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        int index=0;
        char current=strs[0][0];

        while (1)
        {
            bool isprefix=true;
            if(index>=strs[0].length())
            {
                break;
            }
            else
            {
                current=strs[0][index];
            }
            for(string &str:strs)
            {
                if(index>=str.length())
                {
                    isprefix=false;
                    break;
                }
                else if(str[index]==current)
                {

                    continue;
                }
                else
                { 
                    isprefix=false;
                    break;
                }
            }

            if(isprefix)
            {
                index++;
            }
            else
            {
                break;
            }
        }
        return strs[0].substr(0,index);
        





        
    }
};
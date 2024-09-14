#include "bits/stdc++.h"
using namespace std;

class Solution {
public:
    int compress(vector<char>& chars) {
        int index=0;
        int n=chars.size();
        int count=0;
        char current=chars[0];
        chars.push_back('/0');

        for(int i=0;i<=n;i++)
        {
            if(chars[i]!=current)
            {
                chars[index++]=current;
                if(count>1)
                {
                    string num=to_string(count);
                    for(char ch:num)
                    {
                        chars[index++]=ch;
                    }
                }

                count=1;
                current=chars[i];
            }
            else
            {
                count++;
            }
        }

        return index;



        
        
    }
};
#include "bits/stdc++.h"
using namespace std;

class Solution {
public:
    vector<string> commonChars(vector<string>& words) {
        int len=words.size();
        int ans[26];
        vector<string> result;
        for(int i=0;i<26;i++)
        {
            ans[i]=0;
        }


            int length=words[0].length();
            for(int i=0;i<length;i++)
            {
                ans[words[0][i]-'a']++;
            }
        

        for(int i=1;i<len;i++)
        {
            int length=words[i].length();
            int tmp[26]={0};
            for(int j=0;j<length;j++)
            {
                tmp[words[i][j]-'a']++;
            }

            for(int j=0;j<26;j++)
            {
                ans[j]=min(ans[j],tmp[j]);
            }
        }

        for(int i=0;i<26;i++)
        {
            string tmp{((char)(i+(int)'a'))};
            for(int j=0;j<ans[i];j++)
            {
                result.push_back(tmp);
            }
        }
        return result;
    }
};
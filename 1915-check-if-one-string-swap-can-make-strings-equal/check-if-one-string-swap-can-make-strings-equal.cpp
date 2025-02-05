#include "bits/stdc++.h"
using namespace std;
class Solution {
public:
    bool areAlmostEqual(string s1, string s2) {
        int diff=0;
        int len1=s1.length();
        int len2=s2.length();
        vector<int> count1(26,0);
        vector<int> count2(26,0);

        if(len1!=len2)
        {
            return false;
        }

        for(int i=0;i<len1;i++)
        {
            count1[s1[i]-'a']++;
            count2[s2[i]-'a']++;
            if(s1[i]!=s2[i])
            {
                diff++;
            }
            if(diff>2)
            {
                break;
            }
        }

        if(diff==0||diff==2)
        {
            for(int i=0;i<26;i++)
            {
                if(count1[i]!=count2[i])
                {
                    return false;
                }
            }
            return true;
        }
        else
        {
            return false;
        }


        
    }
};
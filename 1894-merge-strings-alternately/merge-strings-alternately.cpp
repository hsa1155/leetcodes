#include "bits/stdc++.h"
using namespace std;


class Solution {
public:
    string mergeAlternately(string word1, string word2) {
        int len1=word1.length();
        int len2=word2.length();
        int minLength=min(len1,len2);
        string result="";
        int i=0;
        int j=0;

        while (i<len1||j<len2)
        {
            if(i<len1)
            {
                result+=word1[i];
                i++;
            }
            if(j<len2)
            {
                result+=word2[j];
                j++;
            }
        }

        return result;
        

        
        
    }
};
#include "bits/stdc++.h"
using namespace std;


class Solution {
public:
    bool closeStrings(string word1, string word2) {
        int frequency1[26]={0};
        int frequency2[26]={0};
        int n=word1.length();
        unordered_map<int,int> mp1,mp2;
        
        if(n!=word2.length())
        {
            return false;
        }

        for(int i=0;i<n;i++)
        {
            frequency1[word1[i]-'a']++;
            frequency2[word2[i]-'a']++;

        }
        for(int i=0;i<26;i++)
        {
            if(frequency1[i]==0&&frequency2[i]!=0)
            {
                return false;
            }
            if(frequency1[i]!=0&&frequency2[i]==0)
            {
                return false;
            }

        }
        for(int i=0;i<26;i++)
        {
            mp1[frequency1[i]]++;
            mp1[frequency2[i]]--;
        }
        for(pair<int,int>pr:mp1)
        {
            if(pr.second!=0)
            {
                return false;
            }
        }
        return true;

        
    }
};
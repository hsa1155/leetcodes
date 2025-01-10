#include "bits/stdc++.h"
using namespace std;
class Solution {
public:
    vector<string> wordSubsets(vector<string>& words1, vector<string>& words2) {
        unordered_map<char,int> mp;
        vector<string> ans;
        for(auto &word:words2)
        {
            vector<int> tmp(26,0);
            for (char &ch:word)
            {
                tmp[ch-'a']++;
            }
            
            for(int i=0;i<26;i++)
            {
                mp['a'+i]=max(mp['a'+i],tmp[i]);
            }
        }
        
        for(auto &word:words1)
        {
            bool is_universal=true;
            vector<int> tmp(26,0);
            for (char &ch:word)
            {
                tmp[ch-'a']++;
            }

            for(int i=0;i<26;i++)
            {
                if(mp['a'+i]>tmp[i])
                {
                    is_universal=false;
                    break;
                }
            }

            if(is_universal)
            {
                ans.push_back(word);
            }


        }

        return ans;
    }
};
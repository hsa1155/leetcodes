#include "bits/stdc++.h"
using namespace std;

class Solution {
public:
    int countConsistentStrings(string allowed, vector<string>& words) {
        
        vector<int> hash_allowed(26,0);
        for(auto x:allowed)
        {
            hash_allowed[x-'a']=1;
        }
        int count=0;

        for(string word:words)
        {
            bool flag=true;
            for(char ch:word)
            {
                
                if(!hash_allowed[ch-'a'])
                {
                    flag=false;
                }
            }
             if(flag)
                {
                    count++;
                    
                }
                
        }
        return count;
    }
};
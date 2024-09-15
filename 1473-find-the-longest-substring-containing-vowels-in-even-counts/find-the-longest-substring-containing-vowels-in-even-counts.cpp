#include "bits/stdc++.h"
using namespace std;

class Solution {
public:
    int findTheLongestSubstring(string s) {
        vector<int> bitmask(26,0);
        bitmask['a'-'a']=1<<0;
        bitmask['e'-'a']=1<<1;
        bitmask['i'-'a']=1<<2;
        bitmask['o'-'a']=1<<3;
        bitmask['u'-'a']=1<<4;
        unordered_map<int,int> lastSeen;//first=xorvalue second=index
        lastSeen[0]=-1;
        int len=s.length();
        int xorvalue=0;
        int longest=0;

        for(int i=0;i<len;i++)
        {

            xorvalue^=bitmask[s[i]-'a'];
            int current;

            if(xorvalue==0)
            {
                current=i+1;
            }
            else if(lastSeen.count(xorvalue)==0)
            {
                lastSeen[xorvalue]=i;
                current=0;
            }
            else
            {
                current=i-lastSeen[xorvalue];
            }
            
            longest=max(longest,current);
        }

        return longest;

        
    }
};
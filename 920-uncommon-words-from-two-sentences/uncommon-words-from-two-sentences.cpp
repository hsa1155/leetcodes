#include "bits/stdc++.h"
using namespace std;


class Solution {
public:
    vector<string> uncommonFromSentences(string s1, string s2) {
        int index=0;
        map<string,int> mp;
        s1.append(" ");
        s2.append(" ");
        int n1=s1.length();
        int n2=s2.length();
        int count=0;
        vector<string> result;

        for(int i=0;i<n1;i++)
        {
            if(s1[i]==' ')
            {
                mp[s1.substr(index,count)]++;
                index=i+1;
                count=0;
            }
            else
            {
                count++;
            }
        }
        index=0;
        count=0;
        for(int i=0;i<n2;i++)
        {
            if(s2[i]==' ')
            {
                mp[s2.substr(index,count)]++;
                index=i+1;
                count=0;
            }
            else
            {
                count++;
            }
        }

        for(pair<string,int> pr:mp)
        {
            if(pr.second==1)
            {
                result.push_back(pr.first);
            }
        }

        return result;

        
    }
};
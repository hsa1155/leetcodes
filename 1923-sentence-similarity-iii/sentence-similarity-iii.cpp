#include "bits/stdc++.h"
using namespace std;

class Solution {
public:
    bool areSentencesSimilar(string sentence1, string sentence2) {
        vector<string> words1;
        vector<string> words2;

        stringstream ss(sentence1);
        string tmp;
        while (ss>>tmp)
        {
            words1.push_back(tmp);
        }
        ss.str("");
        ss.clear();

        ss.str(sentence2);

        while (ss>>tmp)
        {
            words2.push_back(tmp);
        }

        if(words1.size()>words2.size())
        {
            //assume words1 is small one
            swap(words1,words2);
        }
        int n=words1.size();
        int m=words2.size();

        int goback=0;

        for(int i=0;i<n;i++)
        {
            if(goback==0&&words1[i]!=words2[i])
            {
                goback=1;
            }
            if(goback==1&&words1[i]!=words2[m-(n-i)])
            {
                return false;
            }

        }



        return true;


        
    }
};
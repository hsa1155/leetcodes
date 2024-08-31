#include "bits/stdc++.h"
using namespace std;


class Solution {
public:
    string stringHash(string s, int k) {
        int n=s.length();
        string result;

        for(int i=0;i<n;i+=k)
        {
            cout<<i<<endl;
            string sub=s.substr(i,k);
            int sum=0;
            for(int j=0;j<k;j++)
            {
                sum+=sub[j]-'a';
                sum%=26;
            }
            string tmp{(char)(sum+'a')};
            result.append(tmp);
        }
        cout<<result<<endl;

        return result;
        
    }
};
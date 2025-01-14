#include "bits/stdc++.h"
using namespace std;
class Solution {
public:
    vector<int> findThePrefixCommonArray(vector<int>& A, vector<int>& B) {
        bitset<50> a,b;
        int len=A.size();
        vector<int> ans(len,0);
        for(int i=0;i<len;i++)
        {
            a[A[i]-1]=1;
            b[B[i]-1]=1;

            ans[i]=(a & b).count();

        }

        return ans;
        
    }
};
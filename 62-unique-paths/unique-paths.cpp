#include "bits/stdc++.h"
using namespace std;

class Solution {
public:
    int uniquePaths(int m, int n) {
        if(m==1||n==1)
        {
            return 1;
        }
        vector<int> row(m,1);

        for(int i=1;i<n;i++)
        {
            for(int j=1;j<m;j++)
            {
                row[j]=row[j-1]+row[j];
            }
        }
        return row[m-1];
        
    }
};
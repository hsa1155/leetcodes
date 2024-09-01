#include "bits/stdc++.h"
using namespace std;

class Solution {
public:
    vector<vector<int>> construct2DArray(vector<int>& original, int m, int n) {
        int len=original.size();
        if (m*n!=len)
        {
            return {};
        }
        int counter=0;
        vector<vector<int>> result(m,vector<int>(n,-1));
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                result[i][j]=original[counter++];
            }
        }
        return result;
    }
};
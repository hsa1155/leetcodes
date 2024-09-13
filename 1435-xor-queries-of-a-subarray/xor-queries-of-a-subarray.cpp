#include "bits/stdc++.h"
using namespace std;

class Solution {
public:
    vector<int> xorQueries(vector<int>& arr, vector<vector<int>>& queries) {
        int xorsum=0;
        int n=arr.size();
        vector<int> xorfix(n);
        vector<int> result;

        for(int i=0;i<n;i++)
        {
            xorsum^=arr[i];
            xorfix[i]=xorsum;
        }


        for(vector<int> query:queries)
        {
            if(query[0]==0)
            {
                result.push_back(xorfix[query[1]]);
            }
            else
            {
                result.push_back(xorfix[query[1]]^xorfix[query[0]-1]);
            }

        }



        return result;
        
    }
};
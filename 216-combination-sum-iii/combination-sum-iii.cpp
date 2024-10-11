#include "bits/stdc++.h"
using namespace std;
class Solution {
public:
    vector<vector<int>> combinationSum3(int k, int n) {
         vector<vector<int>> ans;
         vector<int> current;
         getCombine(ans,current,1,k,n);

         return ans;
        
    }

    void getCombine(vector<vector<int>> &ans,vector<int> current,int i,int k,int n)
    {
        if(i==9)
        {
            if(current.size()==k)
            {
                int sum=0;
                for(int x:current)
                {
                    sum+=x;
                }
                if(sum==n)
                {
                    ans.push_back(current);
                }
            }
            current.push_back(9);
             if(current.size()==k)
            {
                int sum=0;
                for(int x:current)
                {
                    sum+=x;
                }
                if(sum==n)
                {
                    ans.push_back(current);
                }
            }

        }
        else
        {
            getCombine(ans,current,i+1,k,n);
            current.push_back(i);
             getCombine(ans,current,i+1,k,n);
        }
    }
};
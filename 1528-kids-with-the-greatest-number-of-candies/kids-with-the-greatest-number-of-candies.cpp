#include "bits/stdc++.h"
using namespace std;


class Solution {
public:
    vector<bool> kidsWithCandies(vector<int>& candies, int extraCandies) {
        int n=candies.size();
        vector<bool> result(n);
        int greatest=0;

        for(int i=0;i<n;i++)
        {
            greatest=max(greatest,candies[i]);
        }

        for(int i=0;i<n;i++)
        {
            if(candies[i]+extraCandies>=greatest)
            {
                result[i]=true;
            }
            else
            {
                result[i]=false;
            }
        }
        return result;
        
    }
};
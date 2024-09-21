#include "bits/stdc++.h"
using namespace std;


class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> result;
        vector<int> tmp;
        subset(nums,0,result,tmp);

        return result;

        
    }
    void subset(vector<int>& nums,int index, vector<vector<int>> &result,vector<int> tmp)
    {

        if(index==nums.size())
        {
            result.push_back(tmp);
            return;
        }

        subset(nums,index+1,result,tmp);

        tmp.push_back(nums[index]);

        subset(nums,index+1,result,tmp);

        




    }


};
#include "bits/stdc++.h"
using namespace std;

class Solution
{
public:
    vector<int> productExceptSelf(vector<int> &nums)
    {
        int n = nums.size();
        vector<int> result(n, 1);
        int suffix = 1;
        int prefix = 1;

        for (int i = 1; i < n - 1; i++)
        {
            prefix *= nums[i - 1];
            result[i] = prefix;
        }

        prefix *= nums[n - 2];
        result[n - 1] = prefix;

        for (int i = n - 2; i >= 0; i--)
        {
            suffix *= nums[i + 1];
            result[i] = suffix * result[i];
        }



        return result;
    }
};
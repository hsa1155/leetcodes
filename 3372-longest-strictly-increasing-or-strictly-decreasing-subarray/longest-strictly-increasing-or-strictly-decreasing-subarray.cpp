#include "bits/stdc++.h"
using namespace std;
class Solution
{
public:
    int longestMonotonicSubarray(vector<int> &nums)
    {
        int n = nums.size();
        if (n == 1)
        {
            return true;
        }
        int current = nums[0];
        int inc = 1;
        int dec = 1;
        int ans = 1;
        for (int i = 1; i < n; i++)
        {
            if (nums[i] > current)
            {
                inc++;
                dec = 1;
                ans = max(ans, inc);
                current = nums[i];
            }
            else if (nums[i] == current)
            {
                inc = 1;
                dec = 1;
                ans = max(ans, inc);
                current = nums[i];
            }
            else
            {
                inc = 1;
                dec++;
                ans = max(ans, dec);
                current = nums[i];
            }
        }

        return ans;
    }
};
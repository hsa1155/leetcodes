#include "bits/stdc++.h"
using namespace std;
class Solution
{
public:
    bool check(vector<int> &nums)
    {
        bool rotate = false;
        int n = nums.size();
        if (n == 1)
        {
            return true;
        }

        for (int i = 1; i < n; i++)
        {
            if (!rotate && nums[i] < nums[i - 1])
            {
                rotate = true;
            }
            else if (rotate && nums[i] < nums[i - 1])
            {
                return false;
            }
        }

        if (nums[0] < nums[n - 1]&&rotate)
        {
            return false;
        }

        return true;
    }
};
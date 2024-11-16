#include "bits/stdc++.h"
using namespace std;
class Solution
{
public:
    vector<int> resultsArray(vector<int> &nums, int k)
    {
        int n = nums.size();
        vector<int> ans(n - k + 1, -1);
        int count = 0;
        int current = 0;
        vector<int> windows(n, 0);
        windows[0] = 1;

        for (int i = 1; i < n; i++)
        {
            if (nums[i] != nums[i - 1] + 1)
            {
                windows[i] = 1;
            }
        }
        for (int i = 0; i < k; i++)
        {
            current+=windows[i];
        }
        if (current == 1)
        {
            ans[count] = nums[k - 1];
        }
        count++;

        for (int i = k; i < n; i++)
        {

            current-=windows[i-k];
            current+=windows[i];
            if (current == 1&&windows[i-k+1]==1)
            {
                ans[count] = nums[i];
            }
            else if(current==0)
            {
                ans[count] = nums[i];
            }

            count++;
        }
        return ans;
    }
};
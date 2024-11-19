#include "bits/stdc++.h"
using namespace std;
class Solution
{
public:
    long long maximumSubarraySum(vector<int> &nums, int k)
    {
        int n = nums.size();
        long long int ans = 0;
        long long int current = 0;
        unordered_map<int, int> mp;
        bool flag = true;
        queue<int> duplicate;

        int left = 0;

        for (int i = 0; i < k; i++)
        {
            current += nums[i];
            mp[nums[i]]++;
            if (mp[nums[i]] == 2)
            {
                flag = false;
                duplicate.push(nums[i]);
            }
        }

        if (flag)
        {
            ans = current;
        }

        for (int i = k; i < n; i++)
        {
            current -= nums[left];
            mp[nums[left]]--;

            if (mp[nums[left]] == 1)
            {
                if (duplicate.front() != nums[left])
                {
                    cout << "queue bugs! " << duplicate.front() << " " << nums[left] << endl;
                }
                duplicate.pop();
                if (duplicate.empty())
                {
                    flag = true;
                }
            }
            left++;

            current += nums[i];
            mp[nums[i]]++;
            if (mp[nums[i]] == 2)
            {
                flag = false;
                duplicate.push(nums[i]);
            }

            if (flag)
            {
                ans = max(ans,current);
            }
        }

        return ans;
    }
};
#include "bits/stdc++.h"
using namespace std;
class Solution {
    public:
        string findDifferentBinaryString(vector<string>& nums) {
            sort(nums.begin(),nums.end());

            int n=nums.size();

            for(int i=0;i<n;i++)
            {
                if(stoi(nums[i],nullptr,2)!=i)
                {
                    string ans = bitset<16>(i).to_string();
                    return ans.substr(16-n);
                }
            }
            return  bitset<16>(n).to_string().substr(16-n);
            
        }
    };
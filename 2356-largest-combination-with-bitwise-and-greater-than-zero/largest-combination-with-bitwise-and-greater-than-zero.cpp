#include "bits/stdc++.h"
using namespace std;
class Solution {
public:
    int largestCombination(vector<int>& candidates) {
        vector<int> bits(32,0);
        for(int num:candidates)
        {
            add_bits(num,bits);
        }
        int ans=0;

        for(int bit:bits)
        {
            ans=max(ans,bit);
        }

        return ans;
        
    }

    void add_bits(int num,vector<int> &bits)
    {
        int current=0;
        while (num!=0)
        {
            if(num%2)
            {
                bits[current]++;
            }
            current++;
            num/=2;
        }   

    }
};
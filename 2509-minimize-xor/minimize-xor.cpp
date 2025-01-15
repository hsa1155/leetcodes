#include "bits/stdc++.h"
using namespace std;
class Solution {
public:
    int minimizeXor(int num1, int num2) {
        int num1_bits=__builtin_popcount(num1);
        int num2_bits=__builtin_popcount(num2);
        int ans=0;

        if(num1_bits>=num2_bits)
        {
            for(int i=0;i<num2_bits;i++)
            {
                ans|= 1<<(31 - __builtin_clz(num1));
                num1^=1<<(31 - __builtin_clz(num1));
            }

        }
        else
        {
            ans=num1;
            for(int i=0;i<num2_bits-num1_bits;i++)
            {
                ans+=(~ans & (ans + 1));
            }
        }

        return ans;
        
    }
};
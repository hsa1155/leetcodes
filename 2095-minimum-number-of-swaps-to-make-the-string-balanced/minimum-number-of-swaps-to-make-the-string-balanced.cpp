#include "bits/stdc++.h"
using namespace std;

class Solution {
public:
    int minSwaps(string s) {
        int ans=0;
        int left=0;
        int right=0;
        int n=s.length();
        int last=n-1;
        int current=0;

        while (current<last)
        {
            if(s[current]=='[')
            {
                left++;
            }
            else
            {
                right++;
            }

            if(right>left)
            {
                ans++;
                while (s[last]!='[')
                {
                    last--;
                }
                swap(s[current],s[last]);
                right--;
                left++;
            }
            

            current++;
        }
        cout<<s<<endl;
        return ans;
        
        
        
    }
};
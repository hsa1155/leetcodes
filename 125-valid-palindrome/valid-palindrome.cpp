#include "bits/stdc++.h"
using namespace std;

class Solution {
public:
    bool isPalindrome(string s) {
        int n=s.length();
        int left=0;
        int right=n-1;
        while (left<right)
        {
            if(!isalpha(s[left])&&!isdigit(s[left]))
            {
                left++;
            }
            else if(!isalpha(s[right])&&!isdigit(s[right]))
            {
                right--;
            }
            else if(tolower(s[left])!=tolower(s[right]))
            {
                return false;
            }
            else
            {
                left++;
                right--;
            }
            
        }

        return true;
        
        
    }
};
#include "bits/stdc++.h"
using namespace std;
class Solution {
public:
    string reverseVowels(string s) {
        int len=s.length();
        int left=0;
        int right=len-1;

        while (left<=right)
        {
            if(!isVowel(s[left]))
            {
                left++;
                continue;
            }
            else if(!isVowel(s[right]))
            {
                right--;
                continue;
            }

            swap(s[left],s[right]);
            left++;
            right--;
        }

        return s;
        
        
    }
    bool isVowel(char c)
    {
        if(c=='a'||c=='e'||c=='i'||c=='o'||c=='u'||c=='A'||c=='E'||c=='I'||c=='O'||c=='U')
        {
            return true;
        }
        else
        {
            return false;
        }
    }
};
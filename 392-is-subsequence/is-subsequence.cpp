#include "bits/stdc++.h"
using namespace std;
class Solution
{
public:
    bool isSubsequence(string s, string t)
    {
        int len1 = s.length();
        int len2 = t.length();
        int count = 0;
        if(len1==0)
        {
            return true;
        }
        for (int i = 0; i < len2; i++)
        {

            if (s[count] == t[i])
            {
                count++;
                if (count == len1)
                {
                    return true;
                }
            }
        }
        return false;
    }
};
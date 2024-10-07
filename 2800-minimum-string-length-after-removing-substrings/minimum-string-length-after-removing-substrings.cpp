#include "bits/stdc++.h"
using namespace std;

class Solution
{
public:
    int minLength(string s)
    {
        while (1)
        {
            auto it = s.find("AB");
            if (it != s.npos)
            {
                s.replace(it, 2, "");
                continue;
            }
            else
            {
                it = s.find("CD");
                if (it != s.npos)
                {
                    s.replace(it, 2, "");
                    continue;
                }
            }

            break;
        }

        return s.length();
    }
};
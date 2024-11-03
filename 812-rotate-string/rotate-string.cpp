#include "bits/stdc++.h"
using namespace std;

class Solution {
public:
    bool rotateString(string s, string goal) {
                if(goal.length()<s.length())
        {
            return false;
        }
        s+=s;

        if(s.find(goal)!=s.npos)
        {
            return true;
        }
        else
        {
            return false;
        }
        
    }
};
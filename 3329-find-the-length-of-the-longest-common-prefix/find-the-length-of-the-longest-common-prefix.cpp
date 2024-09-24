#include "bits/stdc++.h"
using namespace std;
class Solution {
public:
    int longestCommonPrefix(vector<int>& arr1, vector<int>& arr2) {
        unordered_set<int> st1,st2;
        int maximun=0;

        for(int &x:arr1)
        {
            while (x>0)
            {
                st1.insert(x);
                x/=10;
            }   
        }
        for(int &x:arr2)
        {
            while (x>0)
            {
                st2.insert(x);
                x/=10;
            }   
        }

        for(int x:st1)
        {
            if(st2.count(x)==1)
            {
                maximun=max(maximun,x);
            }
        }

        int count=0;
        while (maximun>0)
        {
            maximun/=10;
            count++;
        }

        return count;
        
        
    }
};
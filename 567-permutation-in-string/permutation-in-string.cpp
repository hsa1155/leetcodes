#include "bits/stdc++.h"
using namespace std;

class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        int arr[26];//array of num of letters in s1
        int brr[26];//array of num of letters in s2 sliding window size=n
        int n=s1.length();
        int m=s2.length();
        if(m<n)
        {
            return false;
        }
        for(int i=0;i<26;i++)
        {
            arr[i]=0;
            brr[i]=0;
        }

        for(char &c:s1)
        {
            arr[c-'a']++;
        }

        for(int i=0;i<n;i++)
        {
            brr[s2[i]-'a']++;
        }

        if(checkEqual(arr,brr))
        {
            return true;
        }

        for (int i = n; i < m; i++)
        {
            brr[s2[i] - 'a']++;
            brr[s2[i - n] - 'a']--;
            if (checkEqual(arr, brr))
            {
                return true;
            }
        }

        return false;

    }

    bool checkEqual(int arr[],int brr[])
    {
        for(int i=0;i<26;i++)
        {
            if(arr[i]!=brr[i])
            {
                return false;
            }
        }
        return true;
    }
};
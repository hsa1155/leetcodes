#include "bits/stdc++.h"
using namespace std;

class Solution {
public:
    string largestNumber(vector<int>& nums) {
        int n=nums.size();
        vector<string> strs(n);
        string result="";

        for(int i=0;i<n;i++)
        {
            strs[i]=to_string(nums[i]);
        }
        for(int i=0;i<n;i++)
        {
            cout<<strs[i]<<" ";
        }
        cout<<endl;

        sort(strs.begin(),strs.end(),cmp);
        for(int i=0;i<n;i++)
        {
            result.append(strs[i]);
        }
        if(result[0]!='0')
        {
            return result;
        }
        else
        {
            return "0";
        }

        
    }

    static bool cmp(const string &a,const string &b)
    {
        //int indexa=0;
        //int indexb=0;
        //if(a==b)
        //{
        //    return true;
        //}
        //while (indexa<a.length()&&indexb<b.length())
        //{
        //    
        //    if(a[indexa]==b[indexb])
        //    {
        //        indexa++;
        //        indexb++;
        //        indexa%=a.length();
        //        indexb%=b.length();
        //    }
        //    else 
        //    {
        //        return a[indexa]>b[indexb];
        //    }
        //}
//
        //return a>b;
        return a+b>b+a;
        
    }
};
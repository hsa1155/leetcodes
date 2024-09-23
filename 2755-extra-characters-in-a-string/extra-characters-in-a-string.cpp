#include "bits/stdc++.h"
using namespace std;


#include "bits/stdc++.h"
using namespace std;


class Solution {
public:
    int minExtraChar(string s, vector<string>& dictionary) {
        int n=dictionary.size();
        vector<pair<int,int>> overlaps;//1=start 2=end;
        int ans=s.size();

        for(int i=0;i<n;i++)
        {
            int cur=0;
            int len=dictionary[i].length();
            while ((cur=s.find(dictionary[i],cur))!=s.npos)
            {
                overlaps.push_back({cur,cur+len-1});
                cur+=len;
            }
            
        }

        if(overlaps.size()==0)
        {
            return ans;
        }

        sort(overlaps.begin(),overlaps.end());

        vector<int> dp;

        for(int i=0;i<overlaps.size();i++)
        {
            int prevInt=0;
            int currentInt=overlaps[i].second-overlaps[i].first+1;
            for(int j=0;j<i;j++)
            {
                //for all intervals before i,find maximum intervals that is not overlap with i
                if(overlaps[j].second<overlaps[i].first)
                {
                    prevInt=max(prevInt,dp[j]);
                }
            }

            dp.push_back(currentInt+prevInt);
        }

        int maxInterval=0;

        for(auto x:dp)
        {
            maxInterval=max(maxInterval,x);
        }
        return ans-maxInterval;

        //int ends=0;
        //int ans=s.length();
//
        //for(pair<int,int> &x:overlaps)
        //{
        //    cout<<x.first<<" "<<x.second<<endl;
        //    if(x.first>=ends)
        //    {
        //        ends=x.first+(x.second+1-x.first);
        //        cout<<"end"<<ends<<endl;
        //        ans-=x.second+1;
        //        ans+=x.first;
        //    }
        //}
//
        //return ans;
//



        
    }
    static bool cmp(pair<int,int> &a,pair<int,int> &b)
    {
        if(a.first==b.first)
        {
            return a.second>b.second;
        }
        else
        {
            return a.first<b.first ;
        }
    }
};
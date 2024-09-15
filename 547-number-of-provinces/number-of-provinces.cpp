#include "bits/stdc++.h"
using namespace std;


class Solution {
public:
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n=isConnected.size();
        vector<int> un(n);
        for(int i=0;i<n;i++)
        {
            un[i]=i;
        }

        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(isConnected[i][j]==1)
                {
                    int parenti=find(un,i);
                    int parentj=find(un,j);
                    if(parenti!=parentj)
                    {
                        join(un,parenti,parentj);
                    }
                }
            }
        }
        int count=0;
        for(int i=0;i<n;i++)
        {
            if(un[i]==i)
            {
                count++;
            }

        }
        return count;
        
    };
    int find(vector<int> &un,int index)
    {
        while (un[index]!=index)
        {
            index=un[index];
        }
        return index;
    };
    void join(vector<int> &un,int parenti,int parentj)
    {
        un[parentj]=parenti;
    }
    
};
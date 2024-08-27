#include"bits/stdc++.h"
using namespace std;

class Solution {
public:
    double maxProbability(int n, vector<vector<int>>& edges, vector<double>& succProb, int start_node, int end_node) {
        vector<double> dis(n,DBL_MIN);
        
        dis[start_node]=1;
        int edgesCount=edges.size();


        for(int i=0;i<n-1;i++)
        {
            bool updated=false;
            for(int j=0;j<edgesCount;j++)
            {
                int start=edges[j][0];
                int end=edges[j][1];

                if(dis[end]<dis[start]*succProb[j])
                {
                    dis[end]=dis[start]*succProb[j];
                    updated=true;

                }
                if(dis[start]<dis[end]*succProb[j])
                {
                    dis[start]=dis[end]*succProb[j];
                    updated=true;

                }
            }
                if(updated==false) 
                {
                    break;
                }
        }

        if(dis[end_node]<=0)
        {
            return 0;
        }
        else
        {
            return dis[end_node];
        }
    }
};
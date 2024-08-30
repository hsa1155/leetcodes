#include "bits/stdc++.h"
using namespace std;
class Solution {
public:
    vector<vector<int>> modifiedGraphEdges(int n, vector<vector<int>>& edges, int source, int destination, int target) {
        
        long long currentDis=dijkstra(n,edges,source,destination);

        if(currentDis<target)
        {
            return {};
        }

        bool matches=(currentDis==target);



        //for each edge ==-1 adjust it to 1 then dijkstra
        //if new distance <= target then set this edge to match target and others be 2e9
        for(auto &edge:edges)
        {
            if(edge[2]!=-1)
            {
                continue;
            }

            if(matches)
            {
                edge[2]=2e9;
            }
            else
            {
                edge[2]=1;
                long long newDis=dijkstra(n,edges,source,destination);
                if(newDis<=target)
                {
                    edge[2]+=(target-newDis);
                    matches=true;
                }
            }
        }
        if(matches==false)
        {
            return {};
        }


        return edges;
    }


    long long dijkstra(int n, vector<vector<int>>& edges, int source, int destination)
    {
        vector<bool> visited(n,false);

        //[which node][connection of node][0=connect to 1=weight] O(n)
        vector<vector< vector <long long>>> connected(n,vector<vector<long long>>());
        vector<long long> distance(n,2e9);

        distance[source]=0;

        //for each non-1 edge add it to connected O(edges*n)
        for(auto edge:edges)
        {
            if(edge[2]==-1)
            {
                continue;
            }
            else
            {
                connected[edge[0]].push_back(vector<long long>({edge[1],edge[2]}));
                connected[edge[1]].push_back(vector<long long>({edge[0],edge[2]}));
            }
        }
    /*
        for(int i=0;i<n;i++)
        {
            int connection=connected[i].size();
            for(int j=0;j<connection;j++)
            {
                cout<<connected[i][j][0]<<" "<<connected[i][j][1]<<endl;
            }
        }

        */
        //O(n*(n+n))
        for(int i=0;i<n;i++)
        {
            //find nearest;
            int near=-1;
            for(int j=0;j<n;j++)
            {
                //if not visited&&smaller than current min
                if(!visited[j]&&( near==-1||distance[j]<distance[near]))
                {
                    near=j;

                }
            }
            if(near==-1)
            {
                //no more nodes
                break;
            }

            //find nearested and goto it;
            visited[near]=true;

            //for each connection of near update distance
            for(auto connection:connected[near])
            {
                distance[connection[0]]=min(distance[connection[0]],distance[near]+connection[1]);
            }
            


        }

        return distance[destination];
    }

    long long min(long long a,long long b)
    {
        if(a<b)
        {
            return a;
        }
        else
        {
            return b;
        }
    }
};
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


    long long dijkstra(int n, vector<vector<int>>& edges, int source, int destination) {
        vector<long long> distance(n, LLONG_MAX);
        vector<bool> visited(n, false);
        vector<vector<pair<int, long long>>> connected(n);

        for (auto& edge : edges) {
            if (edge[2] == -1) continue;
            connected[edge[0]].push_back({edge[1], edge[2]});
            connected[edge[1]].push_back({edge[0], edge[2]});
        }

        priority_queue<pair<long long, int>, vector<pair<long long, int>>, greater<>> pq;
        pq.push({0, source});
        distance[source] = 0;

        while (!pq.empty()) {
            auto [dist, u] = pq.top();
            pq.pop();

            if (visited[u]) continue;
            visited[u] = true;

            for (auto& [v, weight] : connected[u]) {
                if (distance[u] + weight < distance[v]) {
                    distance[v] = distance[u] + weight;
                    pq.push({distance[v], v});
                }
            }
        }

        return distance[destination] == LLONG_MAX ? 2e9 : distance[destination];
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
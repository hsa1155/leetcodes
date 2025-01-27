#include "bits/stdc++.h"
using namespace std;
class Solution
{
public:
    vector<bool> checkIfPrerequisite(int n, vector<vector<int>> &prerequisites, vector<vector<int>> &queries)
    {
        vector<bool> ans;
        vector<vector<int>> graph(n);
        vector<vector<bool>> request(n, vector<bool>(n, false));


        for (auto &link : prerequisites)
        {
            graph[link[0]].push_back(link[1]);
        }

        for(int i=0;i<n;i++)
        {
            vector<bool> visited(n, false);
            visited[i]=true;
            queue<int> bfs;
            for(int &x:graph[i])
            {
                bfs.push(x);
            }

            while (!bfs.empty())
            {
                int current=bfs.front();
                bfs.pop();
                if(visited[current])
                {
                    continue;
                }
                else
                {
                    visited[current]=true;
                    request[i][current]=true;
                }

                for (int &x : graph[current])
                {
                    if(!visited[x])
                    {
                        bfs.push(x);
                    }
                }
            }
        }

        for(auto &qurey:queries)
        {
            if(request[qurey[0]][qurey[1]])
            {
                ans.push_back(true);
            }
            else
            {
                ans.push_back(false);
            }
        }


        return ans;
    }
};
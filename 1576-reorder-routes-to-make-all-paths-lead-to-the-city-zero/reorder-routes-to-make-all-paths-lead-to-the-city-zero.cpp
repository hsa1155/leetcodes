#include "bits/stdc++.h"
using namespace std;

class Solution {
public:
    int minReorder(int n, vector<vector<int>>& connections) {
        vector<vector<int>> nodes(n+1);
        vector<int> visited(n+1,0);
        visited[1]=1;

        for(const vector<int>&conn:connections)
        {
            nodes[conn[0]+1].push_back(conn[1]+1);
            nodes[conn[1]+1].push_back(-(conn[0]+1));
        }
        stack<int> st;
        int ans=0;

        for(const int &node:nodes[1])
        {
            st.push(node);
        }

        while (!st.empty())
        {
            int tmp=st.top();
            st.pop();
            if(tmp<0)
            {
                tmp*=-1;
            }
            else
            {
                ans++;
            }

            visited[tmp]=1;

            for (const int &node : nodes[tmp])
            {
                if(visited[abs(node)]==0)
                {
                    st.push(node);
                }
            }
        }
        


        return ans;
        
    }
};
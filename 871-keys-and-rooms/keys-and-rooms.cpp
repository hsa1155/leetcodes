#include "bits/stdc++.h"
using namespace std;

class Solution {
public:
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        int n=rooms.size();
        vector<int> visited(n,0);
        queue<int> keys;
        bool result=true;

        for(int x:rooms[0])
        {
            keys.push(x);
        }
        visited[0]=1;

        while (!keys.empty())
        {
            if(visited[keys.front()]==1)
            {
                keys.pop();
                continue;
            }
            else
            {
                visited[keys.front()]=1;
                for(int x:rooms[keys.front()])
                {
                    keys.push(x);
                }
                keys.pop();
            }
        }

        for(int x:visited)
        {
            if(x!=1)
            {
                return false;
            }
        }
        return result;
        
        
    }
};
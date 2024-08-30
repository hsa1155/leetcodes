class Solution {
    int getMinimumDistance(int n, vector<vector<int>> &edges, int source, int destination){
        vector<vector<pair<int, int>>> adj(n);
        for(vector<int> &edge: edges){
            int a = edge[0];
            int b = edge[1];
            int w = edge[2];

            if(w != -1){
                adj[a].push_back({b, w});
                adj[b].push_back({a, w});
            }
        }

        vector<int> minimumDistance(n, INT_MAX);
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        
        minimumDistance[source] = 0;
        pq.push({minimumDistance[source], source});

        while(!pq.empty()){
            int node, nodeDistance;
            tie(nodeDistance, node) = pq.top();
            pq.pop();

            if(nodeDistance != minimumDistance[node]){
                continue;
            }

            for(auto edge: adj[node]){
                int neighbour, weight;
                tie(neighbour, weight) = edge;
                if(minimumDistance[neighbour] > minimumDistance[node] + weight){
                    minimumDistance[neighbour] = minimumDistance[node] + weight;
                    pq.push({minimumDistance[neighbour], neighbour});
                }
            }
        }

        return minimumDistance[destination];
    }
    const int MAX_EDGE_WEIGHT = 2e9;
    vector<vector<int>> fill(vector<vector<int>> &edges){
        for(vector<int> &edge: edges){
            if(edge[2] == -1){
                edge[2] = MAX_EDGE_WEIGHT;
            }
        }
        return edges;
    }
public:
    vector<vector<int>> modifiedGraphEdges(int n, vector<vector<int>>& edges, int source, int destination, int target) {
        int distance = getMinimumDistance(n, edges, source, destination);
        if(distance < target){
            return vector<vector<int>>();
        }
        else if(distance == target){
            return fill(edges);
        }

        for(vector<int> &edge: edges){
            if(edge[2] == -1){
                edge[2] = 1;
                int distance = getMinimumDistance(n, edges, source, destination);
                if(distance == target){
                    return fill(edges);
                }
                else if(distance < target){
                    edge[2] += target - distance;
                    return fill(edges);
                }
            }
        }
        return vector<vector<int>>();
    }
};
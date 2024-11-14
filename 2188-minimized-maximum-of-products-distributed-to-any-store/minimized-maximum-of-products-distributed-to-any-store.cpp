#include "bits/stdc++.h"
using namespace std;
class Solution
{
public:
    int minimizedMaximum(int n, vector<int> &quantities)
    {
        int m=quantities.size();
        pair<int,int> current;
        // Define a custom comparator for the priority queue
        // It sorts the pairs based on the ratio of their first to their second
        // element
        auto compareTypeStorePairs = [](pair<int, int> &a, pair<int, int> &b)
        {
            return (long long)a.first * b.second <
                   (long long)a.second * b.first;
        };

        priority_queue<pair<int,int>,vector<pair<int,int>>,decltype(compareTypeStorePairs)> pq;

        for(int &x:quantities)
        {
            pq.push({x,1});
        }

        for(int i=0;i<n-m;i++)
        {
            current=pq.top();
            pq.pop();
            current.second++;
            pq.push(current);
        }

        return ceil((double)pq.top().first/(double)pq.top().second);
    }
};

// 15 10 10 1 0 0 0
// 8 10 10 1 7 0 0
// 8 5 10 1 7 5 0
// 8 5 5 1 7 5 5
// 11 6 0
// 6 6 5
//// 8 5 5 1 7 5 5 0
//// 5 5 5 1 5 5 5 5
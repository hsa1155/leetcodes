#include "bits/stdc++.h"
using namespace std;
class Solution {
public:
    int findChampion(int n, vector<vector<int>>& edges) {
        vector<int> strong(n, 0);

        for (vector<int> &edge : edges) {
            strong[edge[1]]++;
        }

        int ans=-1;
        for (int i = 0; i < n; i++) {

            if (strong[i] == 0) {
                if(ans!=-1)
                {
                    return -1;
                }
                ans=i;
            }
        }

        // If more than one champion, return -1 else return the team number.
        return ans;
    }
};
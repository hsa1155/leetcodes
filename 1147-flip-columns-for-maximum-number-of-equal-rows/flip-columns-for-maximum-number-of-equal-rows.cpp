#include "bits/stdc++.h"
using namespace std;
class Solution
{
public:
    int maxEqualRowsAfterFlips(vector<vector<int>> &matrix)
    {
        bitset<300> tmp;
        bitset<300> current;
        bitset<300> mask;
        bitset<300> zero;
        vector<pair<bitset<300>, int>> patterns;
        int n = matrix[0].size();
        for (int i = 0; i < n; i++)
        {
            mask[i] = 1;
        }
        int ans = 0;

        for (vector<int> &row : matrix)
        {
            for (int i = 0; i < n; i++)
            {
                current[i] = row[i];
            }

            bool flag = true;
            for (pair<bitset<300>, int> &pattern : patterns)
            {
                // if (current ^ pattern.first == zero ||  current ^ pattern.first == mask)
                // {
                //     flag = false;
                //     pattern.second++;
                //     break;
                // }

                tmp = current ^ pattern.first;
                int x=tmp.count() ;
                if (x== n || x== 0)
                {
                    flag = false;
                    pattern.second++;
                    break;
                }
            }
            if (flag)
            {
                patterns.push_back({current, 1});
            }
        }

        for (pair<bitset<300>, int> &pattern : patterns)
        {
            ans = max(ans, pattern.second);
        }
        return ans;
    }
};
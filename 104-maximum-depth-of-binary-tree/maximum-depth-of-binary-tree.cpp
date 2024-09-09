#include "bits/stdc++.h"
using namespace std;


class Solution {
public:
    int maxDepth(TreeNode* root) {
         return dfs(root);
        
    }

    int dfs(TreeNode* current)
    {
        if(current==nullptr)
        {
            return 0;
        }
        else
        {
            return max(dfs(current->left)+1,dfs(current->right)+1);
        }
    }
};
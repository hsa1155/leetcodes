#include "bits/stdc++.h"
using namespace std;




class Solution {
public:
    int goodNodes(TreeNode* root) {

        return dfs(root,INT_MIN);
        
    }

    int dfs(TreeNode* current,int maximum)
    {
        if(!current)
        {
            return 0;
        }
        maximum=max(maximum,current->val);
        
        int left=0;
        int right=0;

        if(current->left)
        {
            left=dfs(current->left,maximum);
        }
        if(current->right)
        {
            right=dfs(current->right,maximum);
        }

        if(current->val>=maximum)
        {
            return 1+left+right;
        }
        else
        {
            return left+right;
        }

    }
};
#include "bits/stdc++.h"
using namespace std;




class Solution {
public:
    vector<int> rightSideView(TreeNode* root) {
        vector<int> ans;
        if(root==nullptr)
        {
            return {};
        }
        queue<pair<int,TreeNode*>> treeQueue;
        treeQueue.push({0,root});
        int level=0;

        while (!treeQueue.empty())
        {
            if(treeQueue.front().second->right)
            {
                treeQueue.push({treeQueue.front().first+1,treeQueue.front().second->right});
            }

            if(treeQueue.front().second->left)
            {
                treeQueue.push({treeQueue.front().first+1,treeQueue.front().second->left});
            }

            if(level==treeQueue.front().first)
            {
                ans.push_back(treeQueue.front().second->val);
                level++;
            }
            treeQueue.pop();
        }
        return ans;
        
        
    }
};
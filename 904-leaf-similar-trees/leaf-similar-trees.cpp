#include "bits/stdc++.h"
using namespace std;



class Solution {
public:
    bool leafSimilar(TreeNode* root1, TreeNode* root2) {
        vector<int> leaf1,leaf2;
        bfs(root1,leaf1);
        bfs(root2,leaf2);
        int n=leaf1.size();
        int m=leaf2.size();
        if(n!=m)
        {
            return false;
        }
        else
        {
            for(int i=0;i<n;i++)
            {
                if(leaf1[i]!=leaf2[i])
                {
                    return false;
                }
            }
            return true;
        }
        
    }

    void bfs(TreeNode* root,vector<int> &result)
    {
        stack<TreeNode*> visit;

        visit.push(root);

        while (!visit.empty())
        {
            TreeNode* current=visit.top();
            visit.pop();
            if(current->left==nullptr&&current->right==nullptr)
            {
                result.push_back(current->val);
            }
            if(current->right!=nullptr)
            {
                visit.push(current->right);
            }
            if(current->left!=nullptr)
            {
                visit.push(current->left);
            }
            
        }
        
    }
};
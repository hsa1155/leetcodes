#include "bits/stdc++.h"
using namespace std;



class Solution {
public:
    TreeNode* replaceValueInTree(TreeNode* root) {
        vector<int> levelSum;
        queue<pair<TreeNode* ,int>> qu;//treenode,level
        qu.push({root,1});

        while (!qu.empty())
        {
            TreeNode* current=qu.front().first;
            int level=qu.front().second;
            if(level>levelSum.size())
            {
                levelSum.push_back(current->val);
            }
            else
            {
                levelSum[level-1]+=current->val;
            }
            qu.pop();

            if(current->left)
            {
                qu.push({current->left,level+1});
            }
            if(current->right)
            {
                qu.push({current->right,level+1});
            }

        }

                root->val=0;
        qu.push({root,1});

        while (!qu.empty())
        {
            TreeNode* current=qu.front().first;
            int level=qu.front().second;
            qu.pop();
            int childSum=0;
            cout<<current->val<<endl;;

            if(current->left)
            {
                childSum+=current->left->val;
            }
            if(current->right)
            {
                childSum+=current->right->val;
            }

            if(current->left)
            {
                current->left->val=levelSum[level]-childSum;
            }
            if(current->right)
            {
                current->right->val=levelSum[level]-childSum;
            }

            if(current->left)
            {
                qu.push({current->left,level+1});
            }
            if(current->right)
            {
                qu.push({current->right,level+1});
            }

        }



        return root;
        
        
    }
};
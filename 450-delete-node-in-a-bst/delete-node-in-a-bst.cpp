#include "bits/stdc++.h"
using namespace std;



class Solution {
public:
    TreeNode* deleteNode(TreeNode* root, int key) {

        TreeNode* current=root;
        TreeNode* parent=nullptr;

        while (current&&current->val!=key)
        {
            if(current->val>key)
            {
                parent=current;
                current=current->left;
            }
            else
            {
                parent=current;
                current=current->right;
            }

        }

        if(current==nullptr)
        {
            return root;
        }

        //current point to key to be deleted

        if(!current->left&&!current->right)
        {
            //is leaf
            if(parent)
            {
                if(parent->left==current)
                {
                    parent->left=nullptr;
                }
                else
                {
                    parent->right=nullptr;
                }
                
            }
            else
            {
                //is root
                root=nullptr;
                
            }
            delete current;
        }
        else if(!(current->left&&current->right))
        {
            //has one side
            TreeNode* child;
            if(current->left)
            {
                child=current->left;
            }
            else
            {
                child=current->right;
            }

            if(parent)
            {
                 if(parent->left==current)
                {
                    parent->left=child;
                }
                else
                {
                    parent->right=child;
                } 
            }
            else
            {
                //is root
                root=child;
            }

            delete current;

        }
        else
        {
            //has left and right
            TreeNode* child=current->left;
            parent=current;
            while (child->right)
            {
                //find  biggest left child 
                parent=child;
                child=child->right;
            }
            //swap biggest left child to current
            //then delete it
            current->val=child->val;

            if(parent!=current)
            {
                parent->right=child->left;
            }
            if(parent==current)
            {
                current->left=child->left;
            }
            delete child;

            

        }

        

        return root;
        
    }
};
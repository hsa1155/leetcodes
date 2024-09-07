#include "bits/stdc++.h"
using namespace std;




class Solution {
public:
    bool isSubPath(ListNode* head, TreeNode* root) {
        vector<int> nodes;
        ListNode* current=head;
        while (current!=nullptr)
        {
            nodes.push_back(current->val);
            current=current->next;
        }
        int index=0;
        int n=nodes.size();
        return search(root,0,n,nodes);
        
        
    }

    bool peek(TreeNode* current,int index,int n,vector<int> nodes)
    {
        if(index==n)
        {
            return true;
        }
        else if(current==nullptr)
        {
            return false;
        }
        else
        {
            if(current->val==nodes[index])
            {
                return peek(current->left,index+1,n,nodes)||peek(current->right,index+1,n,nodes);
            }
            else
            {
                return false;
            }
        }
    }

    bool search(TreeNode* current,int index,int n,vector<int> nodes)
    {
        if(index==n)
        {
            return true;
        }
        else if(current==nullptr)
        {
            return false;
        }

        if(peek(current,0,n,nodes))
        {
            return true;
        }

        else
        {
            return search(current->left,0,n,nodes)||search(current->right,0,n,nodes);
        }
    }
};
class Solution {
public:
    TreeNode* searchBST(TreeNode* root, int val) {
        TreeNode* current=root;

        while (current)
        {
            if(val<current->val)
            {
                current=current->left;
            }
            else if(val>current->val)
            {
                current=current->right;
            }
            else
            {
                return current;
            }
        }

        return nullptr;
        
        
    }
};
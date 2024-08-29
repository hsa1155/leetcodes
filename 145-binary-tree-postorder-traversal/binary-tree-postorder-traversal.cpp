void travel(TreeNode* root,vector<int>& result)
{

    if(!root)
    {
        return;
    }

    if(root->left)
    {
        travel(root->left,result);
    }
        if(root->right)
    {
        travel(root->right,result);
    }
    result.push_back(root->val);

}


class Solution {
public:
    vector<int> postorderTraversal(TreeNode* root) {

        vector<int> result;

        travel(root, result);


       
        return result;
    }
};


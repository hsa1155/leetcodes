
class Solution {
public:
    int pathSum(TreeNode* root, int targetSum) {

        vector<long long int> parents;


        return dfs(root,targetSum,parents);
        
    }

    int dfs(TreeNode* current, int targetSum,vector<long long int> parents)
    {
        if(!current)
        {
            return 0;
        }

        int matched=0;
        parents.push_back(0);
        for(long long int &x:parents)
        {
            x+=current->val;
            if(x==targetSum)
            {
                matched++;
            }
        }
        if(current->left)
        {
            matched+=dfs(current->left,targetSum,parents);
        }
        if(current->right)
        {
            matched+=dfs(current->right,targetSum,parents);
        }

        return matched;
    }
};


class Solution {
public:
    long long kthLargestLevelSum(TreeNode* root, int k) {
        vector<long long> num;
        dfs(root,1,num);
        if(num.size()<k)
        {
            return -1;
        }

        sort(num.begin(),num.end());

        return num[num.size()-k];
        
    }

    void dfs(TreeNode* current,int level,vector<long long> &num)
    {
        if(level>num.size())
        {
            num.push_back(current->val);
        }
        else
        {
            num[level-1]+=current->val;
        }

        if(current->left)
        {
            dfs(current->left,level+1,num);
        }
        if(current->right)
        {
            dfs(current->right,level+1,num);
        }
    }
};
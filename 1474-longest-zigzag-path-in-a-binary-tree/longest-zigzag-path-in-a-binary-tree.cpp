
class Solution
{
public:
    int longestZigZag(TreeNode *root)
    {
        int ans=0;
        zigzag(root,-1,0,ans);
        return ans;

    }

    void zigzag(TreeNode *current, int direction,int path,int &ans)
    {
        ans=max(path,ans);

        if (current->right)
        {
            if (direction == 0)
            {
                zigzag(current->right, 1,path+1,ans);
            }
            else
            {
                zigzag(current->right, 1,1,ans);
            }
        }
        if (current->left)
        {
            if (direction == 1)
            {
                zigzag(current->left, 0,path+1,ans);
            }
            else
            {
                zigzag(current->left, 0,1,ans);
            }
        }

        
    }
};
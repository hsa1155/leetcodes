

class Solution {
public:
    bool flipEquiv(TreeNode* root1, TreeNode* root2) {
        queue<TreeNode*> t1,t2;
        if(root1==nullptr&&root2==nullptr)
        {
            return true;
        }
        else if(root1==nullptr||root2==nullptr)
        {
            return false;
        }
        t1.push(root1);
        t2.push(root2);

        while (!t1.empty()&&!t2.empty())
        {
            TreeNode* current1=t1.front();
            TreeNode* current2=t2.front();
            if(current1->val!=current2->val)
            {
                return false;
            }
            t1.pop();
            t2.pop();
            int left1= current1->left ? current1->left->val :-1;
            int left2= current2->left ? current2->left->val :-1;
            int right1= current1->right ? current1->right->val :-1;
            int right2= current2->right ? current2->right->val :-1;
            int tmp=0;
            tmp=tmp^left1^left2^right1^right2;
            if(tmp!=0)
            {
                cout<<current1->val<<" "<<left1<<" "<<right1<<" "<<left2<<" "<<" "<<right2<<endl;
                return false;
                //childern not equal
            }
            if(left1!=left2)
            {
                swap(current2->left,current2->right);
                //flip tree2
            }

            if(current1->left)
            {
                t1.push(current1->left);
            }
            if(current1->right)
            {
                t1.push(current1->right);
            }
            if(current2->left)
            {
                t2.push(current2->left);
            }
            if(current2->right)
            {
                t2.push(current2->right);
            }

        }

        if(t1.empty()&&t2.empty())
        {
            
        return true;

        }
        else
        {
            return false;
        }
        
    }
};
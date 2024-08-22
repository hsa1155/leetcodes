class Solution {
public:
    int lengthOfLastWord(string s) {
        int ans=0;
        int length=s.length();
        int flag=0;//0 no space 1=space
        for(int i=0;i<length;i++)
        {
            if(s[i]!=' '&&flag==0)
            {
                ans++;
            }
            else if(s[i]!=' '&&flag==1)
            {
                flag=0;
                ans=1;
            }
            else
            {
                flag=1;
            }
        }
        return ans;
        
    }
};
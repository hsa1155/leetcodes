class Solution {
public:
    int findComplement(int num) {
        int counter=0;
        int ans=0;
    while(num>0)
    {

        int rmb=num&1; //right most bit;
        if(rmb==0)
        {
            ans|=1<<counter;

        }
        num>>=1;
        counter++;
    }

    return ans;
        
    }
};
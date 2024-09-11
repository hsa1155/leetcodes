class Solution {
public:
    int minBitFlips(int start, int goal) {
        int x=start^goal;

        int num=0;
        while(x>0)
        {
            if(x%2)
            {
                num++;
            }
            x/=2;
        }
        return num;
        
    }
};
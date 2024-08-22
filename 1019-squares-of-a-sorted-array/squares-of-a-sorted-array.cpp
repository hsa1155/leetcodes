class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        int len=nums.size();
        int min_abs=0x3f3f3f3f;
        int min_index=0;
        vector<int> square;
        for(int i=0;i<len;i++)
        {
            int tmp=nums[i]*nums[i];
            if(tmp<=min_abs)
            {
                min_index=i;
                min_abs=tmp;
            }
        }
        cout<<min_abs<<" "<<min_index<<endl;

        int left=min_index-1;
        int right=min_index+1;
        square.push_back(nums[min_index] *nums[min_index]);
        while(1)
        {
            if(left<0&&right>=len)
            {
                break;
            }
            else if(left<0&&!(right>=len))
            {
                //choose right
                square.push_back(nums[right]*nums[right]);
                right++;
            }
            else if(!(left<0)&&right>=len)
            {
                //choose left
                square.push_back(nums[left]*nums[left]);
                left--;
            }
            else
            {
                //both in bound
                if(nums[left]*nums[left]<=nums[right]*nums[right])
                {
                    square.push_back(nums[left]*nums[left]);
                    left--;
                }
                else
                {
                    square.push_back(nums[right]*nums[right]);
                    right++;
                }
            }
        }
        return square;
    }
};
class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int length=nums.size();
        int counter=0;
        for(int i=0;i<length;i++)
        {
            if(nums[i]==val)
            {
                continue;
            }
            else
            {
                nums[counter]=nums[i];
                counter++;
            }
        }
        nums.resize(counter);
        return counter;

    }
};
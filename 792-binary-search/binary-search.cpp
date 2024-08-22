class Solution {
public:
    int search(vector<int>& nums, int target) {
        int length=nums.size();
        int left=0;
        int right=length-1;
        
        for(;left<=right;)
        {

            int mid=(left+right)/2;
            if(nums[mid]==target)
            {
                return mid;
            }
            else if(nums[mid]>target)
            {
                right=mid-1;
            }
            else if(nums[mid]<target)
            {
                left=mid+1;
            }
            
        }
        return -1;
        
    }
};
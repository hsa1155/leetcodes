class Solution {
public:
    int maxWidthRamp(vector<int>& nums) {
        int n = nums.size();
        stack<int> indicesStack;

        // Fill the stack with indices in decreasing order of their values
        //the new value of stack should always<= previous value in stack
        for (int i = 0; i < n; i++) {
            if (indicesStack.empty() || nums[indicesStack.top()] > nums[i]) {
                indicesStack.push(i);
            }
        }

        int maxWidth = 0;

        // Traverse the array from the end to the start
        for (int j = n - 1; j >= 0; j--) {
            while (!indicesStack.empty() &&nums[indicesStack.top()] <= nums[j]) {
                maxWidth = max(maxWidth, j - indicesStack.top());
                // Pop the index since it's already processed
                indicesStack.pop();
                if(indicesStack.empty())
            {
                return maxWidth;
            }
            }
            
        }

        return maxWidth;
    }
};
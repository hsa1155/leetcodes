# Definition for a binary tree node.
from collections import *
import math
class Solution:
    def waysToSplitArray(self, nums: list[int]) -> int:
        left,right,ans=0,0,0
        for num in nums:
            right+=num
        nums.pop()
        for num in nums:
            left+=num
            right-=num
            if left>=right:
                ans+=1
            
        
        return ans
        
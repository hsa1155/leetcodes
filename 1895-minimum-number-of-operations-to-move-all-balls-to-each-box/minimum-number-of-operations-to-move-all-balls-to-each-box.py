# Definition for a binary tree node.
from collections import *
import math
class Solution:
    def minOperations(self, boxes: str) -> list[int]:
        left=0
        right=0
        rightsum=0
        leftsum=0
        ans=[]

        for i in range(len(boxes)-1,0,-1):
            if boxes[i]=='1':
                right+=1
            rightsum+=right
        
        ans.append(rightsum)
        if boxes[0]=='1':
            left=1
            leftsum=1
        for i in range(1,len(boxes)):
            rightsum-=right
            if boxes[i]=='1':
                right-=1
            
            ans.append(rightsum+leftsum)

            if boxes[i]=='1':
                left+=1
            leftsum+=left

        return ans

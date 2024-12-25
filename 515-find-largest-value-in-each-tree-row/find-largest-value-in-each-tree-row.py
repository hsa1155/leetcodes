# Definition for a binary tree node.
from collections import *
import math
class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right
class Solution:
    def largestValues(self, root:TreeNode) -> list[int]:
        if root is None:
            return []
        stack=deque()
        stack.append(root)
        ans=[]
        while stack:
            nodes=len(stack)
            maxi=-math.inf

            for i in range(nodes):
                current=stack.popleft()
                maxi=max(maxi,current.val)
                if(current.left is not None):
                    stack.append(current.left)
                if(current.right is not None):
                    stack.append(current.right)   

            ans.append(maxi)             



        return ans
        
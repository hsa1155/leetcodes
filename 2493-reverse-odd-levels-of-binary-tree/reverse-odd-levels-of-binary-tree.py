# Definition for a binary tree node.
from collections import *
class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right
class Solution:
    def reverseOddLevels(self, root:TreeNode) -> TreeNode:
        stack=deque()
        stack.append(root)
        level=2
        while stack:
            current=stack.popleft()
            if current.left is not None:
                stack.append(current.left)
                stack.append(current.right)
            
            if(len(stack)==level):
                left, right = 0, level - 1
                level*=4
                while left < right:
                    stack[left].val,stack[right].val=stack[right].val,stack[left].val
                    left+=1
                    right-=1

        return root
        
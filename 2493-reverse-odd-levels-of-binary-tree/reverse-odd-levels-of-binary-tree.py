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
                level*=4
                reverse=stack.copy()
                while reverse:
                    reverse[0].val,reverse[-1].val=reverse[-1].val,reverse[0].val
                    reverse.pop()
                    reverse.popleft()

        return root
        
# Definition for a binary tree node.
from collections import *
import math
class Solution:
    def maxScore(self, s: str) -> int:
        ans=0
        current=0
        for i in range(1,len(s)):
            if s[i]=='1':
                current+=1
        if s[0]=='0':
            current+=1
        ans=current

        for i in range(1,len(s)-1):
            if(s[i]=='0'):
                current+=1
            else:
                current-=1
            ans=max(ans,current)
        return ans
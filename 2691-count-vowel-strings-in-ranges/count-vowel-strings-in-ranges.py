# Definition for a binary tree node.
from collections import *
import math
def isvowel(ch):
    if ch in ['a','e','i','o','u']:
        return True
    else:
        return False
class Solution:
        
    def vowelStrings(self, words: list[str], queries: list[list[int]]) -> list[int]:
        prefix=[0]*(len(words)+1)
        ans=[]
        for i in range(1,len(words)+1):
            prefix[i]=prefix[i-1]
            if isvowel(words[i-1][0]) and isvowel(words[i-1][-1]):
                prefix[i]+=1
        
        for qurey in queries:
            ans.append(prefix[qurey[1]+1]-prefix[qurey[0]])
        
        

        return ans

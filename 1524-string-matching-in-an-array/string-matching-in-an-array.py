# Definition for a binary tree node.
from collections import *
import math
class Solution:
    def stringMatching(self, words: list[str]) -> list[str]:
        ans=[]
        for current in range(len(words)):
            for other in range(len(words)):
                if current==other:
                    continue
                if words[current] in words[other]:
                    ans.append(words[current])
                    break
        
        return ans
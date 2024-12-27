# Definition for a binary tree node.
from collections import *
import math
class Solution:
    def maxScoreSightseeingPair(self, values: list[int]) -> int:
        if(len(values)==2):
            return values[0]+values[1]-1
        
        prefix=-math.inf
        ans=-math.inf
        prefix=values[0]

        for i in range(1,len(values)):
            ans=max(ans,values[i]-i+prefix)

            prefix=max(prefix,values[i]+i)
        
        return ans
        
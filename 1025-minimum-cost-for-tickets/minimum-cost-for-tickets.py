# Definition for a binary tree node.
from collections import *
import math
class Solution:
    def mincostTickets(self, days: list[int], costs: list[int]) -> int:
        last=days[len(days)-1]
        dp=[0]*(last+1)
        i=0

        for day in range(1,last+1):
            if(day<days[i]):
                dp[day]=dp[day-1]
            else:
                i+=1
                dp[day]=min(dp[day-1]+costs[0],  dp[max(0, day - 7)] + costs[1],dp[max(0, day - 30)] + costs[2])
            
        return dp[last]
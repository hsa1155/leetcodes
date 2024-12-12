import math
import heapq
class Solution:
    def pickGifts(self, gifts:list[int], k: int) -> int:
        gifts=[x*-1 for x in gifts]
        heapq.heapify(gifts)
        for i in range(k):
            tmp=heapq.heappop(gifts)
            tmp*=-1
            tmp=int(math.sqrt(tmp))
            tmp*=-1
            heapq.heappush(gifts,tmp)
        ans=0
        for gift in gifts:
            ans+=gift

        return -1*ans
        
import heapq
class Solution:
    def getFinalState(self, nums: list[int], k: int, multiplier: int) -> list[int]:
        minheap=[ [x,i] for [i,x] in enumerate(nums)]
        heapq.heapify(minheap)

        for i in range(k):
            cur=heapq.heappop(minheap)
            cur[0]*=multiplier
            nums[cur[1]]*=multiplier
            heapq.heappush(minheap,cur)
        
        return nums

        
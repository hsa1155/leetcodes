import heapq
class Solution:
    def maxAverageRatio(self, classes: List[List[int]], extraStudents: int) -> float:
        maxheap=[[-((c[0]+1)/(c[1]+1)-(c[0]/c[1])),c] for c in classes]
        
        heapq.heapify(maxheap)
        
        for i in range(extraStudents):
            c=heapq.heappop(maxheap)
            c[1][0]+=1
            c[1][1]+=1
            c[0]=-((c[1][0]+1)/(c[1][1]+1)-(c[1][0]/c[1][1]))
            heapq.heappush(maxheap,c)

        return sum(c[1][0] / c[1][1] for c in maxheap) / len(classes)
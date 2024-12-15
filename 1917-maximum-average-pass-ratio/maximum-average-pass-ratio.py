import heapq
class Solution:
    def maxAverageRatio(self, classes: list[list[int]], extraStudents: int) -> float:
        maxheap=[]
        for c in classes:
            heapq.heappush(maxheap,  [-((c[0]+1)/(c[1]+1)-(c[0]/c[1])),c] )
        
        for i in range(extraStudents):
            c=heapq.heappop(maxheap)
            c[1][0]+=1
            c[1][1]+=1
            c[0]=-((c[1][0]+1)/(c[1][1]+1)-(c[1][0]/c[1][1]))
            heapq.heappush(maxheap,c)

        total=0     
        while maxheap:
            c=heapq.heappop(maxheap)
            total+=(c[1][0]/c[1][1])
        
        total/=len(classes)


        return total
        
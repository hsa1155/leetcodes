class Solution:
    def maxTwoEvents(self, events: list[list[int]]) -> int:
        pq=[]

        events.sort(key = lambda x:(x[0],x[1]))

        print(events)

        ans=0
        current=0
        ptr_to_past=0
        past_max=0

        for i in range(len(events)):
            while pq and pq[0][0]<events[i][0]:
                past_max=max(past_max,pq[0][1])
                heapq.heappop(pq)


            current=events[i][2]+past_max

            ans=max(ans,current)

            heapq.heappush(pq, (events[i][1], events[i][2]))



        return ans
from collections import defaultdict
class Solution:
    def zero():
        return 0
    def maximumLength(self, s: str) -> int:
        ans=-1
        subs=defaultdict(Solution.zero)
        current=''
        count=0
        s+='\n'

        for ch in s:
            if(ch!=current):
                for i in range(count):
                    subs[current*(i+1)]+=count-i
                    if subs[current*(i+1)]>=3:
                        ans=max(ans,i+1)
                current=ch
                count=1
            else:
                count+=1

        return ans


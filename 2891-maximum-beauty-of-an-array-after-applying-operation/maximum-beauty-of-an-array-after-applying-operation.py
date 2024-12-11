class Solution:
    def maximumBeauty(self, nums: list[int], k: int) -> int:
        if(len(nums)==1):
            return 1
        maxi=max(*nums)
        mini=min(*nums)
        add_prefix=[0]*((maxi+k)-(mini-k)+1)
        minus_prefix=[0]*((maxi+k)-(mini-k)+1)
        mini-=k
        maxi+=k
        current=0
        ans=0
        for num in nums:
            add_prefix[num-k-mini]+=1
            minus_prefix[num+k-mini]-=1
        
        for i in range(len(add_prefix)):
            current+=add_prefix[i]
            ans=max(ans,current)
            current+=minus_prefix[i]


        return ans

class Solution:
    def findScore(self, nums: list[int]) -> int:
        mark=[0]*len(nums)
        for i in range(len(nums)):
            nums[i]=[nums[i],i]

        nums.sort()

        ans=0

        for i in range(len(nums)):
            if(mark[nums[i][1]]!=1):
                ans+=nums[i][0]
                mark[nums[i][1]]=1
                if nums[i][1]-1>=0:
                    mark[nums[i][1]-1]=1
                if nums[i][1]+1<len(nums):
                    mark[nums[i][1]+1]=1

        return ans
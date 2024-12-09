class Solution:
    def isArraySpecial(self, nums: list[int], queries: list[list[int]]) -> list[bool]:
        special=[0]*len(nums)
        for i in range(1,len(nums)):
            if(nums[i]%2!=nums[i-1]%2):
                special[i]=special[i-1]
            else:
                special[i]=special[i-1]+1
        
        result=[]
        for query in queries:
            if special[query[0]]==special[query[1]]:
                result.append(True)
            else:
                result.append(False)     

        return result         

class Solution:
    def addSpaces(self, s: str, spaces: list[int]) -> str:
        space_index=0
        spaces.append(-1)
        n=len(s)
        ans=""

        for i in range(n):
            if i==spaces[space_index]:
                ans+=' '
                space_index+=1
            ans+=s[i]
        return ans
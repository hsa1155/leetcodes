class Solution:
    def checkIfExist(self, arr: list[int]) -> bool:
        st=set()

        for i in arr:
            if 2*i in st or i/2 in st:
                return True
            st.add(i)

        return False

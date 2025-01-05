# Definition for a binary tree node.
from collections import *
import math
class Solution:
    def shiftingLetters(self, s: str, shifts: list[list[int]]) -> str:
        # 計算累積位移
        final = [0] * (len(s) + 1)
        for shift in shifts:
            if shift[2] == 1:
                final[shift[0]] += 1
                final[shift[1] + 1] -= 1
            else:
                final[shift[0]] -= 1
                final[shift[1] + 1] += 1

        result = ""
        current = 0

        for i in range(len(s)):
            current += final[i]
            # 計算新的字元
            newChar = (ord(s[i]) - ord('a') + current) % 26
            result += chr(ord('a') + newChar)

        return result
# Definition for a binary tree node.
from collections import *
import math
class Solution:
    def stringMatching(self, words: list[str]) -> list[str]:
        # 將所有字串連接成一個大字串,用特殊字元分隔
        text = ' '.join(words)
        
        # 只要檢查一個字串在大字串中出現超過1次,就代表它是某個字串的子字串
        # 但要排除它自己那一次
        return [word for word in words 
                if text.count(word) > 1]
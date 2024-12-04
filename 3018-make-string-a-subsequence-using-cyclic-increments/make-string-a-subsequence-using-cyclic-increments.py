class Solution:
    def canMakeSubsequence(self, str1: str, str2: str) -> bool:
        index = 0
        length_str2 = len(str2)

        # Traverse through both strings using a for loop
        for ch in str1:
            if index < length_str2 and (
                ch == str2[index]
                or ord(ch) + 1 == ord(str2[index])
                or ord(ch) - 25 == ord(str2[index])
            ):
                # If match found, move to next character in str2
                index += 1

        # Check if all characters in str2 were matched
        return index == length_str2
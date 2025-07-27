class Solution:
    def lengthOfLongestSubstring(self, s):
        """
        :type s: str
        :rtype: int
        """
        longestLen = 0
        chars = {}
        i = 0
        while (i < len(s)):
            char = s[i]
            if char not in chars:
                chars[char] = i
            else:
                if len(chars) > longestLen:
                    longestLen = len(chars)
                i = chars[char]
                chars.clear()
            i += 1
        if len(chars) > longestLen:
            longestLen = len(chars) 
        return longestLen

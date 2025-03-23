class Solution:
    def lengthOfLongestSubstring(self, s: str) -> int:
        res = 0
        currTable = dict()
        
        start = 0
        curr = 0
        for idx, char in enumerate(s):
            curr += 1
            if char in currTable and currTable[char] >= start:
                res = max(res, curr - 1)
                curr = idx - currTable[char] 
                start = currTable[char] + 1
                currTable[char] = idx
            else:
                res = max(res, curr)
                currTable[char] = idx

        return res
                
                
        
s = Solution()

res = s.lengthOfLongestSubstring(" ")
print(res)
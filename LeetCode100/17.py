from typing import List

class Solution:
    def firstMissingPositive(self, nums: List[int]) -> int:
        length = len(nums)
        map_num = [0] * (10000)
        
        for num in nums:
            if num > 0 and num < 10000:
                map_num[num - 1] = 1
            
        res = 1    
        for i in range(length+1):
            if map_num[i] == 0:
                res = i+1
                break
        return res
        
s = Solution()
nums = [1]

res = s.firstMissingPositive(nums)

print(res)
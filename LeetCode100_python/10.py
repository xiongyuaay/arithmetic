# 该方法只能针对nums数组全为正整数的问题
from typing import List

class Solution:
    def subarraySum(self, nums: List[int], k: int) -> int:
        start = 0
        end = 0
        curr = 0
        res = 0
        
        while end < len(nums):
            curr += nums[end]
            while curr > k:
                curr -= nums[start]
                start += 1
            if curr == k and start <= end:
                res += 1
                end += 1
            if curr < k:
                end += 1
        
        return res
    

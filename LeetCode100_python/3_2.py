from typing import List
from collections import defaultdict


class Solution:
    def longestConsecutive(self, nums: List[int]) -> int:
        nums_set = set(nums)
        res = 0
        
        for num in nums_set:
            if num - 1 in nums_set:
                next_num = num + 1
                streak = 1
                
                while next_num in nums_set:
                    next_num = next_num + 1
                    streak = streak + 1
                    
                res = max(res, streak)
                
        return res
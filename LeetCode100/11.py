from typing import List

class Solution:
    def maxSlidingWindow(self, nums: List[int], k: int) -> List[int]:
        length = len(nums)
        res = []
        curr_max = nums[0]
        
        for idx in range(k):
            curr_max = max(curr_max, nums[idx])
            
        res.append(curr_max)
        
        for idx in range(k, length):
            if nums[idx - k] == curr_max:
                curr_max = nums[idx]
                for j in range(1, k):
                    curr_max = max(curr_max, nums[idx - k + j])
            else:
                curr_max = max(curr_max, nums[idx])
            res.append(curr_max)
            
        return res
                
            
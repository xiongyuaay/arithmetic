from typing import List

class Solution:
    def rotate(self, nums: List[int], k: int) -> None:
        """
        Do not return anything, modify nums in-place instead.
        """
        length = len(nums)
        k = k % length
        
        m = length - k
        nums.extend(nums[m:] + nums[:m])
        del nums[:length]
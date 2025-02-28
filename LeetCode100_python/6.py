from typing import List

class Solution:
    def threeSum(self, nums: List[int]) -> List[List[int]]:
        nums.sort()
        length = len(nums)
        
        res = []
        
        for i in range(length - 2):
            if i > 0 and nums[i] == nums[i-1]:
                continue
            
            left = i + 1
            right = length - 1
            
            while left < right:
                total = nums[i] + nums[left] + nums[right]
                
                if total == 0:
                    res.append([nums[i], nums[left], nums[right]])
                    left += 1
                    right -= 1
                    while left < right and nums[left] == nums[left - 1]:
                        left += 1
                    while left < right and nums[right] == nums[right + 1]:
                        right -= 1
                        
                elif total < 0:
                    left += 1
                else:
                    right -= 1
        return res
                    

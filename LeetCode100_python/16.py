from typing import List

class Solution:
    def productExceptSelf(self, nums: List[int]) -> List[int]:
        length = len(nums)
        pre = [1] * length
        suffix = [1] * length
        pre[0] = 1
        suffix[length - 1] = 1
                
        for i in range(1, length):
            pre[i] = nums[i-1] * pre[i-1]
            
        for i in range(length-2, -1, -1):
            suffix[i] = nums[i+1] * suffix[i+1]
            
        res = [0] * length
        for i in range(length):
            res[i] = pre[i] * suffix[i]
            
        return res
        
s = Solution()
nums = [1, 2, 3, 4]
res = s.productExceptSelf(nums)
print(res)
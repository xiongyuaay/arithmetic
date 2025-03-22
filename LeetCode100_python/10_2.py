from typing import List
import numpy as np

class Solution:
    def subarraySum(self, nums: List[int], k: int) -> int:
        length = len(nums)
        dist = np.zeros([length, length])
        
        dist[0][0] = nums[0]
        res = 0 if dist[0][0] != k else 1
        
        for i in range(1, length):
            dist[0][i] = dist[0][i-1] + nums[i]
            if dist[0][i] == k:
                res += 1
                
        for row in range(1, length):
            for col in range(row, length):
                dist[row][col] = dist[row-1][col] - nums[row-1]
                if dist[row][col] == k:
                    res += 1
        
        return res
    
    
sol = Solution()

nums = [1, 1, 1]
k = 2
res = sol.subarraySum(nums, k)
print(res)
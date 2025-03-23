from typing import List

class Solution:
    def maxArea(self, height: List[int]) -> int:
        maxA = 0
        validHeight = 0
        
        for left in range(len(height)):
            if height[left] <= validHeight:
                continue
            
            validHeight = height[left]
            for right in range(len(height) - 1, left, -1):
                if height[right] >= height[left]:
                    maxA = max(maxA, height[left] * (right - left))
                    break
                maxA = max(maxA, height[right] * (right - left))
                
        return maxA
        
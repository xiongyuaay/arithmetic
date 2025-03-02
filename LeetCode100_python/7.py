from typing import List

class Solution:
    def trap(self, height: List[int]) -> int:
        length = len(height)

        volume = 0
        l = 0
        r = length - 1
        curr = 0

        while l < r:
            curr = max(min(height[l], height[r]), curr)
            if height[l] <= height[r]:
                volume += max(curr - height[l], 0)
                l += 1
            else:
                volume += max(curr - height[r], 0)
                r -= 1

        return volume
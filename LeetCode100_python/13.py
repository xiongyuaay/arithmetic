from typing import List

class Solution:
    def maxSubArray(self, nums: List[int]) -> int:
        pre = []
        curr = 0
        for num in nums:
            curr += num
            pre.append(curr)

        min_p = []
        mi = 0
        for p in pre:
            min_p.append(mi)
            mi = min(mi, p)
        
        ma = pre[0]
        for idx in range(len(pre)):
            ma = max(ma, pre[idx] - min_p[idx])

        return ma
        
s = Solution()
nums = [-2, -1]
res = s.maxSubArray(nums)

print(res)
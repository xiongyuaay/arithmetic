from typing import List

class Solution:
    def subarraySum(self, nums: List[int], k: int) -> int:
        pre = 0
        res = 0
        hashtable = dict()
        hashtable[0] = 1
        
        for num in nums:
            pre += num
            if pre - k in hashtable:
                res += hashtable[pre - k]
                
            if pre in hashtable:
                hashtable[pre] += 1
            else:
                hashtable[pre] = 1
        
        return res
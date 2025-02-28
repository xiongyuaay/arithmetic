from typing import List
from collections import defaultdict


class Solution:
    def longestConsecutive(self, nums: List[int]) -> int:
        hashtable = defaultdict(list)
        
        nums = set(nums)
        
        for num in nums:
            if num in hashtable:
                hashtable[num].append(num)
                hashtable[num + 1] = hashtable.pop(num)
            else:
                hashtable[num + 1].append(num)
                
        for key in hashtable:
            first = key - len(hashtable[key])
            if first in hashtable:
                hashtable[key].extend(hashtable[first])
                
        for key in hashtable:
            first = key - len(hashtable[key])
            if first in hashtable:
                hashtable[key].extend(hashtable[first])
        
        for key in hashtable:
            first = key - len(hashtable[key])
            if first in hashtable:
                hashtable[key].extend(hashtable[first])
                
        max = 0
        for li in hashtable.values():
            if len(li) > max:
                max = len(li)
                
        return max
    

ans = Solution()
nums = [4,0,-4,-2,2,5,2,0,-8,-8,-8,-8,-1,7,4,5,5,-4,6,6,-3]
res = ans.longestConsecutive(nums)
print(res)
    
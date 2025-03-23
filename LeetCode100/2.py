from typing import List
from collections import defaultdict

class Solution:
    def groupAnagrams(self, strs: List[str]) -> List[List[str]]:
        hashtable = defaultdict(list)
        for string in strs:
            key = tuple(sorted(string))
            hashtable[key].append(string)
            
        return list(hashtable.values())
import heapq

class Solution:
    def minWindow(self, s: str, t: str) -> str:
        dict_t = dict()
        
        for char in t:
            if char in dict_t:
                dict_t[char] += 1
            else:
                dict_t[char] = 1
                
        len_t = len(t)
        len_s = len(s)
        
        heap = []
        res = s + t
        
        temp_t = dict_t.copy()
        
        for idx in range(len_s):
            if s[idx] in temp_t:
                temp_t[s[idx]] -= 1
                heapq.heappush(heap, (idx, s[idx]))
                
            while all(value <= 0 for value in temp_t.values()):
                if len(res) > idx - heap[0][0] + 1:
                    res = s[heap[0][0]:(idx + 1)]
                item = heapq.heappop(heap)
                temp_t[item[1]] += 1
                
        if res == s + t:
            return ""
        else:
            return res

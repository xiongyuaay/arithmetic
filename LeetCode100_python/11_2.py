from typing import List
import heapq

class MaxHeap:
    def __init__(self):
        self.heap = []
        
    def push(self, t:tuple):
        heapq.heappush(self.heap, (-t[0], t[1]))
    
    def pop(self):
        res = heapq.heappop(self.heap)
        
        return (-res[0], res[1])
    
    def peek(self):
        return (-self.heap[0][0], self.heap[0][1]) if self.heap else None
    
        

class Solution:
    def maxSlidingWindow(self, nums: List[int], k: int) -> List[int]:
        heap = MaxHeap()
        res = []
        length = len(nums)
        
        for idx in range(k):
            heap.push((nums[idx], idx))
            
        res.append(heap.peek()[0])
        
        for idx in range(k, length):
            heap.push((nums[idx], idx))
            while heap.peek():
                num, test_idx = heap.peek()
                if test_idx <= idx - k:
                    heap.pop()
                    continue
                res.append(num)
                break
        
        return res
             

nums = [1,3,-1,-3,5,3,6,7]
k = 3
s = Solution()
res = s.maxSlidingWindow(nums, k)
print(res)
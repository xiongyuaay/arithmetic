from typing import List

def quick_sort(intervals: List[List[int]]):
    if len(intervals) <= 1:
        return intervals
    pivot = intervals[len(intervals) // 2]
    left = [[x, y] for [x, y] in intervals if x < pivot[0]]
    middle = [[x, y] for [x, y] in intervals if x == pivot[0]]
    right = [[x, y] for [x, y] in intervals if x > pivot[0]]
    return quick_sort(left) + middle + quick_sort(right)

class Solution:
    def merge(self, intervals: List[List[int]]) -> List[List[int]]:

        intervals = quick_sort(intervals)

        res = []
        while len(intervals) > 1:
            curr = intervals[0]
            if curr[1] < intervals[1][0]:
                res.append(curr)
                intervals.pop(0)
                continue

            new_end = curr[1]
            for idx in range(1, len(intervals)):
                if new_end < intervals[idx][0]:
                    res.append([curr[0], new_end])
                    intervals = intervals[idx:]
                    break
                if new_end >= intervals[idx][0]:
                    new_end = max(intervals[idx][1], new_end)
                    if idx == len(intervals) - 1:
                        res.append([curr[0], new_end])
                        intervals = []

        if len(intervals) > 0:
            res.append(intervals[0])

        return res
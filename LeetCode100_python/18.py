from typing import List

class Solution:
    def setZeroes(self, matrix: List[List[int]]) -> None:
        """
        Do not return anything, modify matrix in-place instead.
        """
        col = set()
        row = set()
        
        r = len(matrix)
        c = len(matrix[0])
        
        for i in range(r):
            for j in range(c):
                if matrix[i][j] == 0:
                    col.add(j)
                    row.add(i)
                    
        for i in  row:
            for j in range(c):
                matrix[i][j] = 0
                
        for j in col:
            for i in range(r):
                matrix[i][j] = 0        

s = Solution()
matrix = [[1,1,1],[1,0,1],[1,1,1]]
s.setZeroes(matrix)
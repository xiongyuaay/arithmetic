from typing import List

class Solution:
    def __init__(self):
        self.row = 0
        self.col = 0
        self.matrix = list()
    
    def spiralOrder(self, matrix: List[List[int]]) -> List[int]:
        direction = [1, 0]
        self.row = len(matrix)
        self.col = len(matrix[0])
        self.matrix = matrix
        
        curr = [0, 0]
        res = []
        
        while(self.term(direction, curr) or self.check(direction, curr)):
            res.append(self.matrix[curr[0]][curr[1]])
            self.matrix[curr[0]][curr[1]] = -200
            if self.check(direction, curr):
                next = self.step(direction, curr)
            else:
                direction = self.revolve(direction)
                next = self.step(direction, curr)
                
            curr = next
            
        if self.matrix[curr[0]][curr[1]] == -200:
            return res
        res.append(self.matrix[curr[0]][curr[1]])
        return res
        
        
        
    def revolve(self, direct: List[int]):
        return [-direct[1], direct[0]]
    
    def step(self, direct: List[int], pos: List[int]):
        return [pos[0] + direct[1], pos[1] + direct[0]]
    
    def term(self, cur_direct: List[int], cur_pos: List[int]):
        pos = self.step(self.revolve(cur_direct), cur_pos)
        
        if pos[0] >= self.row or pos[1] >= self.col or self.matrix[pos[0]][pos[1]] == -200:
            return False
        else:
            return True
        
    def check(self, direct: List[int], pos: List[int]):
        next = self.step(direct, pos)
        if next[0] >= self.row or next[0] < 0 or next[1] >= self.col or next[1] < 0 or self.matrix[next[0]][next[1]] == -200:
            return False
        else:
            return True
        
        
s = Solution()
matrix = [[3],[2]]
res = s.spiralOrder(matrix)
print(res)
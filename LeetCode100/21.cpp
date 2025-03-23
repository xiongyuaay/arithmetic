#include <vector>
using namespace std;

class Solution {
    public:
        bool searchMatrix(vector<vector<int>>& matrix, int target) {
            int row = matrix.size();
            int col = row > 0 ? matrix[0].size():0;

            for (int i = 0; i < row; i++)
            {
                if (matrix[i][0] > target or matrix[i][col-1] < target)
                {
                    continue;
                }
                
                for (int j = 0; j < col; j++)
                {
                    if (matrix[i][j] == target)
                    {
                        return true;
                    }
                    
                }
                
            }
            return false;
            
        }
    };
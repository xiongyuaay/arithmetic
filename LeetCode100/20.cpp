#include<vector>
#include<iostream>
using namespace std;

class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int row = matrix.size();
        int col = matrix[0].size();
        int s = 0;
        int e = 1;

        while (s < row / 2 && s < col / 2 && s <= col - e)
        {
            for (int i = s; i < col - e; i++)
            {
                int curr[2] = {s, i};
                int temp1 = matrix[curr[0]][curr[1]];
                while (true)
                {
                    int next[2] = {curr[1], col - 1 - curr[0]};
                    int temp2 = matrix[next[0]][next[1]];
                    matrix[next[0]][next[1]] = temp1;
                    temp1 = temp2;
                    curr[0] = next[0];
                    curr[1] = next[1];
                    if(next[0] == s && next[1] == i)
                    {
                        break;
                    }
                }
    
            }
            s++;
            e++;
        }
    }
};


int main()
{
    Solution s;
    vector<vector<int>> matrix = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
    s.rotate(matrix);
    for(int i = 0;i < matrix.size();i++)
    {
        for(int j = 0;j < matrix[0].size();j++)
        {
            cout<<matrix[i][j];
        }
        cout<<endl;
    }
    return 0;
}
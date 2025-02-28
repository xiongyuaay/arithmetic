/* 给定一个 8 x 8 的棋盘，只有一个 白色的车，用字符 'R' 表示。棋盘上还可能存在白色的象 'B' 以及黑色的卒 'p'。空方块用字符 '.' 表示。

车可以按水平或竖直方向（上，下，左，右）移动任意个方格直到它遇到另一个棋子或棋盘的边界。如果它能够在一次移动中移动到棋子的方格，则能够 吃掉 棋子。

注意：车不能穿过其它棋子，比如象和卒。这意味着如果有其它棋子挡住了路径，车就不能够吃掉棋子。

返回白车 攻击 范围内 兵的数量。 */
#include <vector>
#include <utility>
using namespace std;

using pos = pair<int, int>; 
class Solution 
{
public:
    int numRookCaptures(vector<vector<char>>& board) 
    {
        pos r;
        vector<pos> b;
        vector<pos> p;
        int count = 0;

        for (int i = 0; i < 8; i++)
        {
            for(int j=0;j<8;j++)
            {
                if (board[i][j] == 'R')
                {
                    r.first = i;
                    r.second = j;
                }
                if (board[i][j] == 'B')
                {
                    b.emplace_back(i, j);
                }
                if (board[i][j] == 'p')
                {
                    p.emplace_back(i, j);
                }
            }
        }
        
        for (int i = r.first - 1; i >= 0; i--)
        {
            if (board[i][r.second] == 'B')
            {
                break;
            }
            if (board[i][r.second] == 'p')
            {
                count++;
                break;
            }
        }

        for (int i = r.first + 1; i < 8; i++)
        {
            if (board[i][r.second] == 'B')
            {
                break;
            }
            if (board[i][r.second] == 'p')
            {
                count++;
                break;
            }
        }

        for (int i = r.second + 1; i < 8; i++)
        {
            if (board[r.first][i] == 'B')
            {
                break;
            }
            if (board[r.first][i] == 'p')
            {
                count++;
                break;
            }
        }
        
        for (int i = r.second - 1; i >= 0; i--)
        {
            if (board[r.first][i] == 'B')
            {
                break;
            }
            if (board[r.first][i] == 'p')
            {
                count++;
                break;
            }
        }

        return count;
    }
};
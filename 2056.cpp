/* 有一个 8 x 8 的棋盘，它包含 n 个棋子（棋子包括车，后和象三种）。给你一个长度为 n 的字符串数组 pieces ，其中 pieces[i] 表示第 i 个棋子的类型（车，后或象）。除此以外，还给你一个长度为 n 的二维整数数组 positions ，其中 positions[i] = [ri, ci] 表示第 i 个棋子现在在棋盘上的位置为 (ri, ci) ，棋盘下标从 1 开始。

棋盘上每个棋子都可以移动 至多一次 。每个棋子的移动中，首先选择移动的 方向 ，然后选择 移动的步数 ，同时你要确保移动过程中棋子不能移到棋盘以外的地方。棋子需按照以下规则移动：

车可以 水平或者竖直 从 (r, c) 沿着方向 (r+1, c)，(r-1, c)，(r, c+1) 或者 (r, c-1) 移动。
后可以 水平竖直或者斜对角 从 (r, c) 沿着方向 (r+1, c)，(r-1, c)，(r, c+1)，(r, c-1)，(r+1, c+1)，(r+1, c-1)，(r-1, c+1)，(r-1, c-1) 移动。
象可以 斜对角 从 (r, c) 沿着方向 (r+1, c+1)，(r+1, c-1)，(r-1, c+1)，(r-1, c-1) 移动。
移动组合 包含所有棋子的 移动 。每一秒，每个棋子都沿着它们选择的方向往前移动 一步 ，直到它们到达目标位置。所有棋子从时刻 0 开始移动。如果在某个时刻，两个或者更多棋子占据了同一个格子，那么这个移动组合 不有效 。

请你返回 有效 移动组合的数目 */

#include <vector>
#include <string>
using namespace std;

using Move = vector<vector<int>>;
using Combinations = vector<Move>;
using Piece_Move = vector<vector<int>>;

class Solution 
{
private:
    void init(vector<string>& pieces, vector<vector<int>>& positions, Combinations &moves)
    {
        int n = pieces.size();
        Piece_Move pmove[n];
        for (int i = 0; i < n; i++)
        {
            generate(pieces[i], pmove[i]);
        }
        
        
        

    }

    void generate(string &piece, Piece_Move &piece_mave)
    {

    }
public:
    int countCombinations(vector<string>& pieces, vector<vector<int>>& positions) 
    {
        Combinations moves;

        int count = 0;
        for (auto &move:moves)
        {
            if (check(move, positions))
            {
                count++;
            }   
        }
        return count;
    }

    bool check(Move &move, vector<vector<int>>& positions)
    {

    }
};
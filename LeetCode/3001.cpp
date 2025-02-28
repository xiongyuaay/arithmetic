/* 现有一个下标从 1 开始的 8 x 8 棋盘，上面有 3 枚棋子。

给你 6 个整数 a 、b 、c 、d 、e 和 f ，其中：

(a, b) 表示白色车的位置。
(c, d) 表示白色象的位置。
(e, f) 表示黑皇后的位置。
假定你只能移动白色棋子，返回捕获黑皇后所需的最少移动次数。

请注意：

车可以向垂直或水平方向移动任意数量的格子，但不能跳过其他棋子。
象可以沿对角线方向移动任意数量的格子，但不能跳过其他棋子。
如果车或象能移向皇后所在的格子，则认为它们可以捕获皇后。
皇后不能移动。 */
#include <cmath>
class Solution 
{
public:
    bool blockRook(int a, int b, int c, int d, int e, int f)
    {
        if (a != c && b != d)
        {
            return false;
        }
        if (a == c && a == e)
        {
            if (b < d && d < f)
            {
                return true;
            }
            if (b > d && d > f)
            {
                return true;
            }
        }
        if (b == d && b == f)
        {
            if (a < c && c < e)
            {
                return true;
            }
            if (a > c && c > e)
            {
                return true;
            }
        }
        return false;
    }

    bool blockBishop(int a, int b, int c, int d, int e, int f)
    {
        if ((((a - e) ^ (c - e)) >= 0) && (((b - f) ^ (d - f)) >= 0) && abs(a - e) == abs(b - f))
        {
            if (abs(a - e) < abs(c - e))
            {
                return true;
            }
            
        }
        return false;
    }

    int minMovesToCaptureTheQueen(int a, int b, int c, int d, int e, int f) 
    {
        bool block = blockBishop(a, b, c, d, e, f);
        if (abs(c - e) == abs(d - f) && !blockBishop(a, b, c, d, e, f))
        {
            return 1;
        }
        
        if (!blockRook(a, b, c, d, e, f))
        {
            if (a == e || b == f)
            {
                return 1;
            }
            return 2;
        }
        if ((c + d) % 2 == (e + f) % 2)
        {
            return 2;
        }
        
        return 2;
        
    }
};

int main()
{
    Solution s;
    s.minMovesToCaptureTheQueen(8, 4, 2, 8, 7, 3);
    return 0;
}
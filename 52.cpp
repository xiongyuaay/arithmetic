/* n 皇后问题 研究的是如何将 n 个皇后放置在 n × n 的棋盘上，并且使皇后彼此之间不能相互攻击。

给你一个整数 n ，返回 n 皇后问题 不同的解决方案的数量。 */
#include <vector>
#include <cmath>
using namespace std;

class Solution {
    vector<int> res;
    int num;
public:
    int DFS(int curr)
    {
        if (curr >= num)
        {
            return 1;
        }
        
        int total = 0;
        for (int i = 0; i < num; i++)
        {
            res[curr] = i;
            if (check(curr))
            {
                total += DFS(curr+1);
            }
        }

        return total;
        
    }

    bool check(int curr)
    {
        for (int i = 0; i < curr; i++)
        {
            if (res[i] == res[curr] || abs(res[curr] - res[i]) == abs(curr - i))
            {
                return false;
            }
            
        }
        return true;

    }

    int totalNQueens(int n) 
    {
        res.resize(n);
        num = n;
        int total = 0;


        total = DFS(0);
        return total;
    }
};

int main()
{
    Solution s;
    int n = 4;
    s.totalNQueens(n);
    return 0;
}
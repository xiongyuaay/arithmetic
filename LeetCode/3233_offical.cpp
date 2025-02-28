/* 给你两个 正整数 l 和 r。对于任何数字 x，x 的所有正因数（除了 x 本身）被称为 x 的 真因数。

如果一个数字恰好仅有两个 真因数，则称该数字为 特殊数字。例如：

数字 4 是 特殊数字，因为它的真因数为 1 和 2。
数字 6 不是 特殊数字，因为它的真因数为 1、2 和 3。
返回区间 [l, r] 内 不是 特殊数字 的数字数量。 */

#include <cmath>
#include <vector>
using namespace std;

class Solution {

public:
    int nonSpecialCount(int l, int r) {
        int n = sqrt(r);
        vector<int> v(n+1);
        int count = r - l + 1;
        for (int i = 2; i <= n; i++)
        {
            if (v[i] == 0)
            {
                if (i * i >= l && i * i <= r)
                {
                    count--;
                }
                
                for (int j = 2*i; j <= n; j+=i)
                {
                    v[j] = 1;
                }
                
            }
            
        }
        return count;
    }
};
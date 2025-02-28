/* 给你两个 正整数 l 和 r。对于任何数字 x，x 的所有正因数（除了 x 本身）被称为 x 的 真因数。

如果一个数字恰好仅有两个 真因数，则称该数字为 特殊数字。例如：

数字 4 是 特殊数字，因为它的真因数为 1 和 2。
数字 6 不是 特殊数字，因为它的真因数为 1、2 和 3。
返回区间 [l, r] 内 不是 特殊数字 的数字数量。 */

#include <cmath>
using namespace std;



class Solution {
private:

    bool isPrime(int num)
    {
        if(num <= 3)
        {
            return num > 1;
        }
        if (num % 6 != 1 && num % 6 != 5)
        {
            return false;
        }
        int sqrt_num = sqrt(num);
        for(int i=5;i<=sqrt_num;i+=6)
        {
            if(num % i == 0 || num % (i+2) == 0)
            {
                return false;
            }
        }
        return true;
    }

public:
    int nonSpecialCount(int l, int r) {
        int count = 0;
        for (int i = l; i <= r; i++)
        {
            int s = sqrt(i);
            if (s != sqrt(i))
            {
                continue;
            }
            
            if(!isPrime(s))
            {
                continue;
            }
            count++;  
        }
        return r-l+1-count;
    }
};
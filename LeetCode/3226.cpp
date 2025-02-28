/* 给你两个正整数 n 和 k。
你可以选择 n 的 二进制表示 中任意一个值为 1 的位，并将其改为 0。
返回使得 n 等于 k 所需要的更改次数。如果无法实现，返回 -1。 */

#include<cmath>

class Solution {
public:
    int minChanges(int n, int k) {
        if(n == k)
        {
            return 0;
        }
        int num1 = log2(n) + 1;
        int num = 0; 
        while(n > k && num1 >= 0)
        {
            if(n - pow(2, num1) >= k && (n & (int)pow(2, num1)) > 0)
            {
                n = n - pow(2, num1);
                num++;
            }
            num1--;
        }
        if(n != k)
        {
            return -1;
        }
        return num;
    }
};
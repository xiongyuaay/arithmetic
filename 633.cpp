/* 给定一个非负整数 c ，你要判断是否存在两个整数 a 和 b，使得 a2 + b2 = c 。 */
#include <cmath>

class Solution {
public:
    bool judgeSquareSum(int c) {
        int limit = sqrt(c);
        for(int a=1;a<=limit;a++)
        {
            int b = c - a*a;
            double temp = sqrt(b);
            if(floor(temp) == temp)
            {
                return true;
            }
        }
        return false;
    }
};
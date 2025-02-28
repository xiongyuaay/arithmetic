/* 给你一个整数数组 colors 和一个整数 k ，colors表示一个由红色和蓝色瓷砖组成的环，第 i 块瓷砖的颜色为 colors[i] ：

colors[i] == 0 表示第 i 块瓷砖的颜色是 红色 。
colors[i] == 1 表示第 i 块瓷砖的颜色是 蓝色 。
环中连续 k 块瓷砖的颜色如果是 交替 颜色（也就是说除了第一块和最后一块瓷砖以外，中间瓷砖的颜色与它 左边 和 右边 的颜色都不同），那么它被称为一个 交替 组。

请你返回 交替 组的数目。

注意 ，由于 colors 表示一个 环 ，第一块 瓷砖和 最后一块 瓷砖是相邻的。

 */
#include <vector>
using namespace std;

class Solution {
public:
    int numberOfAlternatingGroups(vector<int>& colors, int k) {
        int curr = 0;
        int num = colors.size();
        int count = 0;
        int flag = 1;
        
        while (curr < num)
        {
            if (!flag)
            {
                if (colors[(curr+k-2)%num] != colors[(curr+k-1)%num])
                {
                    curr++;
                    count++;
                    flag = 0;
                }
                else
                {
                    curr = curr + k - 1;
                    flag = 1;
                }
                continue;    
            }
            
            flag = 0;
            for (int i = 0; i < k-1; i++)
            {
                if (colors[(i+curr)%num] == colors[(curr+i+1)%num])
                {
                    curr = curr+i+1;
                    flag = 1;
                    break;
                }
            }
            if (flag)
            {
                continue;
            }
            curr++;
            count++;
        }
        return count;
    }
};

int main()
{
    Solution s;
    vector<int> colors = {0, 1, 0, 1, 0};
    int k = 3;
    s.numberOfAlternatingGroups(colors, k);
    return 0;
}
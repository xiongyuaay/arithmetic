/* 小R正在计划一次从地点A到地点B的徒步旅行，总路程需要 N 天。为了在旅途中保持充足的能量，小R每天必须消耗1份食物。幸运的是，小R在路途中每天都会经过一个补给站，可以先购买完食物后再消耗今天的1份食物。然而，每个补给站的食物每份的价格可能不同，并且小R在购买完食物后最多只能同时携带 K 份食物。

现在，小R希望在保证每天食物消耗的前提下，以最小的花费完成这次徒步旅行。你能帮助小R计算出最低的花费是多少吗？

**输入 **

n 总路程需要的天数
k 小R最多能同时携带食物的份数
data[i] 第i天补给站每份食物的价格
**输出 **

返回完成这次徒步旅行的最小花费
**约束条件 **

1 < n,k < 1000
1 < data[i] < 10000 */

#include <iostream>
#include <vector>
using namespace std;

const int INF = 1e9;


int solution(int n, int k, std::vector<int> data) 
{
    vector<vector<int>> dp(n, vector<int>(k, INF));
    for (int i = 0; i < k; i++)
    {
        dp[0][i] = (i + 1) * data[0];
    }

    for (int i = 1; i < n; i++)
    {
        for (int j = 0; j < k; j++)
        {
            int minCost = INF;
            for (int m = 0; m < j+2 && m < k; m++)
            {
                int cost = (j-m+1)*data[i] + dp[i-1][m];
                if (cost < minCost)
                {
                    minCost = cost;
                }
                
            }
            dp[i][j] = minCost;
            
        }
        
    }

    return dp[n-1][0];
}

int main() 
{
    int n, k;
    cin>>n>>k;
    vector<int> data(n);
    for (int i = 0; i < n; i++)
    {
        cin>>data[i];
    }
    

    std::cout << (solution(n, k, data)) << std::endl;
    return 0;
}
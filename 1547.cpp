/* 有一根长度为 n 个单位的木棍，棍上从 0 到 n 标记了若干位置。例如，长度为 6 的棍子可以标记如下：

给你一个整数数组 cuts ，其中 cuts[i] 表示你需要将棍子切开的位置。

你可以按顺序完成切割，也可以根据需要更改切割的顺序。

每次切割的成本都是当前要切割的棍子的长度，切棍子的总成本是历次切割成本的总和。对棍子进行切割将会把一根木棍分成两根较小的木棍（这两根木棍的长度和就是切割前木棍的长度）。请参阅第一个示例以获得更直观的解释。

返回切棍子的 最小总成本 。 */
#include <vector>
#include <iostream>
#include <limits>
using namespace std;

class Solution {
public:
    int minCost(int n, vector<int>& cuts) 
    {
        for (int i = 1; i < cuts.size(); i++)
        {
            for(int j=0;j<cuts.size()-i;j++)
            {
                if (cuts[j] > cuts[j+1])
                {
                    int temp = cuts[j];
                    cuts[j] = cuts[j+1];
                    cuts[j+1] = temp;
                }
                
            }
        }
        
        cuts.push_back(n);
        int len = cuts.size();

        vector<vector<int>> miC(len, vector<int>(len));
        for(int i=0;i<len;i++)
        {
            for(int j=0;j<len;j++)
            {
                miC[i][j] = 0;
            }
        }

        for (int i = 1; i < len; i++)
        {
            for (int j = i; j < len; j++)
            {
                int begin = j-i-1 >= 0 ? cuts[j-i-1] : 0;
                int end = cuts[j];
                int min = INT_MAX;
                for (int k = j-i; k < j; k++)
                {
                    int temp = miC[k-j+i][k] + miC[j-k-1][j];
                    if(temp < min)
                    {
                        min = temp;
                    }
                }  
                miC[i][j] = end - begin + min;
            }
        }
        return miC[len-1][len-1];
    }
};

int main()
{
    int n = 7;
    vector<int> cuts = {1, 3, 4, 5};
    Solution s;
    cout<<s.minCost(n, cuts);
    return 0;
}
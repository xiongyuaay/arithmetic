/* 给你一个 二进制 字符串 s 和一个整数 k。

另给你一个二维整数数组 queries ，其中 queries[i] = [li, ri] 。

如果一个 二进制字符串 满足以下任一条件，则认为该字符串满足 k 约束：

字符串中 0 的数量最多为 k。
字符串中 1 的数量最多为 k。
返回一个整数数组 answer ，其中 answer[i] 表示 s[li..ri] 中满足 k 约束 的 
子字符串
 的数量。 */
#include <vector>
#include <string>
#include <iostream>
using namespace std;

class Solution {
public:
    vector<long long> countKConstraintSubstrings(string s, int k, vector<vector<int>>& queries) {
        vector<vector<long long>> temps;
        int num = s.length();
        temps.resize(num);
        for(int i=0;i<num;i++)
        {
            temps[i].resize(num);
            
            if(i == 0)
            {
                for(int m=0;m<num;m++)
                {
                    temps[i][m] = (s[m] == '1');
                }
            }
            else
            {
                for(int j=0;j<num-i;j++)
                {
                    temps[i][j] = temps[i-1][j+1] + (s[j] == '1');
                }
            }
            for(int j=num-i;j<num;j++)
            {
                temps[i][j] = 0;
            }
            
            
        }

        for(int i=0;i<2;i++)
        {
            for(int j=0;j<num-i;j++)
            {
                temps[i][j] = (i+1) * (i+2) / 2;
            }
            for(int j=num-i;j<num;j++)
            {
                temps[i][j] = 0;
            }
        }

        for(int i=2;i<num;i++)
        {
            for(int j=0;j<num - i;j++)
            {
                if (temps[i][j] <= k || i+1 - temps[i][j] <= k)
                {
                    temps[i][j] = 1 + temps[i-1][j] + temps[i-1][j+1] - temps[i-2][j+1];
                }
                else
                {
                    temps[i][j] = temps[i-1][j] + temps[i-1][j+1] - temps[i-2][j+1];
                }
                
                
            }
        }

        vector<long long> answer;
        answer.resize(queries.size());
        for(int i=0;i<queries.size();i++)
        {
            answer[i] = temps[queries[i][1] - queries[i][0]][queries[i][0]];
        }
        return answer;
    }
};

int main()
{
    Solution s;
    string string = "0001111";
    int k =2;
    vector<vector<int>> queries = {{0, 6}};
    vector<long long> answer =  s.countKConstraintSubstrings(string, k, queries);
    for(auto &ans:answer)
    {
        cout<<ans<<endl;
    }
    return 0;

}
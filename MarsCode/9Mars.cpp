/* 在一个超市里，有一个包含 
n
n 个格子的货物架，每个格子中放有一种商品，商品用小写字母 a 到 z 表示。当顾客进入超市时，他们会依次从第一个格子查找到第 
n
n 个格子，寻找自己想要购买的商品。如果在某个格子中找到该商品，顾客就会购买它并离开；如果中途遇到一个空格子，或查找完所有格子还没有找到想要的商品，顾客也会离开。

作为超市管理员，你可以在顾客到来之前重新调整商品的顺序，以便尽可能多地出售商品。当第一个顾客进入后，商品位置不能再调整。你需要计算在最优调整下，最多可以卖出多少件商品。输入变量说明：

n：货物架的格子数
m：顾客想要购买的商品种类数
s：货物架上商品的初始顺序
c：顾客想要购买的商品种类 */

#include <iostream>
#include <vector>
#include <string>

using namespace std;

int solution(int n, int m, string s, string c) {
    // PLEASE DO NOT MODIFY THE FUNCTION SIGNATURE
    // write code here
    int res = 0;
    for (auto &cur:c)
    {
        auto it = s.find(cur);
        if (it != string::npos)
        {
            res++;
            s.erase(it, 1);
        }
    }
    
    return res;
}

int main() {
    cout << (solution(3, 4, "abc", "abcd") == 3) << endl;
    cout << (solution(4, 2, "abbc", "bb") == 2) << endl;
    cout << (solution(5, 4, "bcdea", "abcd") == 4) << endl;
    return 0;
}
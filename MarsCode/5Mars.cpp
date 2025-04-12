/* 在一场经典的德州扑克游戏中，有一种牌型叫做“葫芦”。“葫芦”由五张牌组成，其中包括三张相同牌面值的牌 
a
a 和另外两张相同牌面值的牌 
b
b。如果两个人同时拥有“葫芦”，我们会优先比较牌 
a
a 的大小，若牌 
a
a 相同则再比较牌 
b
b 的大小，牌面值的大小规则为：1 (A) > K > Q > J > 10 > 9 > ... > 2，其中 1 (A) 的牌面值为1，K 为13，依此类推。

在这个问题中，我们对“葫芦”增加了一个限制：组成“葫芦”的五张牌牌面值之和不能超过给定的最大值 
m
a
x
max。

给定一组牌，你需要找到符合规则的最大的“葫芦”组合，并输出其中三张相同的牌面和两张相同的牌面。如果找不到符合条件的“葫芦”，则输出 “0, 0”。

 */

#include <iostream>
#include <vector>
#include <map>
#include <utility>
using namespace std;

std::vector<int> solution(int n, int max, const std::vector<int>& array) {
    // Edit your code here
    map<int, int> nums;
    if (max < 5)
    {
        return {0, 0};
    }
    
    for (auto &num:array)
    {
        nums[num]++;
    }
    int len = nums.size();
    vector<pair<int, int>> vary(len, {0, 0});
    int count = 0;
    for (auto &[key, value]:nums)
    {
        vary[count].first = key;
        vary[count].second = value;
        count++;
    }
    
    vector<vector<int>> res(len, vector<int>(len, 0));
    for (int i = 0;i < len;i++)
    {
        for (int j = 0;j < len;j++)
        {
            if (vary[i].first*3 + vary[j].first*2 <= max)
            {
                if (i == j && vary[i].second >= 5)
                {
                    res[i][j] = 1;
                }
                if (i != j && vary[i].second >= 3 && vary[j].second >= 2)
                {
                    res[i][j] = 1;
                }
            }
        }
    }

    if (vary[0].first == 1)
    {
        if (vary[0].second >= 5)
        {
            return {1, 1};
        }
        
        if (vary[0].second >= 3)
        {
            for (int i = len - 1; i >= 0; i--)
            {
                if (res[0][i] == 1)
                {
                    return {1, vary[i].first};
                }
                
            }
            
        }
        if (vary[0].second >= 2 && vary[0].second < 3)
        {
            for (int i = len-1; i >= 0; i--)
            {
                if (res[i][0] == 1)
                {
                    return {vary[i].first, 1};
                }
                
            }
            
        }
        
        
    }
    
    
    for (int  i = len-1; i >= 0; i--)
    {
        for (int j = len-1; j >= 0; j--)
        {
            if (res[i][j] == 1)
            {
                return {vary[i].first, vary[j].first};
            }
            
        }
        
    }
    

    
    


    return {0, 0};
}

int main() {
    // Add your test cases here
    
    std::vector<int> result1 = solution(9, 34, {6, 6, 6, 8, 8, 8, 5, 5, 1});
    std::cout << (result1 == std::vector<int>{8, 5}) << std::endl;

    std::vector<int> result2 = solution(9, 37, {9, 9, 9, 9, 6, 6, 6, 6, 13});
    std::cout << (result2 == std::vector<int>{6, 9}) << std::endl;

    std::vector<int> result3 = solution(9, 40, {1, 11, 13, 12, 7, 8, 11, 5, 6});
    std::cout << (result3 == std::vector<int>{0, 0}) << std::endl;

    return 0;
}

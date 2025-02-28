/* 在 LeetCode 商店中， 有 n 件在售的物品。每件物品都有对应的价格。然而，也有一些大礼包，每个大礼包以优惠的价格捆绑销售一组物品。
给你一个整数数组 price 表示物品价格，其中 price[i] 是第 i 件物品的价格。另有一个整数数组 needs 表示购物清单，其中 needs[i] 是需要购买第 i 件物品的数量。
还有一个数组 special 表示大礼包，special[i] 的长度为 n + 1 ，其中 special[i][j] 表示第 i 个大礼包中内含第 j 件物品的数量，且 special[i][n] （也就是数组中的最后一个整数）为第 i 个大礼包的价格。
返回 确切 满足购物清单所需花费的最低价格，你可以充分利用大礼包的优惠活动。你不能购买超出购物清单指定数量的物品，即使那样会降低整体价格。任意大礼包可无限次购买。 */
#include <vector>
#include <limits.h>
#include <iostream>
using namespace std;

class Solution {
public:
    int shoppingOffers(vector<int>& price, vector<vector<int>>& special, vector<int>& needs) {
        int variety = needs.size();
        int length = special.size();
        for(auto i=special.begin();i!=special.end();i++)
        {
            for(auto j=special.begin();j!=special.end();j++)
            {
                if(i == j)
                {
                    continue;
                }
                int flag = 0;
                for(int k=0;k<variety;k++)
                {
                    if(i->at(k) == j->at(k))
                    {
                        flag++;
                    }
                }
                if(i->back() <= j->back() && flag == variety)
                {
                    auto k = j-1;
                    special.erase(j);
                    j = k;
                }

            }
        }
        return dynamic(price, special, needs);
    }

    int dynamic(vector<int>& price, vector<vector<int>>& special, vector<int>& needs)
    {
        int min_price = INT_MAX;
        int variety = needs.size();
        int p = 0;
        int length = special.size();
        for(auto &s:special)
        {
            int flag = 0;
            for(int i=0;i<variety;i++)
            {
                if(s[i] > needs[i])
                {
                    flag++;
                    break;
                }
            }
            if(flag)
            {
                continue;
            }
            for(int i=0;i<variety;i++)
            {
                needs[i] = needs[i] - s[i];
            }
            p = s.back() + shoppingOffers(price, special, needs);
            if(min_price > p)
            {
                min_price = p;
            }
            for(int i=0;i<variety;i++)
            {
                needs[i] = needs[i] + s[i];
            }
        }
        int total = 0;
        for(int i=0;i<variety;i++)
        {
            total += needs[i] * price[i];
        }
        if(total < min_price)
        {
            min_price = total;
        }
        return min_price;
    }
};

int main()
{
    Solution s;
    vector<int> price = {3, 4};
    vector<vector<int>> special = {{1,2,3},{1,2,5}};
    vector<int> needs ={2, 2};
    int p = s.shoppingOffers(price, special, needs);
    cout<<p<<endl;
    return 0;

}
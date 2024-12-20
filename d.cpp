/* 小蓝有一个整数，初始值为 1 ，他可以花费一些代价对这个整数进行变换。

小蓝可以花费 1 的代价将整数增加 1 。

小蓝可以花费 3 的代价将整数增加一个值，这个值是整数的数位中最大的那个（1 到 9）。

小蓝可以花费 10 的代价将整数变为原来的 2 倍。

例如，如果整数为 16，花费 3 将整数变为 22 。

又如，如果整数为 22，花费 1 将整数变为 23 。

又如，如果整数为 23，花费 10 将整数变为 46 。

请问，如果要将整数从初始值 1 变为 2024，请问最少需要多少代价？ */
#include <utility>
#include <vector>
#include <queue>
#include <iostream>
using namespace std;
using pos = pair<int, int>;

int main()
{
    pos begin(0, 1);
    priority_queue<pos, vector<pos>, std::greater<>> wait;
    wait.emplace(begin);

    while (wait.top().second < 2024)
    {
        pos curr = wait.top();
        cout<<curr.second<<endl;
        wait.pop();

        int max = 0;
        int temp = curr.second;
        while (temp != 0)
        {
            int t = temp % 10;
            temp = temp / 10;
            if (t>max)
            {
                max = t;
            }
            
        }
        

        wait.emplace(curr.first+1, curr.second+1);
        wait.emplace(curr.first+3, curr.second+max);
        wait.emplace(curr.first+10, curr.second*2);

    }
    cout<<wait.top().first<<wait.top().second<<endl;
    return 0;
    
}
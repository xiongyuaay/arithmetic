/* 有 n 个网络节点，标记为 1 到 n。

给你一个列表 times，表示信号经过 有向 边的传递时间。 times[i] = (ui, vi, wi)，其中 ui 是源节点，vi 是目标节点， wi 是一个信号从源节点传递到目标节点的时间。

现在，从某个节点 K 发出一个信号。需要多久才能使所有节点都收到信号？如果不能使所有节点收到信号，返回 -1 。 */
#include <vector>
#include <limits>
#include <queue>
#include <algorithm>
#include <iostream>
using namespace std;

struct Edge
{
    int to;
    int weight;
    Edge(int to, int weight): to(to), weight(weight) {}
};
using Graph = vector<vector<Edge>>;

class Solution {
private:
    Graph init(vector<vector<int>>& times, int n)
    {
        Graph graph(n);
        for (auto &time:times)
        {
            graph[time[0]-1].emplace_back(time[1]-1, time[2]);
        }
        return graph;
    }

public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) 
    {
        vector<int> usedTime(n, numeric_limits<int>::max());
        usedTime[k-1] = 0;
        Graph graph = init(times, n);
        queue<int> path;
        path.push(k-1);
        while (!path.empty())
        {
            int curr = path.front();
            path.pop();

            for(auto &edge:graph[curr])
            {
                if (usedTime[edge.to] != numeric_limits<int>::max() && edge.weight + usedTime[curr] >= usedTime[edge.to])
                {
                    continue;
                }
                path.push(edge.to);
                usedTime[edge.to] = edge.weight + usedTime[curr];
            }
        }

        auto it = find(usedTime.begin(), usedTime.end(), numeric_limits<int>::max());
        if (it == usedTime.end())
        {
            int max = *max_element(usedTime.begin(), usedTime.end());
            return max;
        }
        else
        {
            return -1;
        }
        
        
        
        
    }
};

int main()
{
    Solution s;
    vector<vector<int>> times = {{1, 2, 1}, {2, 3, 2}, {1, 3, 4}};
    int n = 3;
    int k = 1;
    int res = s.networkDelayTime(times, n, k);
    cout<<res<<endl;
    return 0;

}
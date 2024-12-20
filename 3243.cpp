/* 给你一个整数 n 和一个二维整数数组 queries。

有 n 个城市，编号从 0 到 n - 1。初始时，每个城市 i 都有一条单向道路通往城市 i + 1（ 0 <= i < n - 1）。

queries[i] = [ui, vi] 表示新建一条从城市 ui 到城市 vi 的单向道路。每次查询后，你需要找到从城市 0 到城市 n - 1 的最短路径的长度。

返回一个数组 answer，对于范围 [0, queries.length - 1] 中的每个 i，answer[i] 是处理完前 i + 1 个查询后，从城市 0 到城市 n - 1 的最短路径的长度。 */
#include <vector>
#include <queue>
#include <limits>
using namespace std;

struct Edge
{
    int to;
    int weight;
    Edge() = delete;
    Edge(int to, int weight): to(to), weight(weight){}
};
using Graph = vector<vector<Edge>>;


class Solution 
{
private:
    

public:
    vector<int> shortestDistanceAfterQueries(int n, vector<vector<int>>& queries) 
    {
        Graph graph;
        vector<int> answer;
        int q_num = queries.size();
        graph.resize(n);
        for (int i = 0; i < n-1; i++)
        {
            graph[i].emplace_back(i+1, 1);
        }
        for (int i = 0; i < q_num; i++)
        {
            graph[queries[i][0]].emplace_back(queries[i][1], 1);
            int ans = Dijkstra(graph, 0);
            answer.emplace_back(ans);
        }
        return answer;
    }

    int Dijkstra(const Graph& graph, int start)
    {
        int n = graph.size();
        vector<int> dist(n, __INT_MAX__);
        dist[start] = 0;

        // <distance, destination>
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> pq;
        pq.emplace(0, start);

        while (!pq.empty())
        {
            auto [curr_dist, curr_vertex] = pq.top();
            pq.pop();

            if(curr_dist > dist[curr_vertex]) continue;

            for(const Edge& edge:graph[curr_vertex])
            {
                int new_dist = edge.weight + curr_dist;
                if(new_dist < dist[edge.to])
                {
                    dist[edge.to] = new_dist;
                    pq.emplace(new_dist, edge.to);
                }
            }
        }

        return dist.back();
        
    }
};
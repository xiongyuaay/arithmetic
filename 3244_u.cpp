/* 给你一个整数 n 和一个二维整数数组 queries。

有 n 个城市，编号从 0 到 n - 1。初始时，每个城市 i 都有一条单向道路通往城市 i + 1（ 0 <= i < n - 1）。

queries[i] = [ui, vi] 表示新建一条从城市 ui 到城市 vi 的单向道路。每次查询后，你需要找到从城市 0 到城市 n - 1 的最短路径的长度。

所有查询中不会存在两个查询都满足 queries[i][0] < queries[j][0] < queries[i][1] < queries[j][1]。

返回一个数组 answer，对于范围 [0, queries.length - 1] 中的每个 i，answer[i] 是处理完前 i + 1 个查询后，从城市 0 到城市 n - 1 的最短路径的长度。 */

#include <vector>
#include <algorithm>
#include <set>
#include <numeric>
using namespace std;


class Solution
{
public:
    vector<int> shortestDistanceAfterQueries(int n, vector<vector<int>>& queries) 
    {
        vector<int> dist(n);
        iota(dist.begin(), dist.end(), 0);
        set<int> curr(dist.begin(), dist.end());

        vector<int> answer;
        for (auto &query:queries)
        {
            auto start = curr.lower_bound(query[0] + 1);
            auto end = curr.upper_bound(query[1] - 1);
            curr.erase(start, end);
            answer.emplace_back(curr.size()-1);
        }
        return answer;

    }
};




// 有 n 个网络节点，标记为 1 到 n。

// 给你一个列表 times，表示信号经过 有向 边的传递时间。 times[i] = (ui, vi, wi)，其中 ui 是源节点，vi 是目标节点， wi 是一个信号从源节点传递到目标节点的时间。

// 现在，从某个节点 K 发出一个信号。需要多久才能使所有节点都收到信号？如果不能使所有节点收到信号，返回 -1 。

// 示例 1：

// 输入：times = [[2,1,1],[2,3,1],[3,4,1]], n = 4, k = 2
// 输出：2

// 示例 2：

// 输入：times = [[1,2,1]], n = 2, k = 1
// 输出：1

// 示例 3：

// 输入：times = [[1,2,1]], n = 2, k = 2
// 输出：-1

// 提示：

//     1 <= k <= n <= 100
//     1 <= times.length <= 6000
//     times[i].length == 3
//     1 <= ui, vi <= n
//     ui != vi
//     0 <= wi <= 100
//     所有 (ui, vi) 对都 互不相同（即，不含重复边）

#include <iostream>
#include <vector>
#include <queue>
#include <limits>
#include <stdio.h>

using namespace std;

int n = 0, k = 0;

vector<vector<int>> times;

void get_input()
{
    int m = 0;
    cin >> m;
    int from = 0, to = 0, weight = 0;
    for (int i = 0; i < m; ++i)
    {
        vector<int> tmp(3, 0);
        cin >> tmp[0] >> tmp[1] >> tmp[2];
        times.push_back(tmp);
    }
    cin >> n >> k;
}

class Solution
{
public:
    class Edge
    {
    public:
        int from, to, weight;
        Edge() : from(0), to(0), weight(0) {}
        Edge(int from, int to, int weight) : from(from), to(to), weight(weight) {}
    };
    class DistFromSource
    {
    public:
        int id, distance;
        DistFromSource() : id(0), distance(0) {}
        DistFromSource(int id, int distance) : id(id), distance(distance) {}
    };
    class DistFromSourceComparator
    {
    public:
        bool operator()(const DistFromSource &obj_1, const DistFromSource &obj_2)
        {
            return obj_1.distance > obj_2.distance;
        }
    };
    int networkDelayTime(vector<vector<int>> &times, int n, int k)
    {
        vector<vector<Edge>> graph;
        for (int i = 0; i < n + 1; ++i)
        {
            vector<Edge> tmp;
            graph.push_back(tmp);
        }
        for (int i = 0; i < times.size(); ++i)
        {
            vector<int> tmp = times[i];
            int from = tmp[0], to = tmp[1], weight = tmp[2];
            Edge e(from, to, weight);
            graph[e.from].push_back(e);
        }
        vector<bool> used(n + 1, false);
        vector<int> dist_to(n + 1, INT32_MAX);
        priority_queue<DistFromSource, vector<DistFromSource>, DistFromSourceComparator> pq;
        dist_to[k] = 0;
        DistFromSource dist(k, dist_to[k]);
        pq.push(dist);
        while (!pq.empty())
        {
            DistFromSource dist = pq.top();
            pq.pop();
            int id = dist.id;
            for (int i = 0; i < graph[id].size(); ++i)
            {
                Edge e = graph[id][i];
                if (dist_to[id] + e.weight < dist_to[e.to])
                {
                    dist_to[e.to] = dist_to[id] + e.weight;
                    DistFromSource tmp(e.to, dist_to[e.to]);
                    pq.push(tmp);
                }
            }
        }
        int max_dist = 0;
        for (int i = 1; i <= n; ++i)
        {
            if (dist_to[i] > max_dist)
            {
                max_dist = dist_to[i];
            }
        }
        return max_dist == INT32_MAX ? -1 : max_dist;
    }
};

int main(int argc, char const *argv[])
{
    get_input();
    Solution().networkDelayTime(times, n, k);
    return 0;
}
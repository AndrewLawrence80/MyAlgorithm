// 给你一个points 数组，表示 2D 平面上的一些点，其中 points[i] = [xi, yi] 。

// 连接点 [xi, yi] 和点 [xj, yj] 的费用为它们之间的 曼哈顿距离 ：|xi - xj| + |yi - yj| ，其中 |val| 表示 val 的绝对值。

// 请你返回将所有点连接的最小总费用。只有任意两点之间 有且仅有 一条简单路径时，才认为所有点都已连接。

// 示例 1：

// 输入：points = [[0,0],[2,2],[3,10],[5,2],[7,0]]
// 输出：20
// 解释：

// 我们可以按照上图所示连接所有点得到最小总费用，总费用为 20 。
// 注意到任意两个点之间只有唯一一条路径互相到达。

// 示例 2：

// 输入：points = [[3,12],[-2,5],[-4,1]]
// 输出：18

// 示例 3：

// 输入：points = [[0,0],[1,1],[1,0],[-1,1]]
// 输出：4

// 示例 4：

// 输入：points = [[-1000000,-1000000],[1000000,1000000]]
// 输出：4000000

// 示例 5：

// 输入：points = [[0,0]]
// 输出：0

// 提示：
//     1 <= points.length <= 1000
//     -10^6 <= xi, yi <= 10^6
//     所有点 (xi, yi) 两两不同。

#include <iostream>
#include <vector>
#include <queue>
#include <math.h>
#include <stdio.h>
#include <limits>

using namespace std;

class Edge
{
public:
    int from;
    int to;
    int weight;
    Edge() : from(0), to(0), weight(0) {}
    Edge(int from, int to, int weight) : from(from), to(to), weight(weight) {}
};

class EdgeComparator
{
public:
    bool operator()(const Edge &edge_a, const Edge &edge_b)
    {
        return edge_a.weight > edge_b.weight;
    }
};

vector<vector<int>> points;

void get_input()
{
    int M = 0; // number of edges
    cin >> M;
    vector<int> tmp(2, 0);
    for (int i = 0; i < M; ++i)
    {
        cin >> tmp[0] >> tmp[1];
        points.push_back(tmp);
    }
}

class Solution
{
public:
    int minCostConnectPoints(vector<vector<int>> &points)
    {
        int n_points = points.size();
        vector<vector<Edge>> graph;
        for (int i = 0; i < n_points; ++i)
        {
            vector<Edge> tmp;
            graph.push_back(tmp);
        }
        for (int i = 0; i < n_points; ++i)
        {
            for (int j = i + 1; j < n_points; ++j)
            {
                vector<int> u = points[i], v = points[j];
                int x1 = u[0], y1 = u[1], x2 = v[0], y2 = v[1];
                int distance = abs(x1 - x2) + abs(y1 - y2);
                Edge edge_a(i, j, distance), edge_b(j, i, distance);
                graph[i].push_back(edge_a);
                graph[j].push_back(edge_b);
            }
        }
        vector<bool> inMST(n_points, false);
        inMST[0] = true;
        priority_queue<Edge, vector<Edge>, EdgeComparator> pq;
        int cost = 0;
        for (int i = 0; i < graph[0].size(); ++i)
        {
            Edge e = graph[0][i];
            pq.push(e);
        }
        while (!pq.empty())
        {
            Edge e = pq.top();
            pq.pop();
            if (inMST[e.to])
            {
                continue;
            }
            else
            {
                cost += e.weight;
                int to = e.to;
                inMST[to] = true;
                for (int i = 0; i < graph[to].size(); ++i)
                {
                    Edge tmp = graph[to][i];
                    if (inMST[tmp.to])
                    {
                        continue;
                    }
                    else
                    {
                        pq.push(tmp);
                    }
                }
            }
        }
        return cost;
    }
};

int main(int argc, char const *argv[])
{
    get_input();
    cout << Solution().minCostConnectPoints(points);
    return 0;
}
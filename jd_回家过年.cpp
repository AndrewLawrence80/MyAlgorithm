#include <iostream>
#include <vector>
#include <deque>
#include <stack>
#include <unordered_map>
#include <algorithm>
#include <string>

using namespace std;

class Edge
{
public:
    int from;
    int to;
    int cost;
    Edge(int from, int to, int cost)
    {
        this->from = from;
        this->to = to;
        this->cost = cost;
    }
};

vector<vector<Edge>> adj;
int answer = 0;
vector<bool> visited;

void dfs(int from, int to, int cost, int wantcost)
{
    if (from == to)
    {
        if (cost == wantcost)
        {
            answer++;
        }
        return;
    }
    visited[from] = true;
    for (int i = 0; i < adj[from].size(); i++)
    {
        if (!visited[adj[from][i].to])
        {
            dfs(adj[from][i].to, to, cost + adj[from][i].cost, wantcost);
        }
    }
    visited[from] = false;
}

int main(int argc, char const *argv[])
{
    int n, m, a;
    cin >> n >> m >> a;
    adj.resize(n + 1);
    for (int i = 0; i < m; i++)
    {
        int from, to, cost;
        cin >> from >> to >> cost;
        adj[from].push_back(Edge(from, to, cost));
        // adj[to].push_back(Edge(to, from, cost));
    }
    visited.resize(n + 1, false);
    dfs(1, n, 0, a);
    if (answer > 20220201)
    {
        cout << "All roads lead to Home!" << endl;
        cout << answer % 20220201 << endl;
    }
    else
    {
        cout << answer << endl;
    }
    return 0;
}
// 给你一个有 n 个节点的 有向无环图（DAG），请你找出所有从节点 0 到节点 n-1 的路径并输出（不要求按特定顺序）

// graph[i] 是一个从节点 i 可以访问的所有节点的列表（即从节点 i 到节点 graph[i][j]存在一条有向边）。

// 示例 1：

// 输入：graph = [[1,2],[3],[3],[]]
// 输出：[[0,1,3],[0,2,3]]
// 解释：有两条路径 0 -> 1 -> 3 和 0 -> 2 -> 3

// 示例 2：

// 输入：graph = [[4,3,1],[3,2,4],[3],[4],[]]
// 输出：[[0,4],[0,3,4],[0,1,3,4],[0,1,2,3,4],[0,1,4]]

// 提示：

//     n == graph.length
//     2 <= n <= 15
//     0 <= graph[i][j] < n
//     graph[i][j] != i（即不存在自环）
//     graph[i] 中的所有元素 互不相同
//     保证输入为 有向无环图（DAG
#include <iostream>
#include <vector>
#include <string.h>

using namespace std;

int N = 0;

vector<vector<int>> graph;

void get_input()
{
    cin >> N;
    cin.get();
    for (int i = 0; i < N; ++i)
    {
        vector<int> tmp;
        char s[80] = {0};
        fgets(s, 80, stdin);
        char *p = strchr(s, '\n');
        if (p)
        {
            *p = '\0';
        }
        int start_i = 0;
        for (int j = 0; j < strlen(s); ++j)
        {
            if (s[j] == ' ')
            {
                char n[80] = {0};
                strncpy(n, s + start_i, j - start_i);
                tmp.push_back(atoi(n));
                start_i = j + 1;
            }
        }
        char n[80] = {0};
        strncpy(n, s + start_i, strlen(s) - start_i);
        tmp.push_back(atoi(n));
        graph.push_back(tmp);
    }
}

class Solution
{
public:
    vector<vector<int>> ans;
    vector<int> current_path;
    void dfs(int source, int target, vector<int> &current_path)
    {
        if (source == target)
        {
            vector<int> tmp(current_path);
            tmp.push_back(source);
            ans.push_back(tmp);
        }
        else
        {
            current_path.push_back(source);
            for (int i = 0; i < graph[source].size(); ++i)
            {
                dfs(graph[source][i], target, current_path);
            }
            current_path.pop_back();
        }
    }
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>> &graph)
    {
        dfs(0, graph.size() - 1, current_path);
        return ans;
    }
};

int main(int argc, char const *argv[])
{
    get_input();
    Solution().allPathsSourceTarget(graph);
    return 0;
}
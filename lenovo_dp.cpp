#include <iostream>
#include <vector>
#include <deque>
#include <stack>
#include <unordered_map>
#include <algorithm>
#include <string>

using namespace std;

int n = 0, T = 0;

vector<int> heat_accum;
vector<int> value;
vector<int> heat_loss;

vector<vector<int>> dp;

int dfs(int idx, int current_heat, int current_value)
{
    if (idx == n + 1)
    {
        return current_value;
    }
    if (dp[idx][current_heat] != -1)
    {
        return dp[idx][current_heat];
    }
    if (current_heat + heat_accum[idx] > T)
    {
        int next_heat = current_heat - heat_loss[idx];
        if (next_heat < 0)
        {
            next_heat = 0;
        }
        dp[idx][current_heat] = dfs(idx + 1, next_heat, current_value);
        return dp[idx][current_heat];
    }
    else
    {
        int next_heat_no_work = current_heat - heat_loss[idx];
        if (next_heat_no_work < 0)
        {
            next_heat_no_work = 0;
        }
        int next_heat_work = current_heat + heat_accum[idx];
        dp[idx][current_heat] = max(dfs(idx + 1, next_heat_work, current_value + value[idx]), dfs(idx + 1, next_heat_no_work, current_value));
        return dp[idx][current_heat];
    }
}

int main(int argc, char const *argv[])
{
    cin >> n >> T;
    heat_accum.resize(n);
    value.resize(n);
    heat_loss.resize(n);
    for (int i = 0; i < n; ++i)
    {
        cin >> heat_accum[i] >> value[i] >> heat_loss[i];
    }
    dp.resize(n + 1, vector<int>(T + 1, -1));
    dfs(0, 0, 0);
    int maxV = 0;
    for (int i = 0; i <= n; ++i)
    {
        for (int j = 0; j <= T; ++j)
        {
            if (dp[i][j] > maxV)
            {
                maxV = dp[i][j];
            }
        }
    }
    cout << maxV << endl;
    return 0;
}
// 标题
// 01数组最大正方形

// 题目描述
// 给定的m * n二维数组只含有0或者1，求包含1的最大正方形面积。​

// 例如：​

// 1 0 1 0 0​

// 1 0 1 1 1​

// 1 0 1 1 1​

// 1 0 0 1 0​

// 上例最大正方形面积为4
// 对角线(1,2) - (2,3)

// 小心的case

// 1 1 0
// 1 1 1
// 0 1 1

#include <iostream>
#include <vector>
#include <deque>
#include <unordered_map>
#include <algorithm>
#include <string>

using namespace std;

int main(int argc, char const *argv[])
{
    int m = 0, n = 0;
    cin >> m >> n;
    vector<vector<int>> input(m, vector<int>(n, 0));
    for (int i = 0; i < m; ++i)
    {
        for (int j = 0; j < n; ++j)
        {
            cin >> input[i][j];
        }
    }

    vector<vector<int>> dp(m, vector<int>(n, 0));
    int maxS = 0;
    for (int i = 0; i < m; ++i)
    {
        dp[i][0] = input[i][0];
        if (input[i][0] == 1 && maxS < 1)
        {
            maxS = 1;
        }
    }
    for (int j = 0; j < n; ++j)
    {
        dp[0][j] = input[0][j];
        if (input[0][j] == 1 && maxS < 1)
        {
            maxS = 1;
        }
    }
    for (int i = 1; i < m; ++i)
    {
        for (int j = 1; j < n; ++j)
        {
            if (input[i][j] == 1)
            {
                if (i == m - 1 && j == n - 1)
                {
                    cout << endl;
                }
                if (input[i - 1][j - 1] == 1 && input[i][j - 1] == 1 && input[i - 1][j] == 1)
                {
                    dp[i][j] = dp[i - 1][j - 1];
                }
                if (dp[i - 1][j - 1] == 1 && dp[i][j - 1] == 1 && dp[i - 1][j] == 1)
                {
                    dp[i][j] = dp[i - 1][j - 1] + 1;
                }
                int tMax = dp[i][j] * dp[i][j];
                if (tMax > maxS)
                {
                    maxS = tMax;
                }
            }
        }
    }
    cout << maxS;
    return 0;
}
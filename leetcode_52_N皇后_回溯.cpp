// n 皇后问题 研究的是如何将 n 个皇后放置在 n × n 的棋盘上，并且使皇后彼此之间不能相互攻击。

// 给你一个整数 n ，返回 n 皇后问题 不同的解决方案的数量。
#include <iostream>
#include <vector>
#include <math.h>
#include <stdio.h>

using namespace std;

class Solution
{
public:
    vector<int> ans;
    int total = 0;
    void dfs(int current_row, int n)
    {
        if (ans.size() == n)
        {
            total += 1;
        }
        else
        {
            for (int i = 0; i < n; ++i)
            {
                if (isValid(i))
                {
                    ans.push_back(i);
                    dfs(current_row + 1, n);
                    ans.pop_back();
                }
            }
        }
    }
    int totalNQueens(int n)
    {
        dfs(0, n);
        return total;
    }
    int isValid(int y)
    {
        for (int i = 0; i < ans.size(); ++i)
        {
            if (ans[i] == y)
            {
                return false;
            }
            else if (ans[i] + i == ans.size() + y)
            {
                return false;
            }
            else if (i - ans[i] == (int)ans.size() - y)
            {
                return false;
            }
        }
        return true;
    }
};

int main(int argc, char const *argv[])
{
    int n = 0;
    cin >> n;
    cout << Solution().totalNQueens(n);
    return 0;
}
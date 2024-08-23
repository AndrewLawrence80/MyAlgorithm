// 标题
// 单词搜索

// 题目描述
// 给定1个二维字符数组cmap和单词1个word，搜索word是否在map中。​
// 搜索的定义是从cmap的任意位置开始，可以上下左右移动，依次和word每个字符匹配，如果word能匹配完，则存在，否则不存在。​

// ​
// a c d z​
// x t r o​
// f i w o​​​
// ​
// 注：cmap中的每个位置只能被访问1次
#include <iostream>
#include <vector>

using namespace std;

class Solution
{
public:
    bool dfs(vector<vector<char>> &matrix, int x, int y, string target, int idx)
    {
        if (idx == target.size())
        {
            return true;
        }
        if (x < 0 || x >= matrix.size() || y < 0 || y >= matrix[0].size())
        {
            return false;
        }
        if (matrix[x][y] != target[idx])
        {
            return false;
        }
        return dfs(matrix, x - 1, y, target, idx + 1) || dfs(matrix, x + 1, y, target, idx + 1) || dfs(matrix, x, y - 1, target, idx + 1) || dfs(matrix, x, y + 1, target, idx + 1);
    }
    bool findWord(vector<vector<char>> &matrix, string target)
    {
        int m = matrix.size(), n = matrix[0].size();
        for (int i = 0; i < m; ++i)
        {
            for (int j = 0; j < n; ++j)
            {
                bool found = dfs(matrix, i, j, target, 0);
                if (found)
                {
                    return true;
                }
            }
        }
        return false;
    }
};

int main()
{
    int m = 0, n = 0;
    cin >> m >> n;
    vector<vector<char>> matrix(m, vector<char>(n));
    string s;
    for (int i = 0; i < m; ++i)
    {
        cin >> s;
        for (int j = 0; j < s.size(); ++j)
        {
            matrix[i][j] = s[j];
        }
    }
    cin >> s;
    cout << Solution().findWord(matrix, s);
    return 0;
}
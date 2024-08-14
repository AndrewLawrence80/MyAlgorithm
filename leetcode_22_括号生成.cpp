// 数字 n 代表生成括号的对数，请你设计一个函数，用于能够生成所有可能的并且 有效的 括号组合。

// 示例 1：

// 输入：n = 3
// 输出：["((()))","(()())","(())()","()(())","()()()"]

// 示例 2：

// 输入：n = 1
// 输出：["()"]

#include <iostream>
#include <vector>
#include <deque>
#include <unordered_map>
#include <algorithm>
#include <string>

using namespace std;

class Solution
{
public:
    vector<string> answer;
    void dfs(int left, int right, string tmp)
    {
        if (left == 0)
        {
            for (int i = 0; i < right; ++i)
            {
                tmp += ")";
            }
            answer.push_back(tmp);
            return;
        }
        if (left == right)
        {
            dfs(left - 1, right, tmp + "(");
        }
        if (left < right)
        {
            dfs(left - 1, right, tmp + "(");
            dfs(left, right - 1, tmp + ")");
        }
    }
    vector<string> generateParenthesis(int n)
    {
        dfs(n, n, "");
        return answer;
    }
};

int main(int argc, char const *argv[])
{
    int n = 0;
    cin >> n;
    vector<string> answer = Solution().generateParenthesis(n);
    for (auto s : answer)
    {
        cout << s << endl;
    }
    return 0;
}
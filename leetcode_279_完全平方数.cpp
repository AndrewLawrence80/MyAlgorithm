// 给你一个整数 n ，返回 和为 n 的完全平方数的最少数量 。

// 完全平方数 是一个整数，其值等于另一个整数的平方；换句话说，其值等于一个整数自乘的积。例如，1、4、9 和 16 都是完全平方数，而 3 和 11 不是。

// 示例 1：

// 输入：n = 12
// 输出：3
// 解释：12 = 4 + 4 + 4

// 示例 2：

// 输入：n = 13
// 输出：2
// 解释：13 = 4 + 9

// 提示：

//     1 <= n <= 104

#include <iostream>
#include <vector>
#include <deque>
#include <stack>
#include <unordered_map>
#include <algorithm>
#include <string>

using namespace std;

class Solution
{
public:
    int numSquares(int n)
    {
        vector<int> candidates;
        for (int i = 1; i * i <= n; ++i)
        {
            candidates.push_back(i * i);
        }
        vector<int> squareNums(n + 1, INT32_MAX);
        squareNums[0] = 0;
        squareNums[1] = 1;
        for (int i = 2; i <= n; ++i)
        {
            for (int j = 0; j < candidates.size() && candidates[j] <= i; ++j)
            {
                squareNums[i] = min(squareNums[i], squareNums[i - candidates[j]] + 1);
            }
        }
        return squareNums[n];
    }
};

int main(int argc, char const *argv[])
{
    int n = 0;
    cin >> n;
    cout << Solution().numSquares(n) << endl;
    return 0;
}
// 你是一个专业的小偷，计划偷窃沿街的房屋。每间房内都藏有一定的现金，影响你偷窃的唯一制约因素就是相邻的房屋装有相互连通的防盗系统，如果两间相邻的房屋在同一晚上被小偷闯入，系统会自动报警。

// 给定一个代表每个房屋存放金额的非负整数数组，计算你 不触动警报装置的情况下 ，一夜之内能够偷窃到的最高金额。

// 示例 1：

// 输入：[1,2,3,1]
// 输出：4
// 解释：偷窃 1 号房屋 (金额 = 1) ，然后偷窃 3 号房屋 (金额 = 3)。
//      偷窃到的最高金额 = 1 + 3 = 4 。

// 示例 2：

// 输入：[2,7,9,3,1]
// 输出：12
// 解释：偷窃 1 号房屋 (金额 = 2), 偷窃 3 号房屋 (金额 = 9)，接着偷窃 5 号房屋 (金额 = 1)。
//      偷窃到的最高金额 = 2 + 9 + 1 = 12 。

// 提示：

//     1 <= nums.length <= 100
//     0 <= nums[i] <= 400

#include <iostream>
#include <vector>
#include <algorithm>
#include <stdio.h>

using namespace std;

int N = 0;
vector<int> nums;
void getInput()
{
    cin >> N;
    nums = vector<int>(N, 0);
    for (int i = 0; i < N; ++i)
    {
        cin >> nums[i];
    }
}
class Solution
{
public:
    vector<int> memo;
    int dfs(vector<int> &nums, int idx)
    {
        if (idx < 0)
        {
            return 0;
        }
        else
        {
            if (memo[idx] != -1)
            {
                return memo[idx];
            }
            else
            {
                memo[idx] = max(nums[idx] + dfs(nums, idx - 2), dfs(nums, idx - 1)); // 偷窃当前的房屋，或者不偷窃转下一家碰运气
                return memo[idx];
            }
        }
    }
    int rob(vector<int> &nums)
    {
        int n = nums.size();
        memo = vector<int>(n, -1);
        return max(dfs(nums, n - 1), dfs(nums, n - 2)); // 偷到最后一定是最后一家或者倒数第二家
    }
};

int main(int argc, char const *argv[])
{
    getInput();
    cout << Solution().rob(nums);
    return 0;
}
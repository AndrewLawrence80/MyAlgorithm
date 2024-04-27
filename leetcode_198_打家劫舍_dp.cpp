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
    int rob(vector<int> &nums)
    {
        int n = nums.size();
        vector<int> dp(n + 1, 0); // n+1处理单输入的情况，dp[0]=0的情况是起初啥也不偷，从第二家开始考虑偷
        dp[1] = nums[0];          // 偷第一家的收益
        for (int idx = 2; idx <= n; ++idx)
        {
            dp[idx] = max(nums[idx - 1] + dp[idx - 2], dp[idx - 1]); // 从第二家开始偷
        }
        return dp[n];
    }
};

int main(int argc, char const *argv[])
{
    getInput();
    cout << Solution().rob(nums);
    return 0;
}
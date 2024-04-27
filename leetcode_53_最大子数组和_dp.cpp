// 给你一个整数数组 nums ，请你找出一个具有最大和的连续子数组（子数组最少包含一个元素），返回其最大和。

// 子数组
// 是数组中的一个连续部分。

// 示例 1：

// 输入：nums = [-2,1,-3,4,-1,2,1,-5,4]
// 输出：6
// 解释：连续子数组 [4,-1,2,1] 的和最大，为 6 。

// 示例 2：

// 输入：nums = [1]
// 输出：1

// 示例 3：

// 输入：nums = [5,4,-1,7,8]
// 输出：23

// 提示：

//     1 <= nums.length <= 105
//     -104 <= nums[i] <= 104

#include <iostream>
#include <vector>
#include <algorithm>
#include <stdio.h>

using namespace std;

int N = 0;
vector<int> nums;

void get_input()
{
    cin >> N;
    nums.resize(N, 0);
    for (int i = 0; i < N; ++i)
    {
        cin >> nums[i];
    }
}

class Solution
{
public:
    int maxSubArray(vector<int> &nums)
    {
        vector<int> dp(nums.size(), 0);
        int idx = 0;
        while (idx < nums.size() && nums[idx] < 0)
        {
            dp[idx] = nums[idx];
            ++idx;
        }

        while (idx < nums.size())
        {
            if (idx == 0)
            {
                dp[idx] = nums[idx];
            }
            else
            {
                dp[idx] = max(dp[idx - 1] + nums[idx], nums[idx]);
            }
            ++idx;
        }
        int maxSum = -INT32_MAX;
        for (int i = 0; i < nums.size(); ++i)
        {
            if (dp[i] > maxSum)
            {
                maxSum = dp[i];
            }
        }
        return maxSum;
    }
};

int main(int argc, char const *argv[])
{
    get_input();
    cout << Solution().maxSubArray(nums);
    return 0;
}
// 给你一个整数数组 nums，返回 数组 answer ，其中 answer[i] 等于 nums 中除 nums[i] 之外其余各元素的乘积 。

// 题目数据 保证 数组 nums之中任意元素的全部前缀元素和后缀的乘积都在  32 位 整数范围内。

// 请不要使用除法，且在 O(n) 时间复杂度内完成此题。

// 示例 1:

// 输入: nums = [1,2,3,4]
// 输出: [24,12,8,6]

// 示例 2:

// 输入: nums = [-1,1,0,-3,3]
// 输出: [0,0,9,0,0]

// 提示：

//     2 <= nums.length <= 105
//     -30 <= nums[i] <= 30
//     保证 数组 nums之中任意元素的全部前缀元素和后缀的乘积都在  32 位 整数范围内

#include <iostream>
#include <vector>
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
    vector<int> productExceptSelf(vector<int> &nums)
    {
        if (1 == nums.size())
        {
            vector<int> ans(nums);
            return ans;
        }
        else
        {
            vector<int> leftResult(nums);
            vector<int> rightResult(nums);
            for (int i = 1; i < nums.size(); ++i)
            {
                leftResult[i] = leftResult[i] * leftResult[i - 1];
            }
            for (int i = nums.size() - 2; i >= 0; --i)
            {
                rightResult[i] = rightResult[i] * rightResult[i + 1];
            }
            vector<int> ans = vector<int>(nums.size(), 0);
            for (int i = 0; i < nums.size(); ++i)
            {
                if (0 == i)
                {
                    ans[i] = rightResult[i + 1];
                }
                else if (nums.size() - 1 == i)
                {
                    ans[i] = leftResult[i - 1];
                }
                else
                {
                    ans[i] = leftResult[i - 1] * rightResult[i + 1];
                }
            }
            return ans;
        }
    }
};

void print_output(vector<int> &nums)
{
    for (int x : nums)
    {
        cout << x << " ";
    }
}

int main(int argc, char const *argv[])
{
    get_input();
    vector<int> ans = Solution().productExceptSelf(nums);
    print_output(ans);
    return 0;
}
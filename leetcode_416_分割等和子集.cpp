// 给你一个 只包含正整数 的 非空 数组 nums 。请你判断是否可以将这个数组分割成两个子集，使得两个子集的元素和相等。

// 示例 1：

// 输入：nums = [1,5,11,5]
// 输出：true
// 解释：数组可以分割成 [1, 5, 5] 和 [11] 。

// 示例 2：

// 输入：nums = [1,2,3,5]
// 输出：false
// 解释：数组不能分割成两个元素和相等的子集。

// 提示：

//     1 <= nums.length <= 200
//     1 <= nums[i] <= 100

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
    bool canPartition(vector<int> &nums)
    {
        int sum = 0;
        for (int x : nums)
        {
            sum += x;
        }
        if (sum % 2 != 0)
        {
            return false;
        }
        int target = sum / 2;
        int n = nums.size();
        vector<bool> dp_prev = vector<bool>(sum + 1, false);
        dp_prev[0] = true;
        dp_prev[nums[0]] = true;
        for (int i = 1; i < n; i++)
        {
            vector<bool> dp_next = vector<bool>(sum + 1, false);
            for (int j = 0; j < sum; ++j)
            {
                if (dp_prev[j])
                {
                    dp_next[j] = true;
                    dp_next[j + nums[i]] = true;
                }
            }
            dp_prev = dp_next;
        }
        return dp_prev[target];
    }
};

int main(int argc, char const *argv[])
{
    int n = 0;
    cin >> n;
    vector<int> nums(n);
    for (int i = 0; i < n; i++)
    {
        cin >> nums[i];
    }
    sort(nums.begin(), nums.end());
    cout << Solution().canPartition(nums);
    return 0;
}
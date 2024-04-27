// 给你一个整数数组 nums 和一个整数 k ，请你统计并返回 该数组中和为 k 的子数组的个数 。

// 子数组是数组中元素的连续非空序列。

// 示例 1：

// 输入：nums = [1,1,1], k = 2
// 输出：2

// 示例 2：

// 输入：nums = [1,2,3], k = 3
// 输出：2

// 提示：

//     1 <= nums.length <= 2 * 104
//     -1000 <= nums[i] <= 1000
//     -107 <= k <= 107

#include <iostream>
#include <vector>
#include <stdio.h>

using namespace std;

int N = 0, k = 0;
vector<int> nums;
void get_input()
{
    cin >> N;
    nums.resize(N, 0);
    for (size_t i = 0; i < N; i++)
    {
        cin >> nums[i];
    }
    cin >> k;
}

class Solution
{
public:
    int subarraySum(vector<int> &nums, int k)
    {
        int slow = 0, fast = 1;
        int current_sum = nums[0];
        int ans = 0;
        while (slow < nums.size())
        {
            while (fast < nums.size() && current_sum < k)
            {
                current_sum += nums[fast];
                ++fast;
            }
            if (current_sum == k)
            {
                ++ans;
            }
            while (slow < fast && current_sum >= k)
            {
                current_sum -= nums[slow];
                ++slow;
            }
        }
        return ans;
    }
};

int main(int argc, char const *argv[])
{
    get_input();
    cout << Solution().subarraySum(nums, k);
    return 0;
}
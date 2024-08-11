// 给你一个整数数组 nums 和一个整数 k ，请你统计并返回 该数组中和为 k 的子数组的个数 。

// 子数组是数组中元素的连续非空序列。

// 示例 1：

// 输入：nums = [1,1,1], k = 2
// 输出：2

// 示例 2：

// 输入：nums = [1,2,3], k = 3
// 输出：2

// 提示：

//     1 <= nums.length <= 2 * 10^4
//     -1000 <= nums[i] <= 1000
//     -10^7 <= k <= 10^7

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
    int subarraySum(vector<int> &nums, int k)
    {
        int n = nums.size();
        vector<long long> presum(n);
        int sum = 0;
        for (int i = 0; i < n; ++i)
        {
            sum += nums[i];
            presum[i] = sum;
        }
        int answer = 0;
        for (int i = 0; i < n; ++i)
        {
            int current_sum = presum[i];
            if (current_sum == k)
            {
                answer += 1;
            }
            for (int j = 0; j < i; ++j)
            {
                if (current_sum - presum[j] == k)
                {
                    answer += 1;
                }
            }
        }
        return answer;
    }
};

int main(int argc, char const *argv[])
{
    int n = 0;
    cin >> n;
    vector<int> nums(n);
    for (int i = 0; i < n; ++i)
    {
        cin >> nums[i];
    }
    int k;
    cin >> k;
    cout << Solution().subarraySum(nums, k);
    return 0;
}
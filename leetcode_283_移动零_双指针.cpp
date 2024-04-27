// 给定一个数组 nums，编写一个函数将所有 0 移动到数组的末尾，同时保持非零元素的相对顺序。

// 请注意 ，必须在不复制数组的情况下原地对数组进行操作。

// 示例 1:

// 输入: nums = [0,1,0,3,12]
// 输出: [1,3,12,0,0]

// 示例 2:

// 输入: nums = [0]
// 输出: [0]

// 提示:

//     1 <= nums.length <= 104
//     -231 <= nums[i] <= 231 - 1

// 进阶：你能尽量减少完成的操作次数吗？

#include <iostream>
#include <vector>
#include <algorithm>
#include <stdio.h>

using namespace std;

vector<int> nums;

void get_input()
{
    int n = 0;
    cin >> n;
    nums.resize(n, 0);
    for (int i = 0; i < n; ++i)
    {
        cin >> nums[i];
    }
}
class Solution
{
public:
    void moveZeroes(vector<int> &nums)
    {
        int slow = 0, fast = 0;
        while (fast < nums.size())
        {
            if (0 == nums[fast])
            {
                ++fast;
                continue;
            }
            nums[slow] = nums[fast];
            ++slow;
            ++fast;
        }
        for (int i = slow; i < nums.size(); ++i)
        {
            nums[i] = 0;
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
    Solution().moveZeroes(nums);
    print_output(nums);
    return 0;
}
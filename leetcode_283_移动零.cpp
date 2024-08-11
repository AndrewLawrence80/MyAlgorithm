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
#include <deque>
#include <unordered_map>
#include <algorithm>
#include <string>

using namespace std;

class Solution
{
public:
    void moveZeroes(vector<int> &nums)
    {
        for (int i = 0; i < nums.size(); ++i)
        {
            if (nums[i] == 0)
            {
                for (int j = i + 1; j < nums.size(); ++j)
                {
                    if (nums[j] == 0)
                    {
                        continue;
                    }
                    int tmp = nums[i];
                    nums[i] = nums[j];
                    nums[j] = tmp;
                    break;
                }
            }
        }
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
    Solution().moveZeroes(nums);
    for (int i = 0; i < n; ++i)
    {
        cout << nums[i] << " ";
    }
    return 0;
}
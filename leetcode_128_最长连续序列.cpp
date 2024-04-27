// 给定一个未排序的整数数组 nums ，找出数字连续的最长序列（不要求序列元素在原数组中连续）的长度。

// 请你设计并实现时间复杂度为 O(n) 的算法解决此问题。

// 示例 1：

// 输入：nums = [100,4,200,1,3,2]
// 输出：4
// 解释：最长数字连续序列是 [1, 2, 3, 4]。它的长度为 4。

// 示例 2：

// 输入：nums = [0,3,7,2,5,8,4,6,0,1]
// 输出：9

#include <iostream>
#include <vector>
#include <unordered_map>
#include <stdio.h>

using namespace std;

vector<int> get_input()
{

    int n = 0;
    cin >> n;
    vector<int> nums(n, 0);
    for (int i = 0; i < n; i++)
    {
        cin >> nums[i];
    }
    return nums;
}

class Solution
{
public:
    int longestConsecutive(vector<int> &nums)
    {
        unordered_map<int, int> umap;
        for (int i = 0; i < nums.size(); ++i)
        {
            umap[nums[i]] += 1;
        }
        int maxlen = 0;
        for (int i = 0; i < nums.size(); ++i)
        {
            if (umap[nums[i] - 1])
            {
                continue;
            }
            else
            {
                int tmp_cnt = 0, current_num = nums[i];
                while (umap[current_num])
                {
                    ++tmp_cnt;
                    ++current_num;
                }
                if (tmp_cnt > maxlen)
                {
                    maxlen = tmp_cnt;
                }
            }
        }
        return maxlen;
    }
};

int main(int argc, char const *argv[])
{
    vector<int> nums = get_input();
    cout << Solution().longestConsecutive(nums);
    return 0;
}
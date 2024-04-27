// 给你四个整数数组 nums1、nums2、nums3 和 nums4 ，数组长度都是 n ，请你计算有多少个元组 (i, j, k, l) 能满足：

//     0 <= i, j, k, l < n
//     nums1[i] + nums2[j] + nums3[k] + nums4[l] == 0

// 示例 1：

// 输入：nums1 = [1,2], nums2 = [-2,-1], nums3 = [-1,2], nums4 = [0,2]
// 输出：2
// 解释：
// 两个元组如下：
// 1. (0, 0, 0, 1) -> nums1[0] + nums2[0] + nums3[0] + nums4[1] = 1 + (-2) + (-1) + 2 = 0
// 2. (1, 1, 0, 0) -> nums1[1] + nums2[1] + nums3[0] + nums4[0] = 2 + (-1) + (-1) + 0 = 0

// 示例 2：

// 输入：nums1 = [0], nums2 = [0], nums3 = [0], nums4 = [0]
// 输出：1

//   提示：

//     n == nums1.length
//     n == nums2.length
//     n == nums3.length
//     n == nums4.length
//     1 <= n <= 200
//     -2^28 <= nums1[i], nums2[i], nums3[i], nums4[i] <= 2^28

#include <iostream>
#include <stdio.h>
#include <vector>
#include <map>
#include <iterator>

using namespace std;

int nums[4][512] = {0};

int tmp[228 * 4 + 1] = {0};
void init_tmp()
{
    for (int i = -228 * 2; i <= 228 * 2; ++i)
    {
        tmp[i + 228 * 2] = i;
    }
}

int sum1[228 * 4 + 1] = {0};
int sum2[228 * 4 + 1] = {0};

int N = 0;
void get_input()
{
    scanf("%d", &N);
    for (int i = 0; i < 4; ++i)
    {
        for (int j = 0; j < N; ++j)
        {
            scanf("%d", &nums[i][j]);
        }
    }
}

int solve(vector<int> &num1, vector<int> &num2, vector<int> &num3, vector<int> &num4)
{
    // int n = num1.size();
    // for (int i = 0; i < n; ++i)
    // {
    //     for (int j = 0; j < n; ++j)
    //     {
    //         int tmp_sum = num1[i] + num2[j];
    //         sum1[tmp_sum + 228 * 2] += 1;
    //     }
    // }
    // for (int i = 0; i < n; ++i)
    // {
    //     for (int j = 0; j < n; ++j)
    //     {
    //         int tmp_sum = num3[i] + num4[j];
    //         sum2[tmp_sum + 228 * 2] += 1;
    //     }
    // }
    // int ans = 0;
    // for (int i = 0; i < 228 * 4 + 1; ++i)
    // {
    //     ans += sum1[i] * sum2[228 * 4 - i];
    // }
    // return ans;
    int n = num1.size();
    map<int, int> sum_map;
    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < n; ++j)
        {
            int tmp_sum = num3[i] + num4[j];
            sum_map[tmp_sum] += 1;
        }
    }
    int ans = 0;
    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < n; ++j)
        {
            int tmp_sum = num1[i] + num2[j];
            if (sum_map.find(0 - tmp_sum) != sum_map.end())
            {
                ans += sum_map[0 - tmp_sum];
            }
        }
    }
    return ans;
}

int main(int argc, char const *argv[])
{
    get_input();
    init_tmp();
    vector<int> v1(nums[0], nums[0] + N);
    vector<int> v2(nums[1], nums[1] + N);
    vector<int> v3(nums[2], nums[2] + N);
    vector<int> v4(nums[3], nums[3] + N);
    printf("%d", solve(v1, v2, v3, v4));
    return 0;
}

// 给定整数数组 nums 和整数 k，请返回数组中第 k 个最大的元素。

// 请注意，你需要找的是数组排序后的第 k 个最大的元素，而不是第 k 个不同的元素。

// 你必须设计并实现时间复杂度为 O(n) 的算法解决此问题。

// 示例 1:

// 输入: [3,2,1,5,6,4], k = 2
// 输出: 5

// 示例 2:

// 输入: [3,2,3,1,2,4,5,5,6], k = 4
// 输出: 4

// 提示：

//     1 <= k <= nums.length <= 105
//     -104 <= nums[i] <= 104

#include <iostream>
#include <vector>
#include <deque>
#include <stack>
#include <unordered_map>
#include <algorithm>
#include <string>
#include <queue>

using namespace std;

class Solution
{
public:
    int partition(vector<int> &nums, int k, int left, int right)
    {
        if (right - left + 1 == k)
        {
            return nums[right];
        }
        int pivot = nums[left];
        int i = left + 1, j = right;
        while (true)
        {
            while (nums[i] >= pivot && i <= right)
                i++;
            while (nums[j] < pivot && j >= left)
                j--;
            if (i > j)
                break;
            swap(nums[i], nums[j]);
        }
        swap(nums[left], nums[j]);
        if (j - left + 1 == k)
        {
            return nums[j];
        }
        else if (j - left + 1 < k)
        {
            return partition(nums, k, j + 1, right);
        }
        else
        {
            return partition(nums, k, left, j - 1);
        }
        return -1;
    }
    int findKthLargest(vector<int> &nums, int k)
    {
        int left = 0, right = nums.size() - 1;
        return partition(nums, k, left, right);
    }
};

int main(int argc, char const *argv[])
{
    int n = 0;
    cin >> n;
    priority_queue<int, vector<int>, less<int>> pq;
    for (int i = 0; i < n; i++)
    {
        int tmp = 0;
        cin >> tmp;
        pq.push(tmp);
    }
    int k = 0;
    cin >> k;
    int answer = 0;
    for (int i = 0; i < k; ++i)
    {
        answer = pq.top();
        pq.pop();
    }
    cout << answer << endl;
    return 0;
}
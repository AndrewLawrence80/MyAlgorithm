// 给你一个整数数组 nums ，数组中的元素 互不相同 。返回该数组所有可能的
// 子集
// （幂集）。

// 解集 不能 包含重复的子集。你可以按 任意顺序 返回解集。

// 示例 1：

// 输入：nums = [1,2,3]
// 输出：[[],[1],[2],[1,2],[3],[1,3],[2,3],[1,2,3]]

// 示例 2：

// 输入：nums = [0]
// 输出：[[],[0]]

// 提示：

//     1 <= nums.length <= 10
//     -10 <= nums[i] <= 10
//     nums 中的所有元素 互不相同

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
    vector<vector<int>> answer;
    void dfs(vector<int> tset, int size, int idx, vector<int> &nums)
    {
        if (tset.size() == size)
        {
            answer.push_back(tset);
            return;
        }
        for (int i = idx; i < nums.size(); ++i)
        {
            tset.push_back(nums[i]);
            dfs(tset, size, i + 1, nums);
            tset.pop_back();
        }
    }
    vector<vector<int>> subsets(vector<int> &nums)
    {
        for (int sz = 0; sz <= nums.size(); ++sz)
        {
            dfs({}, sz, 0, nums);
        }
        return answer;
    }
};

int main(int argc, char const *argv[])
{
    int n = 0;
    cin >> n;
    vector<int> nums(n, 0);
    for (int i = 0; i < n; ++i)
    {
        cin >> nums[i];
    }
    vector<vector<int>> answer = Solution().subsets(nums);
    for (auto v : answer)
    {
        for (auto x : v)
        {
            cout << x << " ";
        }
        cout << endl;
    }
    return 0;
}
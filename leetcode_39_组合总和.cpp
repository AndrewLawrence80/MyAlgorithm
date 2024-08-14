// 给你一个 无重复元素 的整数数组 candidates 和一个目标整数 target ，找出 candidates 中可以使数字和为目标数 target 的 所有 不同组合 ，并以列表形式返回。你可以按 任意顺序 返回这些组合。

// candidates 中的 同一个 数字可以 无限制重复被选取 。如果至少一个数字的被选数量不同，则两种组合是不同的。

// 对于给定的输入，保证和为 target 的不同组合数少于 150 个。

// 示例 1：

// 输入：candidates = [2,3,6,7], target = 7
// 输出：[[2,2,3],[7]]
// 解释：
// 2 和 3 可以形成一组候选，2 + 2 + 3 = 7 。注意 2 可以使用多次。
// 7 也是一个候选， 7 = 7 。
// 仅有这两种组合。

// 示例 2：

// 输入: candidates = [2,3,5], target = 8
// 输出: [[2,2,2,2],[2,3,3],[3,5]]

// 示例 3：

// 输入: candidates = [2], target = 1
// 输出: []

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
    void dfs(vector<int> &candidates, vector<int> t_set, int index, int t_target)
    {
        if (t_target == 0)
        {
            answer.push_back(t_set);
            return;
        }
        if (t_target < candidates[index])
        {
            return;
        }
        for (int i = index; i < candidates.size(); ++i)
        {
            if (t_target >= candidates[i])
            {
                t_set.push_back(candidates[i]);
                dfs(candidates, t_set, i, t_target - candidates[i]);
                t_set.pop_back();
            }
        }
    }
    vector<vector<int>> combinationSum(vector<int> &candidates, int target)
    {
        sort(candidates.begin(), candidates.end());
        dfs(candidates, {}, 0, target);
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
    int target = 0;
    cin >> target;
    vector<vector<int>> answer = Solution().combinationSum(nums, target);
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
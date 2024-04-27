// 给定一个不含重复数字的数组 nums ，返回其 所有可能的全排列 。你可以 按任意顺序 返回答案。

// 示例 1：

// 输入：nums = [1,2,3]
// 输出：[[1,2,3],[1,3,2],[2,1,3],[2,3,1],[3,1,2],[3,2,1]]

// 示例 2：

// 输入：nums = [0,1]
// 输出：[[0,1],[1,0]]

// 示例 3：

// 输入：nums = [1]
// 输出：[[1]]

// 提示：

//     1 <= nums.length <= 6
//     -10 <= nums[i] <= 10
//     nums 中的所有整数 互不相同

#include <iostream>
#include <vector>
#include <stdio.h>

using namespace std;

int N;
vector<int> nums;

class Solution
{
public:
    vector<int> temp;
    vector<bool> visited;
    vector<vector<int>> ans;
    void dfs(vector<int> &nums)
    {
        if (temp.size() == nums.size())
        {
            ans.push_back(vector<int>(temp));
        }
        for (int i = 0; i < nums.size(); ++i)
        {
            if (!visited[i])
            {
                temp.push_back(nums[i]);
                visited[i] = true;
                dfs(nums);
                visited[i] = false;
                temp.pop_back();
            }
        }
    }
    vector<vector<int>> permute(vector<int> &nums)
    {
        visited = vector<bool>(nums.size(), false);
        dfs(nums);
        return ans;
    }
};

void get_input()
{
    cin >> N;
    for (int i = 0; i < N; ++i)
    {
        int tmp = 0;
        cin >> tmp;
        nums.push_back(tmp);
    }
}
int main(int argc, char const *argv[])
{
    get_input();
    vector<vector<int>> ans = Solution().permute(nums);
    for (int i = 0; i < ans.size(); ++i)
    {
        for (int j = 0; j < ans[i].size(); ++j)
        {
            cout << ans[i][j];
        }
        cout << endl;
    }
    return 0;
}

// 二叉树中的 路径 被定义为一条节点序列，序列中每对相邻节点之间都存在一条边。同一个节点在一条路径序列中 至多出现一次 。该路径 至少包含一个 节点，且不一定经过根节点。

// 路径和 是路径中各节点值的总和。

// 给你一个二叉树的根节点 root ，返回其 最大路径和 。

// 示例 1：

// 输入：root = [1,2,3]
// 输出：6
// 解释：最优路径是 2 -> 1 -> 3 ，路径和为 2 + 1 + 3 = 6

// 示例 2：

// 输入：root = [-10,9,20,null,null,15,7]
// 输出：42
// 解释：最优路径是 15 -> 20 -> 7 ，路径和为 15 + 20 + 7 = 42

// 提示：

//     树中节点数目范围是 [1, 3 * 104]
//     -1000 <= Node.val <= 1000

#include <iostream>
#include <vector>
#include <deque>
#include <stack>
#include <unordered_map>
#include <algorithm>
#include <string>
#include <cstring>

using namespace std;

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

TreeNode *arrayToTree(vector<string> &nums, int idx)
{
    if (idx >= nums.size())
    {
        return nullptr;
    }
    if (nums[idx] == "null")
    {
        return nullptr;
    }
    TreeNode *node = new TreeNode(stoi(nums[idx]));
    node->left = arrayToTree(nums, 2 * idx + 1);
    node->right = arrayToTree(nums, 2 * idx + 2);
    return node;
}

class Solution
{
public:
    int maxS;
    int dfs(TreeNode *current_root)
    {
        if (current_root == nullptr)
        {
            return 0;
        }
        int left_max = max(0, dfs(current_root->left));
        int right_max = max(0, dfs(current_root->right));
        maxS = max(maxS, current_root->val + left_max + right_max);
        return current_root->val + max(left_max, right_max);
    }
    int maxPathSum(TreeNode *root)
    {
        maxS = INT32_MIN;
        dfs(root);
        return maxS;
    }
};

int main(int argc, char const *argv[])
{
    char a[1024] = {0};
    cin.getline(a, 1024);
    vector<string> sv;
    char *ta = strtok(a, " ");
    while (ta != nullptr)
    {
        sv.push_back(string(ta));
        ta = strtok(nullptr, " ");
    }
    TreeNode *root = arrayToTree(sv, 0);
    cout << Solution().maxPathSum(root) << endl;
    return 0;
}
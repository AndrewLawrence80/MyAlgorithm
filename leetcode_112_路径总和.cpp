// 给你二叉树的根节点 root 和一个表示目标和的整数 targetSum 。判断该树中是否存在 根节点到叶子节点 的路径，这条路径上所有节点值相加等于目标和 targetSum 。如果存在，返回 true ；否则，返回 false 。

// 叶子节点 是指没有子节点的节点。

// 示例 1：

// 输入：root = [5,4,8,11,null,13,4,7,2,null,null,null,1], targetSum = 22
// 输出：true
// 解释：等于目标和的根节点到叶节点路径如上图所示。

// 示例 2：

// 输入：root = [1,2,3], targetSum = 5
// 输出：false
// 解释：树中存在两条根节点到叶子节点的路径：
// (1 --> 2): 和为 3
// (1 --> 3): 和为 4
// 不存在 sum = 5 的根节点到叶子节点的路径。

// 示例 3：

// 输入：root = [], targetSum = 0
// 输出：false
// 解释：由于树是空的，所以不存在根节点到叶子节点的路径。

// 提示：

//     树中节点的数目在范围 [0, 5000] 内
//     -1000 <= Node.val <= 1000
//     -1000 <= targetSum <= 1000

#include <iostream>
#include <vector>
#include <deque>
#include <stack>
#include <unordered_map>
#include <algorithm>
#include <string>
#include <cstring>

using namespace std;

const int sz = 1024;

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

TreeNode *buildTree(vector<string> &sv, int idx)
{
    if (idx == sv.size() - 1)
    {
        cout << endl;
    }
    if (idx >= sv.size())
    {
        return nullptr;
    }
    if (sv[idx] == "null")
    {
        return nullptr;
    }
    TreeNode *current_root = new TreeNode(stoi(sv[idx]));
    current_root->left = buildTree(sv, idx * 2 + 1);
    current_root->right = buildTree(sv, idx * 2 + 2);
    return current_root;
}

class Solution
{
public:
    bool dfs(TreeNode *currentRoot, int currentSum, int targetSum)
    {
        if (currentRoot == nullptr)
        {
            return false;
        }
        currentSum += currentRoot->val;
        if (currentRoot->left == nullptr && currentRoot->right == nullptr)
        {
            return currentSum == targetSum;
        }
        return dfs(currentRoot->left, currentSum, targetSum) || dfs(currentRoot->right, currentSum, targetSum);
    }
    bool hasPathSum(TreeNode *root, int targetSum)
    {
        return dfs(root, 0, targetSum);
    }
};

int main(int argc, char const *argv[])
{
    char cstr[sz] = {0};
    cin.getline(cstr, sz);
    vector<string> sv;
    char *cs = strtok(cstr, " ");
    while (cs)
    {
        sv.push_back(string(cs));
        cs = strtok(nullptr, " ");
    }
    int target = 0;
    cin >> target;
    TreeNode *root = buildTree(sv, 0);
    cout << Solution().hasPathSum(root, target) << endl;
    return 0;
}
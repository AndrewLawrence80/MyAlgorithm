// 给定一个二叉树 root ，返回其最大深度。

// 二叉树的 最大深度 是指从根节点到最远叶子节点的最长路径上的节点数。

// 示例 1：

// 输入：root = [3,9,20,null,null,15,7]
// 输出：3

// 示例 2：

// 输入：root = [1,null,2]
// 输出：2

// 提示：

//     树中节点的数量在 [0, 104] 区间内。
//     -100 <= Node.val <= 100

// Definition for a binary tree node.

#include <iostream>
#include <vector>
#include <deque>
#include <unordered_map>
#include <algorithm>
#include <string>

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

TreeNode *arrayToTree(vector<int> array, int idx)
{
    if (array[idx] == -1)
    {
        return nullptr;
    }
    TreeNode *node = new TreeNode(array[idx]);
    int left = 2 * idx + 1;
    int right = 2 * idx + 2;
    if (left < array.size())
    {
        node->left = arrayToTree(array, left);
    }
    if (right < array.size())
    {
        node->right = arrayToTree(array, right);
    }
    return node;
}

class Solution
{
public:
    int getDepth(TreeNode *current_root)
    {
        if (current_root == nullptr)
        {
            return 0;
        }
        return 1 + max(getDepth(current_root->left), getDepth(current_root->right));
    }
    int maxDepth(TreeNode *root)
    {
        return getDepth(root);
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
    TreeNode *root = arrayToTree(nums, 0);
    cout << Solution().maxDepth(root);
    return 0;
}

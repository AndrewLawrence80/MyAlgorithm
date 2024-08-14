// 给定一个二叉搜索树的根节点 root ，和一个整数 k ，请你设计一个算法查找其中第 k 小的元素（从 1 开始计数）。

// 示例 1：

// 输入：root = [3,1,4,null,2], k = 1
// 输出：1

// 示例 2：

// 输入：root = [5,3,6,2,4,null,null,1], k = 3
// 输出：3

// 提示：

//     树中的节点数为 n 。
//     1 <= k <= n <= 10^4
//     0 <= Node.val <= 10^4

#include <iostream>
#include <vector>
#include <deque>
#include <unordered_map>
#include <algorithm>
#include <string>

using namespace std;

// Definition for a binary tree node.
struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

TreeNode *arrayToTree(vector<int> nums, int idx)
{
    if (nums[idx] == -1)
    {
        return nullptr;
    }
    int left = 2 * idx + 1, right = 2 * idx + 2;
    TreeNode *node = new TreeNode(nums[idx]);
    if (left < nums.size())
    {
        node->left = arrayToTree(nums, left);
    }
    if (right < nums.size())
    {
        node->right = arrayToTree(nums, right);
    }
    return node;
}

class Solution
{
public:
    int kthMin = INT32_MAX;
    int get_size(TreeNode *current_root)
    {
        if (current_root == nullptr)
        {
            return 0;
        }
        return 1 + get_size(current_root->left) + get_size(current_root->right);
    }
    int kthSmallest(TreeNode *root, int k)
    {
        int size = get_size(root);
        int left_size = get_size(root->left);
        if (k <= left_size)
        {
            return kthSmallest(root->left, k);
        }
        else if (k == left_size + 1)
        {
            return root->val;
        }
        else
        {
            // 关键
            return kthSmallest(root->right, k - left_size - 1);
        }
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
    int k = 0;
    cin >> k;
    cout << Solution().kthSmallest(root, k);
    return 0;
}
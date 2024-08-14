// 给你一个二叉树的根节点 root ，判断其是否是一个有效的二叉搜索树。

// 有效 二叉搜索树定义如下：

//     节点的左
//     子树
//     只包含 小于 当前节点的数。
//     节点的右子树只包含 大于 当前节点的数。
//     所有左子树和右子树自身必须也是二叉搜索树。

// 示例 1：

// 输入：root = [2,1,3]
// 输出：true

// 示例 2：

// 输入：root = [5,1,4,null,null,3,6]
// 输出：false
// 解释：根节点的值是 5 ，但是右子节点的值是 4 。

// 树中节点数目范围在[1, 104] 内
// -231 <= Node.val <= 231 - 1

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
    TreeNode *node = new TreeNode(nums[idx]);
    int left = idx * 2 + 1, right = idx * 2 + 2;
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
    vector<int> inorderSeq;
    void inorderTraverse(TreeNode *current_root)
    {
        if (current_root == nullptr)
        {
            return;
        }
        inorderTraverse(current_root->left);
        inorderSeq.push_back(current_root->val);
        inorderTraverse(current_root->right);
    }
    bool isValidBST(TreeNode *root)
    {
        inorderTraverse(root);
        for (int i = 0; i < inorderSeq.size() - 1; ++i)
        {
            if (!(inorderSeq[i] < inorderSeq[i + 1]))
            {
                return false;
            }
        }
        return true;
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
    cout << Solution().isValidBST(root);
    return 0;
}
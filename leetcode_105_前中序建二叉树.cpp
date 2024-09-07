// 给定两个整数数组 preorder 和 inorder ，其中 preorder 是二叉树的先序遍历， inorder 是同一棵树的中序遍历，请构造二叉树并返回其根节点。

// 示例 1:

// 输入: preorder = [3,9,20,15,7], inorder = [9,3,15,20,7]
// 输出: [3,9,20,null,null,15,7]

// 示例 2:

// 输入: preorder = [-1], inorder = [-1]
// 输出: [-1]

// 提示:

//     1 <= preorder.length <= 3000
//     inorder.length == preorder.length
//     -3000 <= preorder[i], inorder[i] <= 3000
//     preorder 和 inorder 均 无重复 元素
//     inorder 均出现在 preorder
//     preorder 保证 为二叉树的前序遍历序列
//     inorder 保证 为二叉树的中序遍历序列

#include <iostream>
#include <vector>
#include <deque>
#include <stack>
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

class Solution
{
public:
    vector<int> preorder, inorder;
    TreeNode *build(int pre_left, int pre_right, int in_left, int in_right)
    {
        if (pre_left > pre_right)
        {
            return nullptr;
        }
        int current_root_val = preorder[pre_left];
        int current_in_idx = find(inorder.begin(), inorder.end(), current_root_val) - inorder.begin();
        int left_offset = current_in_idx - in_left;
        TreeNode *current_root = new TreeNode(current_root_val);
        current_root->left = build(pre_left + 1, pre_left + left_offset, in_left, current_in_idx - 1);
        current_root->right = build(pre_left + left_offset + 1, pre_right, current_in_idx + 1, in_right);
        return current_root;
    }
    TreeNode *buildTree(vector<int> &preorder, vector<int> &inorder)
    {
        this->preorder = vector<int>(preorder);
        this->inorder = vector<int>(inorder);
        return build(0, preorder.size() - 1, 0, inorder.size() - 1);
    }
};

int main(int argc, char const *argv[])
{
    unsigned long n = 0;
    cin >> n;
    vector<int> preorder(n), inorder(n);
    for (size_t i = 0; i < n; i++)
    {
        cin >> preorder[i];
    }
    for (size_t i = 0; i < n; i++)
    {
        cin >> inorder[i];
    }
    TreeNode *root = Solution().buildTree(preorder, inorder);
    return 0;
}
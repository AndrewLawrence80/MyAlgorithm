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
#include <algorithm>
#include <stdio.h>

using namespace std;
class TreeNode
{
public:
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
    TreeNode *build(vector<int> &preorder, vector<int> &inorder, int pre_left, int pre_right, int in_left, int in_right)
    {
        if (pre_left>pre_right){
            return nullptr;
        }
        // if (pre_right - pre_left == 0)
        // {
        //     return new TreeNode(preorder[pre_left]);
        // }
        int val_current_root = preorder[pre_left];
        TreeNode *current_root = new TreeNode(val_current_root);
        int in_mid = in_left;
        for (int i = in_left; i <= in_right; ++i)
        {
            if (inorder[i] == val_current_root)
            {
                in_mid = i;
            }
        }
        int left_length = in_mid - in_left;
        int right_length = in_right - in_mid;
        current_root->left = build(preorder, inorder, pre_left + 1, pre_left + left_length, in_left, in_mid);
        current_root->right = build(preorder, inorder, pre_left + 1 + left_length, pre_right, in_mid + 1, in_right);
        return current_root;
    }
    TreeNode *buildTree(vector<int> &preorder, vector<int> &inorder)
    {
        return build(preorder, inorder, 0, preorder.size() - 1, 0, inorder.size() - 1);
    }
};
int main(int argc, char const *argv[])
{
    int num_node = 0;
    cin >> num_node;
    vector<int> preorder(num_node, 0);
    vector<int> inorder(num_node, 0);
    for (int i = 0; i < num_node; ++i)
    {
        cin >> preorder[i];
    }
    for (int i = 0; i < num_node; ++i)
    {
        cin >> inorder[i];
    }
    TreeNode *root = Solution().buildTree(preorder, inorder);
    return 0;
}
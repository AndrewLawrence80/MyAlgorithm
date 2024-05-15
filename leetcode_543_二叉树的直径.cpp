// 给你一棵二叉树的根节点，返回该树的 直径 。

// 二叉树的 直径 是指树中任意两个节点之间最长路径的 长度 。这条路径可能经过也可能不经过根节点 root 。

// 两节点之间路径的 长度 由它们之间边数表示。

// 示例 1：

// 输入：root = [1,2,3,4,5]
// 输出：3
// 解释：3 ，取路径 [4,2,1,3] 或 [5,2,1,3] 的长度。

// 示例 2：

// 输入：root = [1,2]
// 输出：1

// 提示：

//     树中节点数目在范围 [1, 104] 内
//     -100 <= Node.val <= 100

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

TreeNode *buildBinaryTree(vector<int> &array, int idx)
{
    if (idx >= array.size() || array[idx] == -1)
    {
        return nullptr;
    }
    else
    {
        TreeNode *current_root = new TreeNode(array[idx]);
        current_root->left = buildBinaryTree(array, 2 * idx + 1);
        current_root->right = buildBinaryTree(array, 2 * idx + 2);
        return current_root;
    }
}

class Solution
{
public:
    int max_diameter;
    int get_max_depth(TreeNode *current_root)
    {
        if (current_root == nullptr)
        {
            return 0;
        }
        else
        {
            return 1 + max(get_max_depth(current_root->left), get_max_depth(current_root->right));
        }
    }
    void get_max_diameter(TreeNode *current_root)
    {
        if (current_root == nullptr)
        {
            return;
        }
        int current_diameter = get_max_depth(current_root->left) + get_max_depth(current_root->right);
        if (current_diameter > max_diameter)
        {
            max_diameter = current_diameter;
        }
        get_max_diameter(current_root->left);
        get_max_diameter(current_root->right);
    }
    int diameterOfBinaryTree(TreeNode *root)
    {
        get_max_diameter(root);
        return max_diameter;
    }
    Solution() : max_diameter(0) {}
};

int main(int argc, char const *argv[])
{
    vector<int> array;
    int x;
    while (cin >> x)
    {
        array.push_back(x);
    }
    TreeNode *root = buildBinaryTree(array, 0);
    cout << Solution().diameterOfBinaryTree(root);
    return 0;
}

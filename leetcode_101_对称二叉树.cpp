// 给你一个二叉树的根节点 root ， 检查它是否轴对称。

// 示例 1：

// 输入：root = [1,2,2,3,4,4,3]
// 输出：true

// 示例 2：

// 输入：root = [1,2,2,null,3,null,3]
// 输出：false

// 提示：

//     树中节点数目在范围 [1, 1000] 内
//     -100 <= Node.val <= 100

#include <iostream>
#include <vector>
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
    bool dfs_symmetric(TreeNode *left, TreeNode *right)
    {
        if (!left && !right)
        {
            return true;
        }
        else if (left && right)
        {
            if (left->val != right->val)
            {
                return false;
            }
            else
            {
                return dfs_symmetric(left->left, right->right) && dfs_symmetric(left->right, right->left);
            }
        }
        else
        {
            return false;
        }
    }
    bool isSymmetric(TreeNode *root)
    {
        if (!root)
        {
            return true;
        }
        else
        {
            return dfs_symmetric(root->left, root->right);
        }
    }
};

int main(int argc, char const *argv[])
{
    vector<int> array;
    int x = 0;
    while (cin >> x)
    {
        array.push_back(x);
    }
    TreeNode *root = buildBinaryTree(array, 0);
    cout << Solution().isSymmetric(root);
    return 0;
}
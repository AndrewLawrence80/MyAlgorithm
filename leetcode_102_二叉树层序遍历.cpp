// 给你二叉树的根节点 root ，返回其节点值的 层序遍历 。 （即逐层地，从左到右访问所有节点）。

// 示例 1：

// 输入：root = [3,9,20,null,null,15,7]
// 输出：[[3],[9,20],[15,7]]

// 示例 2：

// 输入：root = [1]
// 输出：[[1]]

// 示例 3：

// 输入：root = []
// 输出：[]

// 提示：

//     树中节点数目在范围 [0, 2000] 内
//     -1000 <= Node.val <= 1000

#include <iostream>
#include <vector>
#include <deque>
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

TreeNode *buildBinaryTree(vector<int> array, int idx)
{
    if (idx >= array.size() || array[idx] == -1)
    {
        return nullptr;
    }
    TreeNode *current_root = new TreeNode(array[idx]);
    current_root->left = buildBinaryTree(array, 2 * idx + 1);
    current_root->right = buildBinaryTree(array, 2 * idx + 2);
    return current_root;
}

class Solution
{
public:
    vector<vector<int>> levelOrder(TreeNode *root)
    {
        vector<vector<int>> ans;
        deque<TreeNode *> queue;
        if (root != nullptr)
        {
            queue.push_back(root);
        }
        while (!queue.empty())
        {
            vector<int> temp;
            int current_layer_size = queue.size();
            for (int i = 0; i < current_layer_size; ++i)
            {
                TreeNode *head = queue.front();
                queue.pop_front();
                temp.push_back(head->val);
                if (head->left != nullptr)
                {
                    queue.push_back(head->left);
                }
                if (head->right != nullptr)
                {
                    queue.push_back(head->right);
                }
            }
            ans.push_back(temp);
        }
        return ans;
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
    return 0;
}
// 给定两个整数数组 inorder 和 postorder ，其中 inorder 是二叉树的中序遍历， postorder 是同一棵树的后序遍历，请你构造并返回这颗 二叉树 。

// 示例 1:

// 输入：inorder = [9,3,15,20,7], postorder = [9,15,7,20,3]
// 输出：[3,9,20,null,null,15,7]

// 示例 2:

// 输入：inorder = [-1], postorder = [-1]
// 输出：[-1]

// 提示:

//     1 <= inorder.length <= 3000
//     postorder.length == inorder.length
//     -3000 <= inorder[i], postorder[i] <= 3000
//     inorder 和 postorder 都由 不同 的值组成
//     postorder 中每一个值都在 inorder 中
//     inorder 保证是树的中序遍历
//     postorder 保证是树的后序遍历

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
    vector<int> inorder, postorder;
    TreeNode *build(int post_left, int post_right, int in_left, int in_right)
    {
        if (post_left > post_right)
        {
            return nullptr;
        }
        int current_val = postorder[post_right];
        TreeNode *current_root = new TreeNode(current_val);
        int current_in_idx = find(inorder.begin(), inorder.end(), current_val) - inorder.begin();
        int right_offset = in_right - current_in_idx;
        current_root->left = build(post_left, post_right - right_offset - 1, in_left, current_in_idx - 1);
        current_root->right = build(post_right - right_offset, post_right - 1, current_in_idx + 1, in_right);
        return current_root;
    }
    TreeNode *buildTree(vector<int> &inorder, vector<int> &postorder)
    {
        this->inorder = vector<int>(inorder);
        this->postorder = vector<int>(postorder);
        return build(0, postorder.size() - 1, 0, inorder.size() - 1);
    }
};

int main(int argc, char const *argv[])
{
    int n = 0;
    cin >> n;
    vector<int> inorder(n);
    vector<int> postorder(n);
    for (int i = 0; i < n; i++)
    {
        cin >> inorder[i];
    }
    for (int i = 0; i < n; i++)
    {
        cin >> postorder[i];
    }
    TreeNode *root = Solution().buildTree(inorder, postorder);
    return 0;
}
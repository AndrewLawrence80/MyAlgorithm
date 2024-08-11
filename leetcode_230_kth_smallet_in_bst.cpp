// Given the root of a binary search tree, and an integer k, return the kth smallest value (1-indexed) of all the values of the nodes in the tree.

// Example 1:

// Input: root = [3,1,4,null,2], k = 1
// Output: 1

// Example 2:

// Input: root = [5,3,6,2,4,null,null,1], k = 3
// Output: 3

// Constraints:

//     The number of nodes in the tree is n.
//     1 <= k <= n <= 104
//     0 <= Node.val <= 104

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

TreeNode *arrayToTree(vector<int> &v, unsigned idx)
{
    if (v[idx] == -1)
    {
        return nullptr;
    }
    TreeNode *current = new TreeNode();
    current->val = v[idx];
    unsigned left = 2 * idx + 1;
    unsigned right = 2 * idx + 2;
    if (left < v.size())
    {
        current->left = arrayToTree(v, left);
    }
    if (right < v.size())
    {
        current->right = arrayToTree(v, right);
    }
    return current;
}

class Solution
{
public:
    int kthSmallest(TreeNode *root, int k)
    {
    }
};

int main(int argc, char const *argv[])
{

    return 0;
}

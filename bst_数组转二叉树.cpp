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
    if (idx >= array.size())
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

void inorder_traverse(TreeNode* current_root){
    if (current_root==nullptr){
        return;
    }
    inorder_traverse(current_root->left);
    
    cout << current_root->val << " ";
    inorder_traverse(current_root->right);
}

int main(int argc, char const *argv[])
{
    int t_array[7] = {1, 2, 2, -1, 3, -1, 3};
    vector<int> array(t_array, t_array + 7);
    TreeNode *root = buildBinaryTree(array, 0);
    inorder_traverse(root);
    return 0;
}
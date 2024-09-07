// 给定一个二叉树的根节点 root ，和一个整数 targetSum ，求该二叉树里节点值之和等于 targetSum 的 路径 的数目。

// 路径 不需要从根节点开始，也不需要在叶子节点结束，但是路径方向必须是向下的（只能从父节点到子节点）。

// 示例 1：

// 输入：root = [10,5,-3,3,2,null,11,3,-2,null,1], targetSum = 8
// 输出：3
// 解释：和等于 8 的路径有 3 条，如图所示。

// 示例 2：

// 输入：root = [5,4,8,11,null,13,4,7,2,null,null,5,1], targetSum = 22
// 输出：3

// 提示:

//     二叉树的节点个数的范围是 [0,1000]
//     -109 <= Node.val <= 109
//     -1000 <= targetSum <= 1000

#include <iostream>
#include <vector>
#include <deque>
#include <stack>
#include <unordered_map>
#include <algorithm>
#include <string>
#include <cstring>

using namespace std;

const int scanLen = 1024;

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
    unordered_map<long long, int> exists;
    int pathCnt;
    void dfs(TreeNode *currentRoot, long long currentSum, long long targetSum)
    {
        if (currentRoot == nullptr)
        {
            return;
        }
        currentSum += currentRoot->val;
        pathCnt += exists[currentSum - targetSum];
        exists[currentSum] += 1;
        dfs(currentRoot->left, currentSum, targetSum);
        dfs(currentRoot->right, currentSum, targetSum);
        exists[currentSum] -= 1;
    }
    int pathSum(TreeNode *root, long long targetSum)
    {
        pathCnt = 0;
        exists[0] = 1;
        dfs(root, 0, targetSum);
        return pathCnt;
    }
};

TreeNode *arrayToTree(vector<string> &sv, int idx)
{
    if (idx >= sv.size())
    {
        return nullptr;
    }
    if (sv[idx] == "null")
    {
        return nullptr;
    }
    TreeNode *currentRoot = new TreeNode(stoi(sv[idx]));
    currentRoot->left = arrayToTree(sv, idx * 2 + 1);
    currentRoot->right = arrayToTree(sv, idx * 2 + 2);
    return currentRoot;
}

int main(int argc, char const *argv[])
{
    char in[scanLen] = {0};
    cin.getline(in, scanLen);
    vector<string> sv;
    char *t = strtok(in, ",");
    while (t)
    {
        sv.push_back(string(t));
        t = strtok(nullptr, ",");
    }
    int targetSum = 0;
    cin >> targetSum;
    TreeNode *root = arrayToTree(sv, 0);
    cout << Solution().pathSum(root, targetSum);
    return 0;
}
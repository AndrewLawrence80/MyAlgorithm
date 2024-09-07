// 给你二叉树的根节点 root 和一个整数目标和 targetSum ，找出所有 从根节点到叶子节点 路径总和等于给定目标和的路径。

// 叶子节点 是指没有子节点的节点。

// 示例 1：

// 输入：root = [5,4,8,11,null,13,4,7,2,null,null,5,1], targetSum = 22
// 输出：[[5,4,11,2],[5,8,4,5]]

// 示例 2：

// 输入：root = [1,2,3], targetSum = 5
// 输出：[]

// 示例 3：

// 输入：root = [1,2], targetSum = 0
// 输出：[]

// 提示：

//     树中节点总数在范围 [0, 5000] 内
//     -1000 <= Node.val <= 1000
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
    vector<vector<int>> answer;
    void dfs(TreeNode *currentRoot, int currentSum, int targetSum, vector<int> path)
    {
        if (currentRoot == nullptr)
        {
            return;
        }
        currentSum += currentRoot->val;
        path.push_back(currentRoot->val);
        if (currentRoot->left == nullptr && currentRoot->right == nullptr)
        {
            if (currentSum == targetSum)
            {
                answer.push_back(path);
            }
        }
        dfs(currentRoot->left, currentSum, targetSum, path);
        dfs(currentRoot->right, currentSum, targetSum, path);
    }
    vector<vector<int>> pathSum(TreeNode *root, int targetSum)
    {
        if (root == nullptr)
        {
            return answer;
        }
        vector<int> path;
        dfs(root, 0, targetSum, path);
        return answer;
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
    vector<vector<int>> answer = Solution().pathSum(root, targetSum);
    for (vector<int> xv : answer)
    {
        for (int x : xv)
        {
            cout << x << " ";
        }
        cout << endl;
    }
    return 0;
}
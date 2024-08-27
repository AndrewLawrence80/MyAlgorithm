// 编写一个高效的算法来搜索 m x n 矩阵 matrix 中的一个目标值 target 。该矩阵具有以下特性：

//     每行的元素从左到右升序排列。
//     每列的元素从上到下升序排列。

// 示例 1：

// 输入：matrix = [[1,4,7,11,15],[2,5,8,12,19],[3,6,9,16,22],[10,13,14,17,24],[18,21,23,26,30]], target = 5
// 输出：true

// 示例 2：

// 输入：matrix = [[1,4,7,11,15],[2,5,8,12,19],[3,6,9,16,22],[10,13,14,17,24],[18,21,23,26,30]], target = 20
// 输出：false

// 提示：

//     m == matrix.length
//     n == matrix[i].length
//     1 <= n, m <= 300
//     -109 <= matrix[i][j] <= 109
//     每行的所有元素从左到右升序排列
//     每列的所有元素从上到下升序排列
//     -109 <= target <= 109

// 5 5
// 1 4 7 11 15
// 2 5 8 12 19
// 3 6 9 16 22
// 10 13 14 17 24
// 18 21 23 26 30

#include <iostream>
#include <vector>
#include <deque>
#include <stack>
#include <unordered_map>
#include <algorithm>
#include <string>

using namespace std;

class Solution
{
public:
    bool searchMatrix(vector<vector<int>> &matrix, int target)
    {
        int m = matrix.size(), n = matrix[0].size();
        int current_row = 0, current_col = n - 1;
        while (current_row < m && current_col >= 0)
        {
            if (matrix[current_row][current_col] == target)
                return true;
            else if (matrix[current_row][current_col] < target)
                current_row++;
            else
                current_col--;
        }
        return false;
    }
};

int main(int argc, char const *argv[])
{
    int m = 0, n = 0;
    cin >> m >> n;
    vector<vector<int>> matrix(m, vector<int>(n));
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> matrix[i][j];
        }
    }
    int target = 0;
    cin >> target;
    cout << Solution().searchMatrix(matrix, target);
    return 0;
}
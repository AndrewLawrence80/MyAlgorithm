// 给你一个 m 行 n 列的矩阵 matrix ，请按照 顺时针螺旋顺序 ，返回矩阵中的所有元素。

// 示例 1：

// 输入：matrix = [[1,2,3],[4,5,6],[7,8,9]]
// 输出：[1,2,3,6,9,8,7,4,5]

// 示例 2：

// 输入：matrix = [[1,2,3,4],[5,6,7,8],[9,10,11,12]]
// 输出：[1,2,3,4,8,12,11,10,9,5,6,7]

// 提示：

//     m == matrix.length
//     n == matrix[i].length
//     1 <= m, n <= 10
//     -100 <= matrix[i][j] <= 100

#include <iostream>
#include <vector>
#include <stdio.h>

using namespace std;

vector<vector<int>> matrix;

void get_input()
{
    int M = 0, N = 0;
    cin >> M >> N;
    matrix.resize(M, vector<int>(N, 0));
    for (size_t i = 0; i < M; i++)
    {
        for (size_t j = 0; j < N; j++)
        {
            cin >> matrix[i][j];
        }
    }
}

class Solution
{
public:
    vector<int> spiralOrder(vector<vector<int>> &matrix)
    {
        int M = matrix.size(), N = matrix[0].size();
        int max_no = M * N;
        int current_no = 0;
        int i = 0, j = 0, left_bound = -1, right_bound = N, upper_bound = 0, lower_bound = M;
        int direction = 0; // 0 右 1 下 2 左 3 上
        vector<int> ans;
        while (current_no < max_no)
        {
            int current_x=matrix[i][j];
            ans.push_back(current_x);
            ++current_no;
            if (direction == 0)
            {
                ++j;
                if (j == right_bound)
                {
                    --j;
                    ++i;
                    direction = 1;
                    --right_bound;
                    continue;
                }
            }
            if (direction == 1)
            {
                ++i;
                if (i == lower_bound)
                {
                    --i;
                    --j;
                    direction = 2;
                    --lower_bound;
                    continue;
                }
            }
            if (direction == 2)
            {
                --j;
                if (j == left_bound)
                {
                    ++j;
                    --i;
                    direction = 3;
                    ++left_bound;
                    continue;
                }
            }
            if (direction == 3)
            {
                --i;
                if (i == upper_bound)
                {
                    ++i;
                    ++j;
                    direction = 0;
                    ++upper_bound;
                    continue;
                }
            }
        }
        return ans;
    }
};

void print_output(vector<int> &ans)
{
    for (size_t i = 0; i < ans.size(); i++)
    {
        cout << ans[i] << " ";
    }
}

int main(int argc, char const *argv[])
{
    get_input();
    vector<int> ans = Solution().spiralOrder(matrix);
    print_output(ans);
    return 0;
}
// 给定一个 n × n 的二维矩阵 matrix 表示一个图像。请你将图像顺时针旋转 90 度。

// 你必须在 原地 旋转图像，这意味着你需要直接修改输入的二维矩阵。请不要 使用另一个矩阵来旋转图像。

// 示例 1：

// 输入：matrix = [[1,2,3],[4,5,6],[7,8,9]]
// 输出：[[7,4,1],[8,5,2],[9,6,3]]

// 示例 2：

// 输入：matrix = [[5,1,9,11],[2,4,8,10],[13,3,6,7],[15,14,12,16]]
// 输出：[[15,13,2,5],[14,3,4,1],[12,6,8,9],[16,7,10,11]]

// 提示：

//     n == matrix.length == matrix[i].length
//     1 <= n <= 20
//     -1000 <= matrix[i][j] <= 1000

// 旋转：沿副对角线翻转之后上下翻转

// 旋转前
// 5   1   9   11
// 2   4   8   10
// 13  3   6   7
// 15  14  12  16
// 旋转后
// 15  13  2   5
// 14  3   4   1
// 12  6   8   9
// 16  7   10  11

#include <iostream>
#include <vector>
#include <stdio.h>

using namespace std;

vector<vector<int>> matrix;

void get_input()
{
    int N = 0;
    cin >> N;
    matrix.resize(N, vector<int>(N, 0));
    for (size_t i = 0; i < N; i++)
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
    void rotate(vector<vector<int>> &matrix)
    {
        int N = matrix.size();
        // 翻转操作副对角线上三角坐标对应关系
        // N=4: (0,0)<->(3,3) (0,1)<->(2,3) (0,3)<->(1,4) (2,0)<->(3,1)
        // 原坐标值(x,y)->(x+delta,y+delta)
        // delta为坐标距离本行对角线的距离
        // 沿副对角线翻转
        int right_bound = N - 1;
        for (size_t i = 0; i < N; i++)
        {
            for (size_t j = 0; j < right_bound; j++)
            {
                int delta = right_bound - j;
                int origin_x = i, origin_y = j;
                int mirror_x = i + delta, mirror_y = j + delta;
                int temp = matrix[origin_x][origin_y];
                matrix[origin_x][origin_y] = matrix[mirror_x][mirror_y];
                matrix[mirror_x][mirror_y] = temp;
            }
            --right_bound;
        }
        // 上下翻转
        for (size_t i = 0; i < N / 2; i++)
        {
            for (size_t j = 0; j < N; j++)
            {
                int temp = matrix[i][j];
                matrix[i][j] = matrix[N - 1 - i][j];
                matrix[N - 1 - i][j] = temp;
            }
        }
    }
};

void print_output()
{
    for (size_t i = 0; i < matrix.size(); i++)
    {
        for (size_t j = 0; j < matrix[i].size(); j++)
        {
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }
}

int main(int argc, char const *argv[])
{
    get_input();
    Solution().rotate(matrix);
    print_output();
    return 0;
}
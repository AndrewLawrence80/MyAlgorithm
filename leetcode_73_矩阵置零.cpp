// 给定一个 m x n 的矩阵，如果一个元素为 0 ，则将其所在行和列的所有元素都设为 0 。请使用 原地 算法。

// 示例 1：

// 输入：matrix = [[1,1,1],[1,0,1],[1,1,1]]
// 输出：[[1,0,1],[0,0,0],[1,0,1]]

// 示例 2：

// 输入：matrix = [[0,1,2,0],[3,4,5,2],[1,3,1,5]]
// 输出：[[0,0,0,0],[0,4,5,0],[0,3,1,0]]

#include <iostream>
#include <vector>
#include <unordered_set>
#include <stdio.h>

using namespace std;

vector<vector<int>> matrix;
int M = 0, N = 0;

class Solution
{
public:
    void setZeroes(vector<vector<int>> &matrix)
    {
        int M = matrix.size(), N = matrix[0].size();
        unordered_set<int> zero_row_no;
        unordered_set<int> zero_col_no;
        for (size_t i = 0; i < M; i++)
        {
            for (size_t j = 0; j < N; j++)
            {
                if (0 == matrix[i][j])
                {
                    zero_row_no.insert(i);
                    zero_col_no.insert(j);
                }
            }
        }
        for (unordered_set<int>::iterator iter = zero_row_no.begin(); iter != zero_row_no.end(); ++iter)
        {
            int row_no = *iter;
            for (size_t i = 0; i < N; i++)
            {
                matrix[row_no][i] = 0;
            }
        }
        for (unordered_set<int>::iterator iter = zero_col_no.begin(); iter != zero_col_no.end(); ++iter)
        {
            int col_no = *iter;
            for (size_t i = 0; i < M; i++)
            {
                matrix[i][col_no] = 0;
            }
        }
    }
};

void get_input()
{

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

void print_output()
{
    for (size_t i = 0; i < M; i++)
    {
        for (size_t j = 0; j < N; j++)
        {
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }
}

int main(int argc, char const *argv[])
{
    get_input();
    Solution().setZeroes(matrix);
    print_output();
    return 0;
}
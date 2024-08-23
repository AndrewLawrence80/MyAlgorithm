#include <iostream>
#include <vector>
#include <deque>
#include <stack>
#include <unordered_map>
#include <algorithm>
#include <string>

using namespace std;

int main(int argc, char const *argv[])
{
    int n = 0;
    cin >> n;
    vector<vector<int>> grid(n, vector<int>(n));
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> grid[i][j];
        }
    }
    int maxValue = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; ++j)
        {
            int temp = grid[i][j];
            if (i - 1 >= 0)
            {
                temp += grid[i - 1][j];
            }
            if (i + 1 < n)
            {
                temp += grid[i + 1][j];
            }
            if (j - 1 >= 0)
            {
                temp += grid[i][j - 1];
            }
            if (j + 1 < n)
            {
                temp += grid[i][j + 1];
            }
            if (temp > maxValue)
            {
                maxValue = temp;
            }
        }
    }
    cout << maxValue;
    return 0;
}
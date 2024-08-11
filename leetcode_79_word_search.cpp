// Given an m x n grid of characters board and a string word, return true if word exists in the grid.

// The word can be constructed from letters of sequentially adjacent cells, where adjacent cells are horizontally or vertically neighboring. The same letter cell may not be used more than once.

// Example 1:

// Input: board = [["A","B","C","E"],["S","F","C","S"],["A","D","E","E"]], word = "ABCCED"
// Output: true

// Example 2:

// Input: board = [["A","B","C","E"],["S","F","C","S"],["A","D","E","E"]], word = "SEE"
// Output: true

// Example 3:

// Input: board = [["A","B","C","E"],["S","F","C","S"],["A","D","E","E"]], word = "ABCB"
// Output: false

// Given an m x n grid of characters board and a string word, return true if word exists in the grid.

// m == board.length
// n = board[i].length
// 1 <= m, n <= 6
// 1 <= word.length <= 15
// board and word consists of only lowercase and uppercase English letters.

#include <iostream>
#include <vector>
#include <deque>
#include <unordered_map>
#include <algorithm>
#include <string>

using namespace std;

class Solution
{
public:
    int m, n;
    bool found = false;
    vector<vector<bool>> visited;
    void dfs(vector<vector<char>> &board, int x, int y, int index, string &word)
    {
        if (index == word.size())
        {
            found = true;
            return;
        }
        if (x==1&&y==3){
            cout << endl;
        }
        if (x < 0 || x >= m || y < 0 || y >= n || visited[x][y] || board[x][y] != word[index])
        {
            return;
        }
        visited[x][y] = true;
        dfs(board, x - 1, y, index + 1, word);
        dfs(board, x + 1, y, index + 1, word);
        dfs(board, x, y - 1, index + 1, word);
        dfs(board, x, y + 1, index + 1, word);
        visited[x][y] = false;
    }
    bool exist(vector<vector<char>> &board, string word)
    {
        m = board.size();
        n = board[0].size();
        for (int i = 0; i < m; ++i)
        {
            visited.push_back(vector<bool>(n, false));
        }
        for (int i = 0; i < m; ++i)
        {
            for (int j = 0; j < n; ++j)
            {
                dfs(board, i, j, 0, word);
                if (found)
                {
                    return true;
                }
            }
        }
        return false;
    }
};

int main(int argc, char const *argv[])
{
    vector<vector<char>> board;
    unsigned m = 0, n = 0;
    cin >> m >> n;
    for (unsigned i = 0; i < m; ++i)
    {
        vector<char> tmp(n, 'a');
        board.push_back(tmp);
    }
    for (unsigned i = 0; i < m; ++i)
    {
        for (unsigned j = 0; j < n; ++j)
        {
            cin >> board[i][j];
        }
    }
    string word;
    cin >> word;
    cout << Solution().exist(board, word);
    return 0;
}

#include <iostream>
#include <string>
#include <stdio.h>
#include <vector>

using namespace std;

class Solution
{
public:
    vector<vector<int>> memo;
    int dfs(string word1, string word2, int i, int j)
    {
        if (i == -1 && j != -1)
        {
            return j + 1;
        }
        else if (i != -1 && j == -1)
        {
            return i + 1;
        }
        else if (i == -1 && j == -1)
        {
            return 0;
        }
        else
        {
            if (memo[i][j] != -1)
            {
                return memo[i][j];
            }
            else
            {
                if (word1[i] == word2[j])
                {
                    memo[i][j] = dfs(word1, word2, i - 1, j - 1);
                    return memo[i][j];
                }
                else
                {
                    memo[i][j] = 1 + min(min(dfs(word1, word2, i - 1, j - 1), dfs(word1, word2, i - 1, j)), dfs(word1, word2, i, j - 1));
                    return memo[i][j];
                }
            }
        }
    }
    int minDistance(string word1, string word2)
    {
        memo = vector<vector<int>>(word1.size(), vector<int>(word2.size(), -1));
        return dfs(word1, word2, word1.size() - 1, word2.size() - 1);
    }
};

int main(int argc, char const *argv[])
{
    string word1, word2;
    cin >> word1 >> word2;
    cout << Solution().minDistance(word1, word2);
    return 0;
}
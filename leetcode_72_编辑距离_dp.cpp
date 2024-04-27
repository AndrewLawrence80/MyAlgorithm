#include <iostream>
#include <string>
#include <stdio.h>
#include <vector>

using namespace std;

class Solution
{
public:
    int minDistance(string word1, string word2)
    {
        vector<vector<int>> dp(word1.size() + 1, vector<int>(word2.size() + 1, -1));
        for (int i = 0; i < word1.size() + 1; ++i)
        {
            dp[i][0] = i;
        }
        for (int j = 0; j < word2.size() + 1; ++j)
        {
            dp[0][j] = j;
        }
        for (int i = 1; i < word1.size() + 1; ++i)
        {
            for (int j = 1; j < word2.size() + 1; ++j)
            {
                if (word1[i - 1] == word2[j - 1])
                {
                    dp[i][j] = dp[i - 1][j - 1];
                }
                else
                {
                    dp[i][j] = 1 + min(min(dp[i - 1][j - 1], dp[i - 1][j]), dp[i][j - 1]);
                }
            }
        }
        return dp[word1.size()][word2.size()];
    }
};

int main(int argc, char const *argv[])
{
    string word1, word2;
    cin >> word1 >> word2;
    cout << Solution().minDistance(word1, word2);
    return 0;
}
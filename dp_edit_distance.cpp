// 给你两个单词 word1 和 word2， 请返回将 word1 转换成 word2 所使用的最少操作数  。

// 你可以对一个单词进行如下三种操作：

//     插入一个字符
//     删除一个字符
//     替换一个字符

// 示例 1：

// 输入：word1 = "horse", word2 = "ros"
// 输出：3
// 解释：
// horse -> rorse (将 'h' 替换为 'r')
// rorse -> rose (删除 'r')
// rose -> ros (删除 'e')

// 示例 2：

// 输入：word1 = "intention", word2 = "execution"
// 输出：5
// 解释：
// intention -> inention (删除 't')
// inention -> enention (将 'i' 替换为 'e')
// enention -> exention (将 'n' 替换为 'x')
// exention -> exection (将 'n' 替换为 'c')
// exection -> execution (插入 'u')

// 提示：

//     0 <= word1.length, word2.length <= 500
//     word1 和 word2 由小写英文字母组成

#include <iostream>
#include <stdio.h>
#include <string>
#include <algorithm>

using namespace std;

string str1, str2;

void solve()
{
    int dp[501][501] = {0};
    for (int i = 0; i < str2.size() + 1; ++i)
    {
        dp[0][i] = i;
    }
    for (int i = 0; i < str1.size() + 1; ++i)
    {
        dp[i][0] = i;
    }
    for (int i = 1; i < str1.size() + 1; ++i)
    {
        for (int j = 1; j < str2.size() + 1; ++j)
        {
            if (str1[i - 1] == str2[j - 1])
            {
                dp[i][j] = dp[i - 1][j - 1];
            }
            else
            {
                dp[i][j] = 1 + min(min(dp[i][j - 1], dp[i - 1][j]), dp[i - 1][j - 1]);
            }
        }
    }
    printf("%d", dp[str1.size()][str2.size()]);
}

int main(int argc, char const *argv[])
{
    cin >> str1 >> str2;
    solve();
    return 0;
}

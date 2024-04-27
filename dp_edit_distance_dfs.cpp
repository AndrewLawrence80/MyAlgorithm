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

string str1;
string str2;

int dfs(int i, int j)
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
        if (str1[i] == str2[j])
        {
            return dfs(i - 1, j - 1);
        }
        else
        {
            return 1 + min(min(dfs(i - 1, j), dfs(i, j - 1)), dfs(i - 1, j - 1));
        }
    }
}

void solve()
{
    printf("%d", dfs(str1.size() - 1, str2.size() - 1));
}

int main(int argc, char const *argv[])
{
    cin >> str1 >> str2;
    solve();
    return 0;
}
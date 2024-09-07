// 给你一个字符串 s，找到 s 中最长的
// 回文
// 子串
// 。

// 示例 1：

// 输入：s = "babad"
// 输出："bab"
// 解释："aba" 同样是符合题意的答案。

// 示例 2：

// 输入：s = "cbbd"
// 输出："bb"

// 提示：

//     1 <= s.length <= 1000
//     s 仅由数字和英文字母组成

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
    string longestPalindrome(string s)
    {
        int n = s.size();
        int maxLen = 0;
        string longestParlin;
        for (int center = 1; center < n - 1; ++center)
        {
            int left = center - 1;
            while (left >= 0 && s[left] == s[center])
            {
                --left;
            }
            int right = center + 1;
            while (right < n && s[right] == s[center])
            {
                ++right;
            }
            while (left >= 0 && right < n && s[left] == s[right])
            {
                --left;
                ++right;
            }
            int tLen = right - left - 1;
            if (tLen > maxLen)
            {
                maxLen = tLen;
                longestParlin = s.substr(left + 1, maxLen);
            }
        }
        return longestParlin;
    }
};

int main(int argc, char const *argv[])
{
    string s;
    cin >> s;
    cout << Solution().longestPalindrome(s) << endl;
    return 0;
}
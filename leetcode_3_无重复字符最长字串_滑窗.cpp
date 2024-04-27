// 给定一个字符串 s ，请你找出其中不含有重复字符的 最长
// 子串
//  的长度。

// 示例 1:

// 输入: s = "abcabcbb"
// 输出: 3
// 解释: 因为无重复字符的最长子串是 "abc"，所以其长度为 3。

// 示例 2:

// 输入: s = "bbbbb"
// 输出: 1
// 解释: 因为无重复字符的最长子串是 "b"，所以其长度为 1。

// 示例 3:

// 输入: s = "pwwkew"
// 输出: 3
// 解释: 因为无重复字符的最长子串是 "wke"，所以其长度为 3。
//      请注意，你的答案必须是 子串 的长度，"pwke" 是一个子序列，不是子串。

// 提示：

//     0 <= s.length <= 5 * 104
//     s 由英文字母、数字、符号和空格组成

#include <iostream>
#include <string>
#include <vector>
#include <stdio.h>
#include <string.h>

using namespace std;

class Solution
{
public:
    int lengthOfLongestSubstring(string s)
    {
        int exist[129] = {0};
        int left = -1, right = -1;
        int max_lengh = 0;
        while (right < (int)s.size() - 1)
        {
            ++right;
            exist[s[right]] += 1;
            while (exist[s[right]] != 1)
            {
                ++left;
                exist[s[left]] -= 1;
            }
            int current_length = right - left;
            if (current_length > max_lengh)
            {
                max_lengh = current_length;
            }
        }
        return max_lengh;
    }
};

int main(int argc, char const *argv[])
{
    string s;
    cin >> s;
    cout << Solution().lengthOfLongestSubstring(s);
    return 0;
}
// 给定两个字符串 s 和 p，找到 s 中所有 p 的 异位词 的子串，返回这些子串的起始索引。不考虑答案输出的顺序。

// 异位词 指由相同字母重排列形成的字符串（包括相同的字符串）。

// 示例 1:

// 输入: s = "cbaebabacd", p = "abc"
// 输出: [0,6]
// 解释:
// 起始索引等于 0 的子串是 "cba", 它是 "abc" 的异位词。
// 起始索引等于 6 的子串是 "bac", 它是 "abc" 的异位词。

//  示例 2:

// 输入: s = "abab", p = "ab"
// 输出: [0,1,2]
// 解释:
// 起始索引等于 0 的子串是 "ab", 它是 "ab" 的异位词。
// 起始索引等于 1 的子串是 "ba", 它是 "ab" 的异位词。
// 起始索引等于 2 的子串是 "ab", 它是 "ab" 的异位词。

// 提示:

//     1 <= s.length, p.length <= 3 * 104
//     s 和 p 仅包含小写字母

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <unordered_map>

using namespace std;

class Solution
{
public:
    vector<int> findAnagrams(string s, string p)
    {
        int len_s = s.length(), len_p = p.length();
        unordered_map<char, int> map_p;
        for (char c : p)
        {
            map_p[c]++;
        }
        int left = 0, right = 0, count = 0;
        vector<int> result;
        while (right < len_s)
        {
            if (map_p.find(s[right]) != map_p.end())
            {
                map_p[s[right]]--;
                if (map_p[s[right]] == 0)
                {
                    count++;
                }
            }
            right++;
            while (count == map_p.size())
            {
                if (right - left == len_p)
                {
                    result.push_back(left);
                }
                if (map_p.find(s[left]) != map_p.end())
                {
                    map_p[s[left]]++;
                    if (map_p[s[left]] > 0)
                    {
                        count--;
                    }
                }
                left++;
            }
        }
        return result;
    }
};

int main()
{
    string s, p;
    cin >> s >> p;
    vector<int> answer = Solution().findAnagrams(s, p);
    for (int i : answer)
    {
        cout << i << " ";
    }
    cout << endl;
    return 0;
}
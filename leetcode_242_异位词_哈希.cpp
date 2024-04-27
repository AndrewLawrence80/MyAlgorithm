// 给定两个字符串 s 和 t ，编写一个函数来判断 t 是否是 s 的字母异位词。

// 注意：若 s 和 t 中每个字符出现的次数都相同，则称 s 和 t 互为字母异位词。

 

// 示例 1:

// 输入: s = "anagram", t = "nagaram"
// 输出: true

// 示例 2:

// 输入: s = "rat", t = "car"
// 输出: false

 

// 提示:

//     1 <= s.length, t.length <= 5 * 104
//     s 和 t 仅包含小写字母

 

// 进阶: 如果输入字符串包含 unicode 字符怎么办？你能否调整你的解法来应对这种情况？


#include <iostream>
#include <string>
#include <stdio.h>

using namespace std;

string str1, str2;

bool solve(string &str1, string &str2)
{
    int cnt_1[128] = {0}, cnt_2[128] = {0};
    for (int i = 0; i < str1.size(); ++i)
    {
        cnt_1[str1[i]] += 1;
    }
    for (int i = 0; i < str2.size(); ++i)
    {
        cnt_2[str2[i]] += 1;
    }
    for (int i = 0; i < 128; ++i)
    {
        if (cnt_1[i] != cnt_2[i])
        {
            return false;
        }
    }
    return true;
}
int main(int argc, char const *argv[])
{
    cin >> str1 >> str2;
    cout << solve(str1, str2);
    return 0;
}
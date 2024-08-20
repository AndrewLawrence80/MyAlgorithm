// 给你一个字符串 s 。我们要把这个字符串划分为尽可能多的片段，同一字母最多出现在一个片段中。

// 注意，划分结果需要满足：将所有划分结果按顺序连接，得到的字符串仍然是 s 。

// 返回一个表示每个字符串片段的长度的列表。

// 示例 1：

// 输入：s = "ababcbacadefegdehijhklij"
// 输出：[9,7,8]
// 解释：
// 划分结果为 "ababcbaca"、"defegde"、"hijhklij" 。
// 每个字母最多出现在一个片段中。
// 像 "ababcbacadefegde", "hijhklij" 这样的划分是错误的，因为划分的片段数较少。

// 示例 2：

// 输入：s = "eccbbbbdec"
// 输出：[10]

// 提示：

//     1 <= s.length <= 500
//     s 仅由小写英文字母组成

#include <iostream>
#include <vector>
#include <deque>
#include <stack>
#include <unordered_map>
#include <algorithm>
#include <string>
#include <utility>
#include <iterator>

using namespace std;

class Interval
{
public:
    char c;
    int left;
    int right;
    Interval() {}
    Interval(char c, int left, int right)
    {
        this->c = c;
        this->left = left;
        this->right = right;
    }
};

class IntervalCmp
{
public:
    bool operator()(const Interval &a, const Interval &b)
    {
        return a.left < b.left;
    }
};

class Solution
{
public:
    vector<int> partitionLabels(string s)
    {
        unordered_map<char, Interval> mp;
        for (int i = 0; i < s.size(); ++i)
        {
            if (mp.count(s[i]) == 0)
            {
                mp[s[i]] = Interval(s[i], i, i);
            }
            else
            {
                mp[s[i]].right = i;
            }
        }
        vector<Interval> interval_array;
        for (unordered_map<char, Interval>::iterator it = mp.begin(); it != mp.end(); ++it)
        {
            interval_array.push_back((*it).second);
        }
        sort(interval_array.begin(), interval_array.end(), IntervalCmp());

        vector<int> answer;
        int start = interval_array[0].left, end = interval_array[0].right;

        for (int i = 0; i < interval_array.size(); ++i)
        {
            if (interval_array[i].left <= end)
            {
                end = max(end, interval_array[i].right);
            }
            else
            {
                answer.push_back(end - start + 1);
                start = interval_array[i].left;
                end = interval_array[i].right;
            }
        }
        answer.push_back(end - start + 1);
        return answer;
    }
};

int main(int argc, char const *argv[])
{
    string s;
    cin >> s;
    vector<int> ans = Solution().partitionLabels(s);
    for (int x : ans)
    {
        cout << x << endl;
    }
    return 0;
}
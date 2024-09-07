// 给定一个只包括 '('，')'，'{'，'}'，'['，']' 的字符串 s ，判断字符串是否有效。

// 有效字符串需满足：

//     左括号必须用相同类型的右括号闭合。
//     左括号必须以正确的顺序闭合。
//     每个右括号都有一个对应的相同类型的左括号。

// 示例 1：

// 输入：s = "()"

// 输出：true

// 示例 2：

// 输入：s = "()[]{}"

// 输出：true

// 示例 3：

// 输入：s = "(]"

// 输出：false

// 示例 4：

// 输入：s = "([])"

// 输出：true

// 提示：

//     1 <= s.length <= 104
//     s 仅由括号 '()[]{}' 组成

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
    unordered_map<char, char> bracePair;

    void initBracePair()
    {
        bracePair[')'] = '(';
        bracePair[']'] = '[';
        bracePair['}'] = '{';
    }
    
    bool isValid(string s)
    {
        initBracePair();
        stack<char> st;
        for (char c : s)
        {
            if (st.empty())
            {
                st.push(c);
            }
            else
            {
                char t = st.top();
                if (t == bracePair[c])
                {
                    st.pop();
                }
                else
                {
                    st.push(c);
                }
            }
        }
        return st.empty();
    }
};

int main(int argc, char const *argv[])
{
    string s;
    cin >> s;
    cout << Solution().isValid(s) << endl;
    return 0;
}
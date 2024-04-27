// 给你一个字符串数组，请你将 字母异位词 组合在一起。可以按任意顺序返回结果列表。

// 字母异位词 是由重新排列源单词的所有字母得到的一个新单词。

// 示例 1:

// 输入: strs = ["eat", "tea", "tan", "ate", "nat", "bat"]
// 输出: [["bat"],["nat","tan"],["ate","eat","tea"]]

// 示例 2:

// 输入: strs = [""]
// 输出: [[""]]

// 示例 3:

// 输入: strs = ["a"]
// 输出: [["a"]]

// 提示：

//     1 <= strs.length <= 104
//     0 <= strs[i].length <= 100
//     strs[i] 仅包含小写字母

#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>
#include <algorithm>
#include <stdio.h>

using namespace std;

vector<string> strs;

void get_input()
{
    int N = 0;
    cin >> N;
    strs.resize(N);
    for (int i = 0; i < N; ++i)
    {
        cin >> strs[i];
    }
}

class Solution
{
public:
    vector<vector<string>> groupAnagrams(vector<string> &strs)
    {
        int n = strs.size();
        unordered_map<string, vector<string>> umap;
        for (int i = 0; i < n; ++i)
        {
            string tmp(strs[i]);
            sort(tmp.begin(), tmp.end());
            umap[tmp].push_back(strs[i]);
        }
        vector<vector<string>> ans;
        for (auto iter : umap)
        {
            ans.push_back(iter.second);
        }
        return ans;
    }
};

void print_output(vector<vector<string>> ans)
{
    for (int i = 0; i < ans.size(); ++i)
    {
        for (int j = 0; j < ans[i].size() - 1; ++j)
        {
            cout << ans[i][j] << " ";
        }
        cout << ans[i][ans[i].size() - 1];
        cout << endl;
    }
}

int main(int argc, char const *argv[])
{
    get_input();
    vector<vector<string>> ans = Solution().groupAnagrams(strs);
    print_output(ans);
    return 0;
}
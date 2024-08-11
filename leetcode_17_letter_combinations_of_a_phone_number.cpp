// Given a string containing digits from 2-9 inclusive, return all possible letter combinations that the number could represent. Return the answer in any order.

// A mapping of digits to letters (just like on the telephone buttons) is given below. Note that 1 does not map to any letters.

// 2:"abc"
// 3:"def"
// 4:"ghi"
// 5:"jkl"
// 6:"mno"
// 7:"pqrs"
// 8:"tuv"
// 9:"wxyz"

#include <iostream>
#include <vector>
#include <unordered_map>
#include <string>

using namespace std;

string input;

class Solution
{
public:
    unordered_map<char, string> mp{{'2', "abc"}, {'3', "def"}, {'4', "ghi"}, {'5', "jkl"}, {'6', "mno"}, {'7', "pqrs"}, {'8', "tuv"}, {'9', "wxyz"}};
    vector<string> results;
    string global_digits;
    void backtrack(int digit_idx, string current_s)
    {
        if (digit_idx == global_digits.length())
        {
            if (current_s.length() > 0)
            {
                results.push_back(current_s);
            }
            return;
        }
        string alphabet = mp[global_digits[digit_idx]];
        for (int i = 0; i < alphabet.length(); ++i)
        {
            backtrack(digit_idx + 1, current_s + alphabet[i]);
        }
    }

    vector<string> letterCombinations(string digits)
    {
        global_digits = digits;
        backtrack(0, "");
        return results;
    }
};

int main(int argc, char const *argv[])
{
    cin >> input;
    vector<string> results = Solution().letterCombinations(input);
    for (string s : results)
    {
        cout << s;
    }
    return 0;
}

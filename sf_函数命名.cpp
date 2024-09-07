// given a list of function name, convert camel-cased style name to snake-style function name, if the function name is not camel cased, outut 'indistinct'

// 6
// MyLastName
// sampleFunc
// inputSampleTestTwo
// indistince_Sample
// another__sample
// another_sample_

#include <iostream>
#include <vector>
#include <deque>
#include <stack>
#include <unordered_map>
#include <algorithm>
#include <string>
#include <cstring>

using namespace std;

class Solution
{
public:
    vector<string> convert(vector<string> &names)
    {
        vector<string> answer;
        for (string s : names)
        {
            answer.push_back(toSnakeCase(s));
        }
        return answer;
    }
    string toSnakeCase(string s)
    {
        if (!islower(s[0]))
        {
            return "indistinct";
        }
        string t;
        for (int i = 0; i < s.size(); ++i)
        {
            char c = s[i];
            if (!(isalpha(c) || c == '_'))
            {
                return "indistinct";
            }
            if (isupper(c))
            {
                t += '_';
                t += tolower(c);
            }
            else if (c == '_')
            {
                if (i >= s.size() || !islower(s[i + 1]))
                {
                    return "indistinct";
                }
                else
                {
                    t += c;
                }
            }
            else if (islower(c))
            {
                t += c;
            }
            else{
                return "indistinct";
            }
        }
        return t;
    }
};

int main(int argc, char const *argv[])
{
    int n = 0;
    cin >> n;
    vector<string> names(n);
    for (int i = 0; i < n; i++)
    {
        cin >> names[i];
    }
    vector<string> converted = Solution().convert(names);
    for (string s : converted)
    {
        cout << s << endl;
    }
    return 0;
}
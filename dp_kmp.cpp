#include <iostream>
#include <vector>
#include <deque>
#include <unordered_map>
#include <algorithm>
#include <string>

using namespace std;

class KMP
{
public:
    vector<int> next;
    void buildNext(string pattern)
    {
        int m = pattern.size();
        next.resize(m + 1);
        next[0] = -1;
        int k = -1;
        for (int q = 1; q < m; ++q)
        {
            while (k >= 0 && pattern[k] != pattern[q - 1])
                k = next[k];
            k++;
            next[q] = k;
        }
    }
    bool searchPattern(string text, string pattern)
    {
        buildNext(pattern);
        int n = text.size();
        int m = pattern.size();
        int i = 0, j = 0;
        while (i < n && j < m)
        {
            if (j == -1 || text[i] == pattern[j])
            {
                i++;
                j++;
            }
            else
                j = next[j];
        }
        return j == m;
    }
};

int main(int argc, char const *argv[])
{
    string s1, s2;
    cin >> s1 >> s2;
    cout << KMP().searchPattern(s1, s2);
    return 0;
}
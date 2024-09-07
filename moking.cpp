#include <iostream>
#include <vector>
#include <deque>
#include <stack>
#include <unordered_map>
#include <algorithm>
#include <string>

using namespace std;

int main(int argc, char const *argv[])
{
    int n = 0;
    cin >> n;
    vector<long> a(n), b(n);
    for (int i = 0; i < n; ++i)
    {
        cin >> a[i];
    }
    for (int i = 0; i < n; ++i)
    {
        cin >> b[i];
    }
    vector<int> dp(n, 1);
    int maxLen = 0;
    for (int i = 1; i < n; ++i)
    {
        if (a[i] - a[i - 1] == b[i] - b[i - 1])
        {
            dp[i] = dp[i - 1] + 1;
        }
        maxLen = max(dp[i], maxLen);
    }
    cout << maxLen << endl;
    return 0;
}
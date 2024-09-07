// 双端最长上升子序列

#include <iostream>
#include <vector>
#include <deque>
#include <stack>
#include <unordered_map>
#include <algorithm>
#include <string>

using namespace std;

// vector<int> LIS_left(vector<int> &a)
// {
//     vector<int> dp(a.size(), 1);
//     vector<int> pre(a.size(), -1);
//     for (int i = 1; i < a.size(); ++i)
//     {
//         for (int j = 0; j < i; ++j)
//         {
//             if (a[i] > a[j] && dp[i] < dp[j] + 1)
//             {
//                 dp[i] = dp[j] + 1;
//                 pre[i] = j;
//             }
//         }
//     }
//     return dp;
// }
// vector<int> LIS_right(vector<int> &a)
// {
//     vector<int> dp(a.size(), 1);
//     vector<int> pre(a.size(), -1);
//     for (int i = a.size() - 2; i >= 0; --i)
//     {
//         for (int j = a.size() - 1; j > i; --j)
//         {
//             if (a[i] > a[j] && dp[i] < dp[j] + 1)
//             {
//                 dp[i] = dp[j] + 1;
//                 pre[i] = j;
//             }
//         }
//     }
//     return dp;
// }

vector<int> LIS_left(vector<int> &a)
{
    vector<int> dp(a.size(), 1);
    vector<int> lis;
    for (int i = 0; i < a.size(); ++i)
    {

    }
    return dp;
}
vector<int> LIS_right(vector<int> &a)
{

}

int main(int argc, char const *argv[])
{
    int n = 0;
    cin >> n;
    vector<int> a(n, 0);
    for (int i = 0; i < n; ++i)
    {
        cin >> a[i];
    }
    vector<int> lisLeft = LIS_left(a);
    vector<int> lisRight = LIS_right(a);
    int maxLen = 0;
    for (int i = 0; i < n; ++i)
    {
        if (lisLeft[i] != 1 && lisRight[i] != 1)
        {
            int tLen = lisLeft[i] + lisRight[i] - 1;
            if (tLen > maxLen)
            {
                maxLen = tLen;
            }
        }
    }
    cout << maxLen << endl;
    return 0;
}
// 求长度为n的排列p中满足p_i+p_j=i+j的个数(i<j)
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
    vector<int> p(n, 0);
    unordered_map<int, vector<int>> exists;
    for (int i = 0; i < n; ++i)
    {
        int t = 0;
        cin >> t;
        p[i] = t;
        exists[t - (i + 1)].push_back(i);
    }
    int cnt = 0;
    for (int j = 0; j < n; ++j)
    {
        int target = j + 1 - p[j];
        vector<int> &tv = exists[target];
        for (int k = 0; k < tv.size(); ++k)
        {
            if (tv[k] < j)
            {
                ++cnt;
            }
        }
    }
    cout << cnt << endl;
    return 0;
}
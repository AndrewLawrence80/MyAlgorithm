#include <iostream>
#include <vector>
#include <deque>
#include <stack>
#include <unordered_map>
#include <algorithm>
#include <string>
#include <utility>

using namespace std;

pair<int, int> maxContinuousSum(vector<int> &a)
{
    int n = a.size();
    int maxSum = INT32_MIN;
    int sum = 0;
    int start = 0;
    int end = 0;
    int tempStart = 0;
    for (int i = 0; i < n; i++)
    {
        sum += a[i];
        if (sum > maxSum)
        {
            maxSum = sum;
            start = tempStart;
            end = i;
        }
        if (sum < 0)
        {
            sum = 0;
            tempStart = i + 1;
        }
    }
    return {start, end};
}

pair<int, int> minContinuousSum(vector<int> &a)
{
    int n = a.size();
    int minSum = INT32_MAX;
    int sum = 0;
    int start = 0;
    int end = 0;
    int tempStart = 0;
    for (int i = 0; i < n; i++)
    {
        sum += a[i];
        if (sum < minSum)
        {
            minSum = sum;
            start = tempStart;
            end = i;
        }
        if (sum > 0)
        {
            sum = 0;
            tempStart = i + 1;
        }
    }
    return {start, end};
}

int main(int argc, char const *argv[])
{
    int n = 0, k = 0;
    cin >> n >> k;
    vector<int> a(n);
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    pair<int, int> p = maxContinuousSum(a);
    vector<int> b(n);
    pair<int, int> q = minContinuousSum(a);
    int pleft = p.first, pright = p.second;
    int qleft = q.first, qright = q.second;
    for (int i = pleft; i <= pright; ++i)
    {
        a[i] *= k;
    }
    for (int i = qleft; i <= qright; ++i)
    {
        a[i] *= k;
    }
    int sum = 0;
    for (int i = 0; i < n; ++i)
    {
        sum += a[i];
    }
    cout << sum << endl;
    return 0;
}
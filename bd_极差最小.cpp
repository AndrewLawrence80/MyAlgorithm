// 将长度为n的数组一分为二，使左边所有元素的极差和右边所有元素极差最为接近

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
    vector<int> a(n, 0);
    for (int i = 0; i < n; ++i)
    {
        cin >> a[i];
    }
    vector<int> maxRecLeft(n, 0), maxRecRight(n, 0), minRecLeft(n, 0), minRecRight(n, 0);
    int maxLeft = a[0], minLeft = a[0];
    maxRecLeft[0] = maxLeft, minRecLeft[0] = minLeft;
    for (int i = 1; i < n; ++i)
    {
        if (a[i] > maxLeft)
        {
            maxLeft = a[i];
        }
        maxRecLeft[i] = maxLeft;
        if (a[i] < minLeft)
        {
            minLeft = a[i];
        }
        minRecLeft[i] = minLeft;
    }
    int maxRight = a[n - 1], minRight = a[n - 1];
    maxRecRight[n - 1] = maxRight, minRecRight[n - 1] = minRight;
    for (int i = n - 2; i >= 0; --i)
    {
        if (a[i] > maxRight)
        {
            maxRight = a[i];
        }
        maxRecRight[i] = maxRight;
        if (a[i] < minRight)
        {
            minRight = a[i];
        }
        minRecRight[i] = minRight;
    }
    int minDiff = INT32_MAX;
    for (int i = 1; i < n - 1; ++i)
    {
        int tDiff = abs(abs(maxRecLeft[i] - minRecLeft[i]) - abs(maxRecRight[i+1] - minRecRight[i+1]));
        if (tDiff < minDiff)
        {
            minDiff = tDiff;
        }
    }
    cout << minDiff;
    return 0;
}
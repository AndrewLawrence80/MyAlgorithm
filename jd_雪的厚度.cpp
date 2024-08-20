// 村里有一些桩子，从左到右高度依次为1,1+2,1+2+,...,每两颗桩子之间的距离都是1。
// 现在下了一场雪，但不知雪下了多厚，现在给你两个数字，这是雪后某相邻两个桩子在雪面的高度，请你通过这两个数字计算雪的厚度。
// 输入描述:
// 输入两个整数a,b(1<=a,b<=5*10^5)
// 输出描述:
// 输出一个整数，表示雪的厚度
// 输入例子1:
// 8 13
// 输出例子1:
// 2
// 例子说明1:
// 高度依次是1,3,6,10,15,21,...,给出的是第4和第5个桩子的高度，所以雪的厚度是2

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
    int a, b;
    cin >> a >> b;
    int n = b - a;
    vector<long long> dp(n + 1, 0);
    for (int i = 1; i <= n; i++)
    {
        dp[i] = dp[i - 1] + i;
    }
    cout << dp[n] - b << endl;
    return 0;
}
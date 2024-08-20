// 牛牛有一种锯齿状的积木，这种积木比较长，但是每个单位长度的高度是相等的，高度为1或者2.
// 现在妞妞拿出了两块长度分别为n和m的积木，他现在想把这两块积木拼接在一起，即使中间有空隙也没有关系，但是拼接后的积木高度不要超过3,请你帮助牛牛计算在满足这个前提下拼接后的积木长度最短可以是多少
// 输入描述:
// 输入包括两个整数n,m，代表第一块和第二块积木的长度
// 第二行给出n个数字代表第一块积木每个单位的高度
// 第三行给出m个数字代表第二块积木每个单位的高度
// (1 <= n, m <= 1000, 1 <= 积木高度 <= 2)

// 输出描述:
// 输出一个整数，代表拼接后的积木最短长度

// 输入例子1:
// 5 5
// 1 2 1 2 1
// 2 1 2 1 2
// 输出例子1:
// 5

// 输入例子2:
// 7 10
// 2 2 1 2 1 1 2
// 2 1 1 2 2 1 1 2 1 2
// 输出例子2:
// 10

// 输入例子3:
// 3 2
// 2 2 2
// 2 2
// 输出例子3:
// 5

// 7 10
// 2 2 1 2 1 1 2
// 2 1 1 2 1 1 2 1 1 2

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n, m;
    cin >> n >> m;
    vector<int> a(n), b(m);
    
    for (int i = 0; i < n; ++i) cin >> a[i];
    for (int i = 0; i < m; ++i) cin >> b[i];
    
    int minLength = n + m;
    
    // Try aligning block b at different positions relative to block a
    for (int i = -m; i <= n; ++i) { // i is the starting position of b relative to a
        bool valid = true;
        for (int j = 0; j < m; ++j) {
            int aIndex = i + j;
            if (aIndex >= 0 && aIndex < n) { // Check if there's an overlap
                if (a[aIndex] + b[j] > 3) {
                    valid = false;
                    break;
                }
            }
        }
        if (valid) {
            int length = max(n, i + m) - min(0, i);
            minLength = min(minLength, length);
        }
    }
    
    cout << minLength << endl;
    return 0;
}

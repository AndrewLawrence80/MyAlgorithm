/*
直线上有N个点，i的位置是X_i，从N个点中选择若干个进行标记，要求对于每一个点，距离为R以内的区域里必须带有标记的点，希望为尽可能少的点添加标记
至少有多少点需要标记
1<=N<=1000
0<=R<=1000
0<=X_i<=1000

输入为多个样例，先输入R N
再输入N个X_i
R=N=-1结束
样例输入
0 3
10 20 20
10 7
70 30 1 7 15 20 50
-1 -1
输出
2
4
*/

#include <stdio.h>
#include <algorithm>
#include <string.h>
using namespace std;
int R = 0, N = 0;
int arr[1024] = {0};
void clear_arr()
{
    memset(arr, 0, 1024);
}
void solve()
{
    sort(arr, arr + N);
    int i = 0, ans = 0;
    while (i < N)
    {
        int start = arr[i];
        while (i < N && arr[i] <= start + R)
        {
            ++i;
        }
        int p = arr[i - 1];
        while (i < N && arr[i] <= p + R)
        {
            ++i;
        }
        ++ans;
    }
    printf("%d\n", ans);
}
int main(int argc, char const *argv[])
{
    scanf("%d%d", &R, &N);
    while (R != -1 && N != -1)
    {
        clear_arr();
        for (int i = 0; i < N; ++i)
        {
            scanf("%d", &arr[i]);
        }
        solve();
        scanf("%d%d", &R, &N);
    }
    return 0;
}

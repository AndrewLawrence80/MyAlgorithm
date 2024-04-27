/*
从n个重量和价值分别为wi、vi的物品中挑出总重量不超过W的物品，求出所有挑选方案中价值总和的最大值
1<=n<=100
1<=wi,vi<=100
1<=W<=10000
输入格式
n
wi,vi
W
样例输入
4
2,3
1,2
3,4
2,2
5
样例输出
7(1,2,3号物品)
*/
#include <stdio.h>
#include <algorithm>
#include <string.h>

using namespace std;

int ws[100] = {0};
int vs[100] = {0};
int N = 0, W = 0;
int dp[100][100] = {0};

void get_input()
{
    scanf("%d", &N);
    for (int i = 0; i < N; i++)
    {
        scanf("%d,%d", &ws[i], &vs[i]);
    }
    scanf("%d", &W);
}

void solve()
{
    for (int current_w = 0; current_w <= W; ++current_w)
    {
        for (int current_i = N - 1; current_i >= 0; --current_i)
        {
            if (current_w < ws[current_i])
            {
                dp[current_w][current_i] = dp[current_w][current_i + 1];
            }
            else
            {
                dp[current_w][current_i] = max(dp[current_w][current_i + 1], dp[current_w - ws[current_i]][current_i + 1] + vs[current_i]);
            }
        }
    }
    printf("%d", dp[W][0]);
}

int main(int argc, char const *argv[])
{
    memset(dp, 0, sizeof(dp));
    get_input();
    solve();
    return 0;
}

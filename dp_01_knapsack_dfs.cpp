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
int W = 0, n = 0;
int ws[100] = {0};
int vs[100] = {0};
void read_input()
{
    scanf("%d", &n);
    for (int i = 0; i < n; ++i)
    {
        scanf("%d,%d", &ws[i], &vs[i]);
    }
    scanf("%d", &W);
}
int dfs(int i, int j)
{
    // i是物品编号，j是重量
    if (i == n)
    {
        return 0;
    }
    else if (j < ws[i])
    {
        // 无法挑选物品i，尝试下一个
        return (i + 1, j);
    }
    else
    {
        return std::max(dfs(i + 1, j), dfs(i + 1, j - ws[i]) + vs[i]);
    }
}
int main(int argc, char const *argv[])
{
    read_input();
    printf("%d", dfs(0, W));
    return 0;
}

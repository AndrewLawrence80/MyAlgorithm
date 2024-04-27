/*
给定长度为N的字符串S，重复以下操作构造一个长度为N的字符串T，使T的字典序最小
1. 从S的头部删除一个字符加入T的尾部
2. 从S的尾部删除一个字符加入T的尾部
1<=N<=2000
S只包含大写字母

样例输入
6
A
C
D
B
C
B
样例输出
ABCBCD

输出格式
每行80个字母

使用贪心算法，不断取S开头和末尾中较小的字符放到T的末尾
*/

#include <stdio.h>
#include <string.h>

int N;
char S[2001] = {0};
char T[2001] = {0};

void read_input()
{
    scanf("%d", &N);
    getchar();
    for (int i = 0; i < N; ++i)
    {
        char tmp[3] = {0};
        fgets(tmp, 80, stdin);
        memcpy(S + i, tmp, 1);
    }
}

void solve()
{
    int a = 0, b = N - 1;
    int i = 0;
    while (a <= b)
    {
        if (S[a] < S[b])
        {
            T[i] = S[a];
            ++a;
        }
        else if (S[a] > S[b])
        {
            T[i] = S[b];
            --b;
        }
        else
        {
            int x = a, y = b;
            while (x <= y && S[x] == S[y])
            {
                ++x;
                --y;
            }
            if (S[x] < S[y])
            {
                T[i] = S[a];
                ++a;
            }
            else
            {
                T[i] = S[b];
                --b;
            }
        }
        ++i;
    }
}
void print()
{
    int len = strlen(T);
    int n_line = len / 80;
    for (int i = 0; i < n_line; ++i)
    {
        for (int j = 0; j < 80; ++j)
        {
            putchar(T[i * 80 + j]);
        }
        putchar('\n');
    }
    for (int j = n_line * 80; j < len; ++j)
    {
        putchar(T[j]);
    }
    putchar('\n');
}

int main(int argc, char const *argv[])
{
    read_input();
    solve();
    print();
    return 0;
}

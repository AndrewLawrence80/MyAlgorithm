/*
大小为MxN的园子雨后有积水，八连通的积水被认为相连，求出园子内的水洼数目
输入样例
N=10,M=12
W........WW.
.WWW.....WWW
....WW...WW.
.........WW.
.........W..
..W......W..
.W.W.....WW.
W.W.W.....W.
.W.W......W.
..W.......W.

N,M<=100
*/

#include <stdio.h>

int garden[102][102] = {0};
int N = 0, M = 0;

void get_input()
{
    scanf("N=%d,M=%d", &N, &M);
    getchar();
    for (int i = 1; i <= N; ++i)
    {
        for (int j = 1; j <= M + 1; ++j)
        {
            char c = getchar();
            if (c == 'W')
            {
                garden[i][j] = 1;
            }
        }
    }
}

void dfs(int x, int y)
{
    if (garden[x][y] == 0)
        return;
    garden[x][y] = 0;
    for (int i = -1; i <= 1; ++i)
    {
        for (int j = -1; j <= 1; ++j)
        {
            if (i == 0 && j == 0)
                continue;
            else
                dfs(x + i, y + j);
        }
    }
}

int main(int argc, char const *argv[])
{
    get_input();
    int cnt = 0;
    for (int i = 1; i <= N; ++i)
    {
        for (int j = 1; j <= M; ++j)
        {
            if (garden[i][j] == 1)
            {
                ++cnt;
                dfs(i, j);
            }
        }
    }
    printf("%d\n", cnt);
    return 0;
}

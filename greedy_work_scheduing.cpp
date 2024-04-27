/*
n项工作，每项工作分别在s_i开始，在t_i结束，如果选择参与某项工作需要全程参与，工作时间不能重叠，目标是参与尽可能多的工作，最多参与多少项
1<=N<=10^5
1<=s_i<=t_i<=10^9
样例
n=5
1 2 4 6 8
3 5 7 9 10

解法：在可选的工作中每次都选取结束时间最早的工作
*/

#include <stdio.h>
#include <algorithm>

using namespace std;

typedef struct
{
    int s, t;
} Job;
Job jobs[(int)1e5];

bool operator<(const Job &a, const Job &b)
{
    return a.t < b.t;
}

int N = 0;
void read_input()
{
    scanf("n=%d\n", &N);
    for (int i = 0; i < N; ++i)
    {
        scanf("%d", &(jobs[i].s));
    }
    for (int i = 0; i < N; ++i)
    {
        scanf("%d", &(jobs[i].t));
    }
}

void solve()
{
    sort(jobs, jobs + N);
    int ans = 0, t = 0;
    for (int i = 0; i < N; ++i)
    {
        if (t < jobs[i].s)
        {
            ++ans;
            t = jobs[i].t;
        }
    }
    printf("%d\n", ans);
}

int main(int argc, char const *argv[])
{
    read_input();
    solve();
    return 0;
}

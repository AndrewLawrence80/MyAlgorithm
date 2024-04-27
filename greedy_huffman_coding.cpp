/*
给定N个码频输出Huffman编码的开销
第一个输入为N
输入样例
3
8
5
8
输出
34
*/

#include <queue>
#include <cstdio>
using namespace std;
int N = 0;
priority_queue<int, vector<int>, greater<int> > pq;
int main()
{
    scanf("%d", &N);
    for (int i = 0; i < N; i++)
    {
        int x;
        scanf("%d", &x);
        pq.push(x);
    }
    long long ans = 0;
    while (pq.size() != 1)
    {
        int x = pq.top();
        pq.pop();
        int y = pq.top();
        pq.pop();
        ans += x + y;
        pq.push(x + y);
    }
    printf("%lld", ans);
    return 0;
}
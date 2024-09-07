#include <iostream>
#include <vector>
#include <deque>
#include <stack>
#include <unordered_map>
#include <algorithm>
#include <string>

using namespace std;

vector<bool> visited;
vector<int> number;
int n = 0, m = 0, k = 0;
int cnt = 0;

long vectorToNum()
{
    long t = 0, base = 1;
    for (int i = m - 1; i >= 0; --i)
    {
        t += base * number[i];
        base *= 10;
    }
    return t;
}

void dfs(int idx)
{
    if (idx >= m)
    {
        long x = vectorToNum();
        if (x > k)
        {
            ++cnt;
        }
        return;
    }
    for (int i = 0; i <= n; ++i)
    {
        if (!visited[i])
        {
            if (idx == 0 && m > 1 && i == 0)
            {
                continue;
            }
            number[idx] = i;
            visited[i] = true;
            dfs(idx + 1);
            visited[i] = false;
        }
    }
}

int main(int argc, char const *argv[])
{

    cin >> n >> m >> k;
    visited.resize(n + 1, false);
    number.resize(m, 0);
    dfs(0);
    cout << cnt;
    return 0;
}
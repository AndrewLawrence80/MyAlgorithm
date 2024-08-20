// Given a number n (n>1), find a number m (2<=m<=n),
// that gcd(m,n) is prime

#include <iostream>
#include <vector>
#include <deque>
#include <stack>
#include <unordered_map>
#include <algorithm>
#include <string>

using namespace std;

int gcd(int a, int b)
{
    if (a < b)
        swap(a, b);
    while (b != 0)
    {
        int t = a % b;
        a = b;
        b = t;
    }
    return a;
}

bool is_prime(int n)
{
    if (n < 2)
        return false;
    for (int i = 2; i * i <= n; i++)
    {
        if (n % i == 0)
            return false;
    }
    return true;
}

int main(int argc, char const *argv[])
{
    int T;
    cin >> T;
    vector<int> n(T);
    for (int i = 0; i < T; i++)
    {
        cin >> n[i];
    }
    for (int i = 0; i < T; i++)
    {
        int m = n[i];
        while (m >= 2)
        {
            int t = gcd(m, n[i]);
            if (is_prime(t))
            {
                cout << m << endl;
                break;
            }
            --m;
        }
    }
    return 0;
}
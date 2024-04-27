// Given a knapsack weight W and a set of n items with certain value vali and weight wti, we need to calculate the maximum amount that could make up this quantity exactly. This is different from classical Knapsack problem, here we are allowed to use unlimited number of instances of an item.

// Note: N is always positive i.e greater than zero

// Examples:

// Input : W = 100
//        val[]  = {1, 30}
//        wt[] = {1, 50}
// Output : 100
// There are many ways to fill knapsack.
// 1) 2 instances of 50 unit weight item.
// 2) 100 instances of 1 unit weight item.
// 3) 1 instance of 50 unit weight item and 50
//    instances of 1 unit weight items.
// We get maximum value with option 2.

// Input : W = 8
//        val[] = {10, 40, 50, 70}
//        wt[]  = {1, 3, 4, 5}
// Output : 110
// We get maximum value with one unit of
// weight 5 and one unit of weight 3.

// Constraints:
// 1 ≤ N, W ≤ 1000
// 1 ≤ val[i], wt[i] ≤ 100

#include <iostream>
#include <stdio.h>
#include <algorithm>

using namespace std;

int N = 0, W = 0;
int weights[1000] = {0};
int values[1000] = {0};

void get_input()
{
    scanf("%d", &N);
    scanf("%d", &W);

    for (int i = 0; i < N; ++i)
    {
        scanf("%d", &values[i]);
    }
    for (int i = 0; i < N; ++i)
    {
        scanf("%d", &weights[i]);
    }
}

void solve()
{
    int dp[1001][1001] = {0};
    for (int current_i = 1; current_i <= N; ++current_i)
    {
        for (int current_w = 0; current_w <= W; ++current_w)
        {
            if (current_w < weights[current_i - 1])
            {
                dp[current_i][current_w] = dp[current_i - 1][current_w];
            }
            else
            {
                dp[current_i][current_w] = max(dp[current_i - 1][current_w], dp[current_i][current_w - weights[current_i - 1]] + values[current_i - 1]);
            }
        }
    }
    printf("%d",dp[N][W]);
}

int main(int argc, char const *argv[])
{
    get_input();
    solve();
    return 0;
}
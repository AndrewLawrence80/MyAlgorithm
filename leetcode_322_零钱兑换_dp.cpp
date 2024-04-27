// 给你一个整数数组 coins ，表示不同面额的硬币；以及一个整数 amount ，表示总金额。

// 计算并返回可以凑成总金额所需的 最少的硬币个数 。如果没有任何一种硬币组合能组成总金额，返回 -1 。

// 你可以认为每种硬币的数量是无限的。

// 示例 1：

// 输入：coins = [1, 2, 5], amount = 11
// 输出：3
// 解释：11 = 5 + 5 + 1

// 示例 2：

// 输入：coins = [2], amount = 3
// 输出：-1

// 示例 3：

// 输入：coins = [1], amount = 0
// 输出：0

// 提示：

//     1 <= coins.length <= 12
//     1 <= coins[i] <= 2^31 - 1
//     0 <= amount <= 10^4

#include <iostream>
#include <vector>
#include <algorithm>
#include <stdio.h>

using namespace std;

int n_coins = 0;
vector<int> coins;
int amount;

void get_input()
{
    cin >> n_coins;
    for (int i = 0; i < n_coins; ++i)
    {
        int tmp = 0;
        cin >> tmp;
        coins.push_back(tmp);
    }
    cin >> amount;
}

class Solution
{
public:
    int coinChange(vector<int> &coins, int amount)
    {
        sort(coins.begin(), coins.end());
        vector<int> dp(amount + 1, amount + 1);
        dp[0] = 0;
        for (int i = 0; i < dp.size(); ++i)
        {
            for (int current_i = 0; current_i < coins.size(); ++current_i)
            {
                if (i - coins[current_i] < 0)
                {
                    continue;
                }
                else
                {
                    dp[i] = min(dp[i], dp[i - coins[current_i]] + 1);
                }
            }
        }
        return dp[amount] == amount + 1 ? -1 : dp[amount];
    }
};

int main(int argc, char const *argv[])
{
    get_input();
    cout << Solution().coinChange(coins, amount);
    return 0;
}
// Given a rope of length N meters, cut the rope into several ropes of varying lengths in a way that maximizes product of lengths of all resulting ropes. You must make at least one cut.

// Example 1:

// Input:
// N = 2
// Output: 1
// Explanation: Since 1 cut is mandatory.
// Maximum obtainable product is 1*1 = 1.

// Example 2:

// Input:
// N = 5
// Output: 6
// Explanation:
// Maximum obtainable product is 2*3 = 6.

// Your Task:
// You don't need to read input or print anything. Your task is to complete the function maxProduct() which takes n as input parameter and returns the maximum product.

// Expected Time Complexity: O(N2)
// Expected Auxiliary Space: O(N)

// Constraints:
// 1 ≤ N ≤ 100

#include <iostream>
#include <vector>
#include <deque>
#include <unordered_map>
#include <algorithm>
#include <string>

using namespace std;

class Solution
{
public:
    long long maxProduct(int n)
    {
        if (n == 0 || n == 1)
        {
            return 0;
        }
        long long maxP = 0;
        for (int i = 1; i < n; ++i)
        {
            long long tP = i * (n - i);
            if (tP > maxP)
            {
                maxP = tP;
            }
            tP = i * maxProduct(n - i);
            if (tP > maxP)
            {
                maxP = tP;
            }
        }
        return maxP;
    }
};

int main(int argc, char const *argv[])
{
    int n = 0;
    cin >> n;
    cout << Solution().maxProduct(n);
    return 0;
}
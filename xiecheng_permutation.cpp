// given two number n,k, output the permutation with LIS of length k while keeping the smallest dictionary order of the permutation
// example
// n=5,k=3
// 1 2 5 4 3
// the permutation comes with minimum LIS length k and minmum dictionary order

#include <iostream>
#include <vector>
#include <deque>
#include <stack>
#include <unordered_map>
#include <algorithm>
#include <string>

using namespace std;

class Solution
{
public:
    vector<int> minDictionaryOrderPermutationWithLISK(int n, int k)
    {
        vector<int> a(n, 0);
        for (int i = 0; i < k - 1; ++i)
        {
            a[i] = i + 1;
        }
        for (int i = k - 1; i < n; ++i)
        {
            a[i] = n - (i - k) - 1;
        }
        return a;
    }
};

int main(int argc, char const *argv[])
{
    int n = 0, k = 0;
    cin >> n >> k;
    vector<int> answer = Solution().minDictionaryOrderPermutationWithLISK(n, k);
    for (int i = 0; i < n; ++i)
    {
        cout << answer[i];
        if (i < n - 1)
        {
            cout << " ";
        }
    }
    cout << endl;
    return 0;
}
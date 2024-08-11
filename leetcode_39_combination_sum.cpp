// Given an array of distinct integers candidates and a target integer target, return a list of all unique combinations of candidates where the chosen numbers sum to target. You may return the combinations in any order.

// The same number may be chosen from candidates an unlimited number of times. Two combinations are unique if the
// frequency
// of at least one of the chosen numbers is different.

// The test cases are generated such that the number of unique combinations that sum up to target is less than 150 combinations for the given input.

// Example 1:

// Input: candidates = [2,3,6,7], target = 7
// Output: [[2,2,3],[7]]
// Explanation:
// 2 and 3 are candidates, and 2 + 2 + 3 = 7. Note that 2 can be used multiple times.
// 7 is a candidate, and 7 = 7.
// These are the only two combinations.

// Example 2:

// Input: candidates = [2,3,5], target = 8
// Output: [[2,2,2,2],[2,3,3],[3,5]]

// Example 3:

// Input: candidates = [2], target = 1
// Output: []

#include <iostream>
#include <vector>
#include <deque>
#include <unordered_map>
#include <algorithm>
#include <string>

using namespace std;

int n_candidates;
vector<int> candidates;
int target;

void get_input()
{
    cin >> n_candidates;
    candidates.resize(n_candidates);
    for (int i = 0; i < n_candidates; ++i)
    {
        cin >> candidates[i];
    }
    cin >> target;
}

class Solution
{
public:
    vector<vector<int>> results;

    void backtrack(vector<int> &candidates, vector<int> current_combination, int candidate_idx, int target)
    {
        if (target == 0)
        {
            results.push_back(current_combination);
            return;
        }
        // i从candidate_idx开始，不走回头路
        for (int i = candidate_idx; i < candidates.size(); ++i)
        {
            if (candidates[i] <= target)
            {
                current_combination.push_back(candidates[i]);
                backtrack(candidates, current_combination, i, target - candidates[i]);
                current_combination.pop_back();
            }
        }
    }

    vector<vector<int>> combinationSum(vector<int> &candidates, int target)
    {
        sort(candidates.begin(), candidates.end());
        vector<int> current_combination;
        backtrack(candidates, current_combination, 0, target);
        return results;
    }
};

int main(int argc, char const *argv[])
{
    get_input();
    vector<vector<int>> results = Solution().combinationSum(candidates, target);
    for (auto v : results)
    {
        for (auto x : v)
        {
            cout << x << " ";
        }
        cout << endl;
    }
    return 0;
}
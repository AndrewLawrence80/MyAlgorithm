// Given an array nums of distinct integers, return all the possible permutations. You can return the answer in any order.
// Example 1:

// Input: nums = [1,2,3]
// Output: [[1,2,3],[1,3,2],[2,1,3],[2,3,1],[3,1,2],[3,2,1]]

// Example 2:

// Input: nums = [0,1]
// Output: [[0,1],[1,0]]

// Example 3:

// Input: nums = [1]
// Output: [[1]]
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
    vector<vector<int>> results;
    vector<bool> visited;
    vector<int> nums;
    void dfs(vector<int> v, vector<int> &nums)
    {
        if (v.size()==nums.size()){
            results.push_back(v);
            return;
        }
        for (unsigned i=0;i<nums.size();++i){
            if (!visited[i]){
                v.push_back(nums[i]);
                visited[i]=true;
                dfs(v,nums);
                visited[i]=false;
                v.pop_back();
            }
        }
    }
    vector<vector<int>> permute(vector<int> &nums)
    {
        this->nums = nums;
        visited.resize(nums.size());
        dfs({},nums);
        return results;
    }
};

int main(int argc, char const *argv[])
{
    int N = 0;
    vector<int> nums;
    cin >> N;
    nums.resize(N);
    for (int i = 0; i < N; ++i)
    {
        cin >> nums[i];
    }
    vector<vector<int>> results = Solution().permute(nums);
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
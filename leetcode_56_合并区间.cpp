// 以数组 intervals 表示若干个区间的集合，其中单个区间为 intervals[i] = [starti, endi] 。请你合并所有重叠的区间，并返回 一个不重叠的区间数组，该数组需恰好覆盖输入中的所有区间 。

// 示例 1：

// 输入：intervals = [[1,3],[2,6],[8,10],[15,18]]
// 输出：[[1,6],[8,10],[15,18]]
// 解释：区间 [1,3] 和 [2,6] 重叠, 将它们合并为 [1,6].

// 示例 2：

// 输入：intervals = [[1,4],[4,5]]
// 输出：[[1,5]]
// 解释：区间 [1,4] 和 [4,5] 可被视为重叠区间。

// 提示：

//     1 <= intervals.length <= 104
//     intervals[i].length == 2
//     0 <= starti <= endi <= 104

#include <iostream>
#include <vector>
#include <algorithm>
#include <stdio.h>

using namespace std;

int N = 0;
vector<vector<int>> intervals;

void get_input()
{
    cin >> N;
    intervals.resize(N, vector<int>(2, 0));
    for (int i = 0; i < N; ++i)
    {
        cin >> intervals[i][0] >> intervals[i][1];
    }
}

class IntervalComparator
{
public:
    bool operator()(const vector<int> &interval_a, const vector<int> &interval_b)
    {
        //  开始时间最早的区间放在前面
        if (interval_a[0] < interval_b[0])
        {
            return true;
        }
        else if (interval_a[0] > interval_b[0])
        {
            return false;
        }
        else
        {
            // 如果两个区间起点相同，结束早的区间放前面
            return interval_a[1] < interval_b[1];
        }
    }
};

class Solution
{
public:
    vector<vector<int>> merge(vector<vector<int>> &intervals)
    {
        vector<vector<int>> ans;
        sort(intervals.begin(), intervals.end(), IntervalComparator());
        for (int i = 0; i < intervals.size(); ++i)
        {
            if (ans.size() == 0)
            {
                ans.push_back(intervals[i]);
            }
            else
            {
                vector<int> prev_interval = ans[ans.size() - 1];
                ans.pop_back();
                vector<int> &current_interval = intervals[i];
                if (prev_interval[1] >= current_interval[0]) // 如果最后的区间终点比当前考察的区间起点要早，合并两个区间
                {
                    vector<int> merged_interval(2, 0);
                    merged_interval[0] = min(prev_interval[0],current_interval[0]); // 合并区间的起点是两个区间起点的最小值
                    merged_interval[1] = max(prev_interval[1],current_interval[1]); // 合并区间的终点是两个区间终点的最大值
                    ans.push_back(merged_interval);
                }
                else
                {
                    ans.push_back(prev_interval);
                    ans.push_back(current_interval);
                }
            }
        }
        return ans;
    }
};

void print_output(vector<vector<int>> ans)
{
    for (vector<int> interval : ans)
    {
        cout << interval[0] << " " << interval[1] << endl;
    }
}

int main(int argc, char const *argv[])
{
    get_input();
    vector<vector<int>> ans = Solution().merge(intervals);
    print_output(ans);
    return 0;
}
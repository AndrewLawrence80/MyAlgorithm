// 给定一个长度为 n 的整数数组 height 。有 n 条垂线，第 i 条线的两个端点是 (i, 0) 和 (i, height[i]) 。

// 找出其中的两条线，使得它们与 x 轴共同构成的容器可以容纳最多的水。

// 返回容器可以储存的最大水量。

// 说明：你不能倾斜容器。

// 输入：[1,8,6,2,5,4,8,3,7]
// 输出：49
// 解释：图中垂直线代表输入数组 [1,8,6,2,5,4,8,3,7]。在此情况下，容器能够容纳水（表示为蓝色部分）的最大值为 49。

// 示例 2：

// 输入：height = [1,1]
// 输出：1

// 提示：

//     n == height.length
//     2 <= n <= 105
//     0 <= height[i] <= 104

#include <iostream>
#include <vector>
#include <algorithm>
#include <stdio.h>

using namespace std;

int N = 0;

vector<int> height;

void get_input()
{
    cin >> N;
    height.resize(N, 0);
    for (int i = 0; i < N; ++i)
    {
        cin >> height[i];
    }
}

class Solution
{
public:
    int maxArea(vector<int> &height)
    {
        int left = 0, right = height.size() - 1;
        int currentMaxArea = (right - left) * min(height[left], height[right]);
        while (left < right)
        {
            if (height[left] < height[right])
            {
                ++left;
            }
            else
            {
                --right;
            }
            int tmpArea = (right - left) * min(height[left], height[right]);
            if (tmpArea > currentMaxArea)
            {
                currentMaxArea = tmpArea;
            }
        }
        return currentMaxArea;
        // int currentMaxArea=0;
        // for (int i=0;i<height.size();++i){
        //     for (int j=i+1;j<height.size();++j){
        //         int tmpArea=(j-i)*min(height[i],height[j]);
        //         if (tmpArea>currentMaxArea){
        //             currentMaxArea=tmpArea;
        //         }
        //     }
        // }
        // return currentMaxArea;
    }
};

int main(int argc, char const *argv[])
{
    get_input();
    cout << Solution().maxArea(height);
    return 0;
}
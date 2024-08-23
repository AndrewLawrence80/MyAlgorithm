#include <iostream>
#include <vector>
#include <deque>
#include <stack>
#include <unordered_map>
#include <algorithm>
#include <string>
#include <cmath>

using namespace std;

class QSort
{
public:
    void quickSort(vector<int> &nums, int left, int right)
    {
        if (left >= right)
        {
            return;
        }
        int pivot = nums[left];
        int i = left + 1, j = right;
        while (true)
        {
            while (nums[i] <= pivot && i <= right)
                i++;
            while (nums[j] > pivot && j >= left)
                j--;
            if (i > j)
                break;
            swap(nums[i], nums[j]);
        }
        swap(nums[left], nums[j]);
        quickSort(nums, left, j - 1);
        quickSort(nums, j + 1, right);
    }
};

int main(int argc, char const *argv[])
{
    long sz = random() % 100;
    vector<int> a(sz);
    for (int i = 0; i < sz; i++)
    {
        a[i] = random();
    }
    QSort().quickSort(a, 0, sz - 1);
    return 0;
}
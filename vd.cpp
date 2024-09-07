#include <iostream>
#include <vector>
using namespace std;
class Heap
{
public:
    vector<int> arr;
    int size;
    void sink(int idx)
    {
        if (idx >= size)
        {
            return;
        }
        int leftIdx = 2 * idx + 1;
        int rightIdx = 2 * idx + 2;
        int minVal = arr[idx];
        int minIdx = idx;
        int tMinVal = minVal;
        if (leftIdx < size)
        {
            tMinVal = min(minVal, arr[leftIdx]);
            if (tMinVal != minVal)
            {
                minVal = tMinVal;
                minIdx = leftIdx;
            }
        }
        if (rightIdx < size)
        {
            tMinVal = min(minVal, arr[rightIdx]);
            if (tMinVal != minVal)
            {
                minIdx = rightIdx;
            }
        }
        if (minIdx != idx)
        {
            swap(arr[minIdx], arr[idx]);
            sink(minIdx);
        }
        
    }
    void heapify()
    {
        for (int i = size / 2; i >= 0; --i)
        {
            sink(i);
        }
    }
    int pop()
    {
        int x = arr[0];
        swap(arr[size - 1], arr[0]);
        arr.pop_back();
        size -= 1;
        sink(0);
        return x;
    }
    Heap()
    {
    }
    Heap(vector<int> &nums)
    {
        arr = vector<int>(nums);
        this->size = arr.size();
    }
};
int main()
{
    int n = 0;
    cin >> n;
    vector<int> arr(n);
    for (int i = 0; i < n; ++i)
    {
        cin >> arr[i];
    }
    Heap h(arr);
    h.heapify();
    while (!h.size == 0)
    {
        cout << h.pop() << endl;
    }
    cout << endl;
}
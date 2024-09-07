#include <iostream>
#include <vector>
#include <deque>
#include <stack>
#include <unordered_map>
#include <algorithm>
#include <string>

using namespace std;

class Sorter
{
public:
    void bubbleSort(vector<int> &arr);
    void selectSort(vector<int> &arr);
    void insertSort(vector<int> &arr);
    void hillSort(vector<int> &arr);
    void mergeSort(vector<int> &arr, int left, int right);
    void quickSort(vector<int> &arr, int left, int right);
    void bucketSort(vector<int> &arr);
    void countSort(vector<int> &arr);
    void heapSort(vector<int> &arr);
    void radixSort(vector<int> &arr);
};

void Sorter::bubbleSort(vector<int> &arr)
{
    int sz = arr.size();
    for (int i = 0; i < sz; ++i)
    {
        for (int j = 0; j + 1 < sz - i; ++j)
        {
            if (arr[j] > arr[j + 1])
            {
                swap(arr[j], arr[j + 1]);
            }
        }
    }
}

void Sorter::selectSort(vector<int> &arr)
{
    int sz = arr.size();
    for (int i = 0; i < sz; ++i)
    {
        int min_idx = i;
        for (int j = i + 1; j < sz; ++j)
        {
            if (arr[j] < arr[min_idx])
            {
                min_idx = j;
            }
        }
        swap(arr[i], arr[min_idx]);
    }
}
void Sorter::insertSort(vector<int> &arr)
{
    int sz = arr.size();
    for (int i = 0; i < sz; ++i)
    {
        for (int j = i + 1; j > 0 && arr[j] < arr[j - 1]; --j)
        {
            swap(arr[j], arr[j - 1]);
        }
    }
}
void Sorter::hillSort(vector<int> &arr)
{
    int gap = 1, sz = arr.size();
    while (gap < sz / 3)
    {
        gap *= 3;
        gap += 1;
    }
    while (gap)
    {
        for (int i = 0; i + gap < sz; i += gap)
        {
            for (int j = i + gap; j > 0 && arr[j] < arr[j - gap]; j -= gap)
            {
                swap(arr[j], arr[j - gap]);
            }
        }
        gap /= 3;
    }
}
void Sorter::mergeSort(vector<int> &arr, int left, int right)
{
    if (right <= left)
    {
        return;
    }
    int mid = (left + right) / 2;
    mergeSort(arr, left, mid);
    mergeSort(arr, mid + 1, right);
    vector<int> arrLeft(arr.begin() + left, arr.begin() + mid + 1);
    vector<int> arrRight(arr.begin() + mid + 1, arr.begin() + right + 1);
    int i = 0, j = 0, k = left;
    while (i < arrLeft.size() && j < arrRight.size())
    {
        if (arrLeft[i] <= arrRight[j])
        {
            arr[k++] = arrLeft[i++];
        }
        else
        {
            arr[k++] = arrRight[j++];
        }
    }
    while (i < arrLeft.size())
    {
        arr[k++] = arrLeft[i++];
    }
    while (j < arrRight.size())
    {
        arr[k++] = arrRight[j++];
    }
}
void Sorter::quickSort(vector<int> &arr, int left, int right)
{
    if (right <= left)
    {
        return;
    }
    int i = left + 1, j = right, pivot = arr[left];
    while (true)
    {
        while (i <= right && arr[i] < pivot)
        {
            ++i;
        }
        while (j >= left && arr[j] > pivot)
        {
            --j;
        }
        if (i >= j)
        {
            break;
        }
        swap(arr[i], arr[j]);
    }
    swap(arr[left], arr[j]);
    quickSort(arr, left, j - 1);
    quickSort(arr, j + 1, right);
}
void Sorter::bucketSort(vector<int> &arr) {
    
}
void Sorter::countSort(vector<int> &arr) {}
void Sorter::heapSort(vector<int> &arr) {}
void Sorter::radixSort(vector<int> &arr) {}

int main(int argc, char const *argv[])
{
    srand(time(0));
    const int sz = 20;
    vector<int> arr(sz, 0);
    for (int i = 0; i < sz; ++i)
    {
        arr[i] = rand() % 100;
    }
    Sorter *sorter = new Sorter();
    sorter->quickSort(arr, 0, sz - 1);
    for (int x : arr)
    {
        cout << x << " ";
    }
    cout << endl;
    return 0;
}
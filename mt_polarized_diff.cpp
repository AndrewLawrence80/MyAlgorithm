// Given an array of length n, each time select two index i,j, make a[i]=a[i]-1 and a[j]=a[j]+1,
// find minimum operation number k to minimize the polarized difference of the array.

#include <iostream>
#include <vector>
#include <deque>
#include <stack>
#include <unordered_map>
#include <algorithm>
#include <string>

using namespace std;

int main(int argc, char const *argv[])
{
    int n;
    cin >> n;

    vector<int> arr(n);
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    sort(arr.begin(), arr.end());

    int i = 0, j = n - 1;
    int operations = 0;

    while (i < j) {
        int diff = arr[j] - arr[i];
        operations += diff;
        i++;
        j--;
    }

    cout << operations << endl;

    return 0;
}

// Given an array of length n, each time select two index i,j, make a[i]=a[i]-1 and a[j]=a[j]+1,
// find minimum operation number k to minimize the polarized difference of the array.

// #include <iostream>
// #include <vector>
// #include <deque>
// #include <stack>
// #include <unordered_map>
// #include <algorithm>
// #include <string>

// using namespace std;

// int main(int argc, char const *argv[])
// {
//     int n = 0;
//     cin >> n;
//     vector<int> a(n);
//     for (int i = 0; i < n; i++)
//     {
//         cin >> a[i];
//     }
//     sort(a.begin(), a.end());
//     int num_op = 0;
//     int prev_diff = a[n - 1] - a[0];
//     while (true)
//     {
//         a[0] = a[0] + 1;
//         a[n - 1] = a[n - 1] - 1;
//         sort(a.begin(), a.end());
//         int next_diff = a[n - 1] - a[0];
//         if (next_diff > prev_diff)
//         {
//             break;
//         }
//         prev_diff = next_diff;
//         ++num_op;
//     }
//     cout << num_op << endl;
//     return 0;
// }
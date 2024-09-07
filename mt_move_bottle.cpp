#include <iostream>
#include <vector>
#include <deque>
#include <stack>
#include <unordered_map>
#include <algorithm>
#include <string>
#include <utility>
#include <queue>
#include <cmath>

using namespace std;

class Co
{
public:
    long long x, y;
    unsigned long long distToStart;
    unsigned long long distToEnd;
    Co()
    {
        x = 0;
        y = 0;
        distToStart = 0;
        distToEnd = 0;
    }
};

class CmpDistToStart
{
public:
    bool operator()(const Co &a, const Co &b)
    {
        return a.distToStart > b.distToStart;
    }
};

class CmpDistToEnd
{
public:
    bool operator()(const Co &a, const Co &b)
    {
        return a.distToEnd > b.distToEnd;
    }
};

int main(int argc, char const *argv[])
{
    Co startC, endC;
    cin >> startC.x >> startC.y;
    cin >> endC.x >> endC.y;
    endC.distToEnd = abs(endC.x - startC.x) + abs(endC.y - startC.y);
    int n = 0;
    cin >> n;
    priority_queue<Co, vector<Co>, CmpDistToStart> pqStart;
    priority_queue<Co, vector<Co>, CmpDistToEnd> pqEnd;
    for (int i = 0; i < n; ++i)
    {
        Co t;
        cin >> t.x >> t.y;
        t.distToStart = abs(t.x - startC.x) + abs(t.y - startC.y);
        t.distToEnd = abs(t.x - endC.x) + abs(t.y - endC.y);
        pqStart.push(t);
        pqEnd.push(t);
    }
    Co firstToPick = pqStart.top();
    unsigned long long dist = firstToPick.distToStart + firstToPick.distToEnd;
    int duplicatedCo = 0;
    while (!pqEnd.empty())
    {
        Co nextToPick = pqEnd.top();
        pqEnd.pop();
        if (nextToPick.x == firstToPick.x && nextToPick.y == firstToPick.y && duplicatedCo < 1)
        {
            ++duplicatedCo;
            continue;
        }
        dist += 2 * nextToPick.distToEnd;
    }
    cout << dist << endl;
    return 0;
}
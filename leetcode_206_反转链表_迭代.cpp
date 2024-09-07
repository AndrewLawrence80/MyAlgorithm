// 给你单链表的头节点 head ，请你反转链表，并返回反转后的链表。

// 示例 1：

// 输入：head = [1,2,3,4,5]
// 输出：[5,4,3,2,1]

// 示例 2：

// 输入：head = [1,2]
// 输出：[2,1]

// 示例 3：

// 输入：head = []
// 输出：[]

// 提示：

//     链表中节点的数目范围是 [0, 5000]
//     -5000 <= Node.val <= 5000

// 进阶：链表可以选用迭代或递归方式完成反转。你能否用两种方法解决这道题？

#include <iostream>
#include <vector>
#include <deque>
#include <stack>
#include <unordered_map>
#include <algorithm>
#include <string>

using namespace std;

struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

ListNode *buildList(vector<int> &list)
{
    ListNode *head = nullptr, *tail = nullptr;
    for (int x : list)
    {
        ListNode *newNode = new ListNode(x);
        if (head == nullptr)
        {
            head = newNode;
            tail = newNode;
        }
        else
        {
            tail->next = newNode;
            tail = newNode;
        }
    }
    return head;
}

class Solution
{
public:
    ListNode *reverseList(ListNode *head)
    {
        ListNode *prev = nullptr, *current = head;
        while (current)
        {
            ListNode *next = current->next;
            current->next = prev;
            prev = current;
            current = next;
        }
        return prev;
    }
};

int main(int argc, char const *argv[])
{
    int n = 0;
    cin >> n;
    vector<int> list(n);
    for (int i = 0; i < n; i++)
    {
        cin >> list[i];
    }
    ListNode *head = buildList(list);
    head = Solution().reverseList(head);
    return 0;
}
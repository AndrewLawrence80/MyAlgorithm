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
#include <stdio.h>

using namespace std;

class ListNode
{
public:
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class LinkedList
{
public:
    ListNode *head, *tail;
    LinkedList() : head(nullptr), tail(nullptr) {}
    void push(ListNode *new_node)
    {
        if (head == nullptr)
        {
            head = new_node;
            tail = new_node;
        }
        else
        {
            tail->next = new_node;
            tail = tail->next;
        }
    }
};

class Solution
{
public:
    ListNode *reverseList(ListNode *head)
    {
        if (head == nullptr || head->next == nullptr)
        {
            return head;
        }
        ListNode *next_head = reverseList(head->next);
        head->next->next = head;
        head->next = nullptr;
        return next_head;
    }
};
int main(int argc, char const *argv[])
{
    LinkedList list;
    int N = 0;
    cin >> N;
    for (int i = 0; i < N; ++i)
    {
        int tmp = 0;
        cin >> tmp;
        ListNode *new_node = new ListNode(tmp);
        list.push(new_node);
    }
    list.head = Solution().reverseList(list.head);
    return 0;
}
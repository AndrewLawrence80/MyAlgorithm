// 将两个升序链表合并为一个新的 升序 链表并返回。新链表是通过拼接给定的两个链表的所有节点组成的。

// 示例 1：

// 输入：l1 = [1,2,4], l2 = [1,3,4]
// 输出：[1,1,2,3,4,4]

// 示例 2：

// 输入：l1 = [], l2 = []
// 输出：[]

// 示例 3：

// 输入：l1 = [], l2 = [0]
// 输出：[0]

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

ListNode *build_list()
{
    int N = 0;
    cin >> N;
    ListNode *head = nullptr, *tail = nullptr;
    for (int i = 0; i < N; ++i)
    {
        int x = 0;
        cin >> x;
        ListNode *new_node = new ListNode(x);
        if (head == nullptr)
        {
            head = new_node;
            tail = new_node;
        }
        else
        {
            tail->next = new_node;
            tail = new_node;
        }
    }
    return head;
}

class Solution
{
public:
    ListNode *mergeTwoLists(ListNode *list1, ListNode *list2)
    {
        ListNode *head1 = list1, *head2 = list2;
        ListNode *head = nullptr, *tail = nullptr;
        while (head1 || head2)
        {
            if (!head1 && head2)
            {
                while (head2)
                {
                    ListNode *new_node = new ListNode(head2->val);
                    if (!head)
                    {
                        head = new_node;
                        tail = new_node;
                    }
                    else
                    {
                        tail->next = new_node;
                        tail = new_node;
                    }
                    head2 = head2->next;
                }
            }
            else if (head1 && !head2)
            {
                while (head1)
                {
                    ListNode *new_node = new ListNode(head1->val);
                    if (!head)
                    {
                        head = new_node;
                        tail = new_node;
                    }
                    else
                    {
                        tail->next = new_node;
                        tail = new_node;
                    }
                    head1 = head1->next;
                }
            }
            else if (head1 && head2)
            {
                if (head1->val < head2->val)
                {
                    ListNode *new_node = new ListNode(head1->val);
                    if (!head)
                    {
                        head = new_node;
                        tail = new_node;
                    }
                    else
                    {
                        tail->next = new_node;
                        tail = new_node;
                    }
                    head1 = head1->next;
                }
                else
                {
                    ListNode *new_node = new ListNode(head2->val);
                    if (!head)
                    {
                        head = new_node;
                        tail = new_node;
                    }
                    else
                    {
                        tail->next = new_node;
                        tail = new_node;
                    }
                    head2 = head2->next;
                }
            }
            else
            {
                continue;
            }
        }
        return head;
    }
};

int main(int argc, char const *argv[])
{
    ListNode *list1 = build_list();
    ListNode *list2 = build_list();
    Solution().mergeTwoLists(list1,list2);
    return 0;
}
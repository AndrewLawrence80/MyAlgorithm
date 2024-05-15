// 给你两个 非空 的链表，表示两个非负的整数。它们每位数字都是按照 逆序 的方式存储的，并且每个节点只能存储 一位 数字。

// 请你将两个数相加，并以相同形式返回一个表示和的链表。

// 你可以假设除了数字 0 之外，这两个数都不会以 0 开头。

// 示例 1：

// 输入：l1 = [2,4,3], l2 = [5,6,4]
// 输出：[7,0,8]
// 解释：342 + 465 = 807.

// 示例 2：

// 输入：l1 = [0], l2 = [0]
// 输出：[0]

// 示例 3：

// 输入：l1 = [9,9,9,9,9,9,9], l2 = [9,9,9,9]
// 输出：[8,9,9,9,0,0,0,1]

// 提示：

//     每个链表中的节点数在范围 [1, 100] 内
//     0 <= Node.val <= 9
//     题目数据保证列表表示的数字不含前导零

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
    ListNode *addTwoNumbers(ListNode *l1, ListNode *l2)
    {
        ListNode *head1 = l1, *head2 = l2;
        ListNode *head = nullptr, *tail = nullptr;
        int div = 0;
        while (head1 || head2)
        {
            if (!head1 && head2)
            {
                int next_x = (head2->val + div) % 10;
                div = (head2->val + div) / 10;
                ListNode *new_node = new ListNode(next_x);
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
                head2 = head2->next;
            }
            else if (head1 && !head2)
            {
                int next_x = (head1->val + div) % 10;
                div = (head1->val + div) / 10;
                ListNode *new_node = new ListNode(next_x);
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
                head1 = head1->next;
            }
            else if (head1 && head2)
            {
                int next_x = (head1->val + head2->val + div) % 10;
                div = (head1->val + head2->val + div) / 10;
                ListNode *new_node = new ListNode(next_x);
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
                head1 = head1->next;
                head2 = head2->next;
            }
            else
            {
                continue;
            }
        }
        if (div)
        {
            ListNode *new_node = new ListNode(div);
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
};

int main(int argc, char const *argv[])
{
    ListNode *l1 = build_list();
    ListNode *l2 = build_list();
    Solution().addTwoNumbers(l1, l2);
    return 0;
}
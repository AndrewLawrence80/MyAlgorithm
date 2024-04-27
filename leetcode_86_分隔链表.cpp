// 给你一个链表的头节点 head 和一个特定值 x ，请你对链表进行分隔，使得所有 小于 x 的节点都出现在 大于或等于 x 的节点之前。

// 你应当 保留 两个分区中每个节点的初始相对位置。

// 输入：head = [1,4,3,2,5,2], x = 3
// 输出：[1,2,2,4,3,5]

// 输入：head = [2,1], x = 2
// 输出：[1,2]

#include <iostream>
#include <stdio.h>
#include <vector>

using namespace std;

int N = 0, x = 0;
vector<int> arr;
void get_input()
{
    cin >> N;
    for (int i = 0; i < N; ++i)
    {
        int tmp = 0;
        cin >> tmp;
        arr.push_back(tmp);
    }
    cin >> x;
}

class ListNode
{
public:
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution
{
public:
    ListNode *partition(ListNode *head, int x)
    {
        vector<int> arr1;
        vector<int> arr2;
        ListNode *current = head;
        while (current != nullptr)
        {
            if (current->val < x)
            {
                arr1.push_back(current->val);
            }
            else
            {
                arr2.push_back(current->val);
            }
            current = current->next;
        }
        ListNode *nhead = nullptr;
        ListNode *ntail = nhead;
        for (int i = 0; i < arr1.size(); ++i)
        {
            ListNode *newNode = new ListNode(arr1[i]);
            if (nhead == nullptr)
            {
                nhead = newNode;
                ntail = newNode;
            }
            else
            {
                ntail->next = newNode;
                ntail = newNode;
            }
        }
        for (int i = 0; i < arr2.size(); ++i)
        {
            ListNode *newNode = new ListNode(arr2[i]);
            if (nhead == nullptr)
            {
                nhead = newNode;
                ntail = newNode;
            }
            else
            {
                ntail->next = newNode;
                ntail = newNode;
            }
        }
        return nhead;
    }
};

ListNode *build(vector<int> &array)
{
    ListNode *head = nullptr;
    ListNode *tail = head;
    for (int i = 0; i < array.size(); ++i)
    {
        ListNode *newNode = new ListNode(array[i]);
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

int main(int argc, char const *argv[])
{
    get_input();
    ListNode *head = build(arr);
    ListNode *nhead=Solution().partition(head, x);
    return 0;
}
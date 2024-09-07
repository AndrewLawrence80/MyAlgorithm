// 代码中已指定的类名、方法名、参数名，请勿修改，直接返回方法规定的值即可

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

ListNode *buildList(vector<int> a)
{
    ListNode *head = nullptr, *tail = nullptr;
    for (int i = 0; i < a.size(); ++i)
    {
        ListNode *newNode = new ListNode(a[i]);
        if (head == nullptr)
        {
            head = newNode;
            tail = newNode;
        }
        else
        {
            tail->next = newNode;
            tail = tail->next;
        }
    }
    return head;
}

class Solution
{
public:
    ListNode *reverseList(ListNode *head)
    {
        ListNode *prev = nullptr, *currentHead = head;
        while (currentHead)
        {
            ListNode *next = currentHead->next;
            currentHead->next = prev;
            prev = currentHead;
            currentHead = next;
        }
        return head;
    }
    ListNode *mergeList(ListNode *headA, ListNode *headB)
    {
        bool flagA = true;
        ListNode *newHead = nullptr, *newTail = nullptr;
        while (headA && headB)
        {
            if (flagA)
            {
                if (newHead = nullptr)
                {
                    newHead = headA;
                    newTail = headA;
                    headA = headA->next;
                    flagA = false;
                }
                else
                {
                    newTail->next = headA;
                    headA = headA->next;
                    flagA = false;
                }
            }
            else
            {
                newTail->next = headB;
                headB = headB->next;
                flagA = true;
            }
        }
        while (headA)
        {
            newTail->next = headA;
            headA = headA->next;
        }
        while (headB)
        {
            newTail->next = headB;
            headB = headB->next;
        }
        return newHead;
    }
    void reorderList(ListNode *head)
    {
        ListNode *slow = head, *fast = head;
        while (fast)
        {
            fast = fast->next;
            fast = fast->next;
            slow = slow->next;
        }
        ListNode *tHead = reverseList(slow);
        ListNode *sHead = mergeList(head->next, tHead);
        head->next = sHead;
    }
};

void printList(ListNode *head)
{
    while (head)
    {
        cout << head->val << endl;
        head = head->next;
    }
}

int main(int argc, char const *argv[])
{
    int n = 0;
    cin >> n;
    vector<int> a(n, 0);
    for (int i = 0; i < n; ++i)
    {
        cin >> a[i];
    }
    ListNode *head = buildList(a);
    Solution().reorderList(head);
    return 0;
}

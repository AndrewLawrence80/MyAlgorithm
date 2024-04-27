#include <iostream>
#include <stdio.h>
#include <vector>

using namespace std;

class ListNode
{
public:
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(nullptr) {}
};

struct List
{
    ListNode *head;
    ListNode *tail;
};

List *build(vector<int> &arr)
{
    ListNode *head = nullptr;
    ListNode *tail = nullptr;
    for (int i = 0; i < arr.size(); ++i)
    {
        ListNode *newNode = new ListNode(arr[i]);
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
    return new List{head, tail};
}

void addCycle(List *list)
{
    list->tail->next = list->head->next;
}

class Solution
{
public:
    ListNode *detectCycle(ListNode *head)
    {
        ListNode *slow = head, *fast = head;
        while (fast != nullptr && fast->next != nullptr)
        {
            fast = fast->next->next;
            slow = slow->next;
            if (fast == slow)
            {
                break;
            }
        }
        if (fast == nullptr || fast->next == nullptr)
        {
            return nullptr;
        }
        else
        {
            slow = head;
            while (slow != fast)
            {
                fast = fast->next;
                slow = slow->next;
            }
            return slow;
        }
    }
};

int main(int argc, char const *argv[])
{
    vector<int> arr{3, 2, 0, -4};
    List *list = build(arr);
    addCycle(list);
    ListNode *cycleHead = Solution().detectCycle(list->head);
    cout << cycleHead->val;
    return 0;
}
// 给你一个单链表的头节点 head ，请你判断该链表是否为回文链表。
// 如果是，返回 true ；否则，返回 false 。

// 示例 1：

// 输入：head = [1,2,2,1]
// 输出：true

// 示例 2：

// 输入：head = [1,2]
// 输出：false

// 提示：

//     链表中节点数目在范围[1, 105] 内
//     0 <= Node.val <= 9

// 进阶：你能否用 O(n) 时间复杂度和 O(1) 空间复杂度解决此题？

#include <iostream>
#include <vector>
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

ListNode *buildList()
{
    ListNode *head = nullptr, *tail = nullptr;
    int N = 0;
    cin >> N;
    for (size_t i = 0; i < N; i++)
    {
        int x;
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
    vector<int> pre_order;
    vector<int> post_order;
    void dfs(ListNode *current_head)
    {
        if (current_head != nullptr)
        {
            pre_order.push_back(current_head->val);
            dfs(current_head->next);
            post_order.push_back(current_head->val);
        }
    }
    bool isPalindrome(ListNode *head)
    {
        dfs(head);
        return pre_order == post_order;
    }
};

int main(int argc, char const *argv[])
{
    ListNode *head = buildList();
    cout << Solution().isPalindrome(head);
    return 0;
}
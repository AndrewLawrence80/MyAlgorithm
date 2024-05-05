// 请你设计并实现一个满足  LRU (最近最少使用) 缓存 约束的数据结构。
// 实现 LRUCache 类：

//     LRUCache(int capacity) 以 正整数 作为容量 capacity 初始化 LRU 缓存
//     int get(int key) 如果关键字 key 存在于缓存中，则返回关键字的值，否则返回 -1 。
//     void put(int key, int value) 如果关键字 key 已经存在，则变更其数据值 value ；如果不存在，则向缓存中插入该组 key-value 。如果插入操作导致关键字数量超过 capacity ，则应该 逐出 最久未使用的关键字。

// 函数 get 和 put 必须以 O(1) 的平均时间复杂度运行。

// 示例：

// 输入
// ["LRUCache", "put", "put", "get", "put", "get", "put", "get", "get", "get"]
// [[2], [1, 1], [2, 2], [1], [3, 3], [2], [4, 4], [1], [3], [4]]
// 输出
// [null, null, null, 1, null, -1, null, -1, 3, 4]

// 解释
// LRUCache lRUCache = new LRUCache(2);
// lRUCache.put(1, 1); // 缓存是 {1=1}
// lRUCache.put(2, 2); // 缓存是 {1=1, 2=2}
// lRUCache.get(1);    // 返回 1
// lRUCache.put(3, 3); // 该操作会使得关键字 2 作废，缓存是 {1=1, 3=3}
// lRUCache.get(2);    // 返回 -1 (未找到)
// lRUCache.put(4, 4); // 该操作会使得关键字 1 作废，缓存是 {4=4, 3=3}
// lRUCache.get(1);    // 返回 -1 (未找到)
// lRUCache.get(3);    // 返回 3
// lRUCache.get(4);    // 返回 4

// 提示：

//     1 <= capacity <= 3000
//     0 <= key <= 10000
//     0 <= value <= 105
//     最多调用 2 * 105 次 get 和 put

// 使用哈希+双向链表，哈希表的K,V分别是键值和链表结点

#include <iostream>
#include <unordered_map>

using namespace std;

class Node
{
public:
    int key;
    int value;
    Node *prev;
    Node *next;
    Node() : key(0), value(0), prev(nullptr), next(nullptr) {}
    Node(int k, int v) : key(k), value(v), prev(nullptr), next(nullptr) {}
};
class DLinkedList
{
public:
    Node *head, *tail;
    int size;
    DLinkedList()
    {
        head = new Node();
        tail = new Node();
        head->next = tail;
        tail->prev = head;
        size = 0;
    }
    void push_head(Node *new_node)
    {
        new_node->next = head->next;
        new_node->prev = head;
        head->next->prev = new_node;
        head->next = new_node;
        ++size;
    }
    void push_tail(Node *new_node)
    {
        new_node->next = tail;
        new_node->prev = tail->prev;
        tail->prev->next = new_node;
        tail->prev = new_node;
        ++size;
    }
    void delete_node(Node *node)
    {
        node->prev->next = node->next;
        node->next->prev = node->prev;
        delete node;
        --size;
    }
    Node *get_tail()
    {
        return tail->prev;
    }
    void pop_back()
    {
        Node *temp = tail->prev;
        temp->prev->next = tail;
        tail->prev = temp->prev;
        delete temp;
        --size;
    }
};
class LRUCache
{
public:
    unordered_map<int, Node *> cache;
    DLinkedList list;
    int capacity;
    LRUCache() {}
    LRUCache(int capacity)
    {
        this->capacity = capacity;
    }
    int get(int key)
    {
        if (!cache.count(key))
        {
            return -1;
        }
        else
        {
            Node *node = cache[key];
            int k = node->key;
            int v = node->value;
            list.delete_node(node);
            cache.erase(k);
            Node *new_node = new Node(k, v);
            list.push_head(new_node);
            cache[key] = new_node;
            return v;
        }
    }
    void put(int key, int value)
    {
        if (!cache.count(key))
        {
            Node *new_node = new Node(key, value);
            list.push_head(new_node);
            cache[key] = new_node;
            if (list.size > capacity)
            {
                Node* tail=list.get_tail();
                int key=tail->key;
                list.pop_back();
                cache.erase(key);
            }
        }
        else
        {
            Node *node = cache[key];
            list.delete_node(node);
            cache.erase(key);
            Node *new_node = new Node(key, value);
            list.push_head(new_node);
            cache[key] = new_node;
        }
    }
};

int main(int argc, char const *argv[])
{
    LRUCache cache(2);
    // cache.put(1, 1);
    // cache.put(2, 2);
    // cout << cache.get(1);
    // cache.put(3, 3);
    // cout << cache.get(2);
    // cache.put(4, 4);
    // cout << cache.get(1);
    // cout << cache.get(3);
    // cout << cache.get(4);
    cache.put(2, 1);
    cache.put(1, 1);
    cout << cache.get(2);
    cache.put(4, 1);
    cout << cache.get(1);
    cout << cache.get(2);
    return 0;
}

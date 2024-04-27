/*
给定字符和频率，构建huffman树并输出字符对应的编码
输入
a b c d e f
45 16 13 12 9 5
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

class HeapNode
{
public:
    char c;
    int freq;
    HeapNode *left;
    HeapNode *right;
    HeapNode();
    HeapNode(char c, int freq);
};
HeapNode::HeapNode()
{
    c = 0;
    freq = 0;
    left = NULL;
    right = NULL;
}
HeapNode::HeapNode(char c, int freq)
{
    this->c = c;
    this->freq = freq;
    left = NULL;
    right = NULL;
}
class MinHeap
{
private:
    HeapNode **heap;
    long capacity;
    long size;
    void swap(long idx_a, long idx_b);
    void heapify(long idx);

public:
    MinHeap();
    MinHeap(HeapNode *node_array[], long size);
    ~MinHeap();
    HeapNode *get_top();
    bool pop_top();
    void insert(HeapNode *new_node);
    void print();
    bool empty();
    long get_size();
};
MinHeap::MinHeap()
{
    heap = NULL;
    capacity = 0;
    size = 0;
}
MinHeap::MinHeap(HeapNode *node_array[], long size)
{
    capacity = 1 << (long)ceil(log2(size));
    heap = new HeapNode *[capacity];
    memcpy(heap, node_array, sizeof(HeapNode *) * size);
    this->size = size;
    for (long i = (size - 1) / 2; i >= 0; --i)
    {
        heapify(i);
    }
}
MinHeap::~MinHeap()
{
    for (int i = 0; i < capacity; ++i)
    {
        if (heap[i] != NULL)
        {
            delete heap[i];
        }
    }
    delete[] heap;
}
void MinHeap::swap(long idx_a, long idx_b)
{
    HeapNode *temp = heap[idx_a];
    heap[idx_a] = heap[idx_b];
    heap[idx_b] = temp;
}
void MinHeap::heapify(long idx)
{
    long min_idx = idx;
    long left_idx = 2 * idx + 1;
    long right_idx = 2 * idx + 2;
    if (left_idx < size && heap[left_idx]->freq < heap[min_idx]->freq)
    {
        min_idx = left_idx;
    }
    if (right_idx < size && heap[right_idx]->freq < heap[min_idx]->freq)
    {
        min_idx = right_idx;
    }
    if (min_idx != idx)
    {
        swap(min_idx, idx);
        heapify(min_idx);
    }
}
HeapNode *MinHeap::get_top()
{
    HeapNode *tmp_node = new HeapNode();
    tmp_node->c = heap[0]->c;
    tmp_node->freq = heap[0]->freq;
    tmp_node->left = heap[0]->left;
    tmp_node->right = heap[0]->right;
    return tmp_node;
}
bool MinHeap::pop_top()
{
    if (size == 0)
    {
        return false;
    }
    swap(0, size - 1);
    size--;
    heapify(0);
    return true;
}
void MinHeap::insert(HeapNode *new_node)
{
    if (size >= capacity)
    {
        long prev_capacity = capacity;
        capacity *= 2;
        HeapNode **new_heap = new HeapNode *[capacity];
        memcpy(new_heap, heap, size * sizeof(HeapNode *));
        for (long i = 0; i < prev_capacity; ++i)
        {
            if (heap[i] != NULL)
            {
                delete heap[i];
            }
        }
        delete[] heap;
        heap = new_heap;
    }
    ++size;
    int i = size - 1;
    while (i > 0 && new_node->freq < heap[(i - 1) / 2]->freq)
    {
        heap[i] = heap[(i - 1) / 2];
        i = (i - 1) / 2;
    }
    heap[i] = new_node;
}
void MinHeap::print()
{
    for (int i = 0; i < size; ++i)
    {
        printf("%c %d\n", heap[i]->c, heap[i]->freq);
    }
}
bool MinHeap::empty()
{
    return size == 0;
}
long MinHeap::get_size()
{
    return size;
}
class HuffmanTree
{
private:
    HeapNode *root;
    void delete_tree(HeapNode *node);

public:
    HuffmanTree();
    HuffmanTree(MinHeap &min_heap);
    void from(MinHeap &min_heap);
    ~HuffmanTree();
};
HuffmanTree::HuffmanTree()
{
    root = NULL;
}
HuffmanTree::HuffmanTree(MinHeap &min_heap)
{
    HuffmanTree();
    from(min_heap);
}
void HuffmanTree::from(MinHeap &min_heap)
{
    while (min_heap.get_size() != 1)
    {
        HeapNode *tmp_root = new HeapNode();
        HeapNode *left = min_heap.get_top();
        min_heap.pop_top();
        HeapNode *right = min_heap.get_top();
        min_heap.pop_top();
        tmp_root->freq = left->freq + right->freq;
        tmp_root->left = left;
        tmp_root->right = right;
        min_heap.insert(tmp_root);
    }
    root = min_heap.get_top();
}
void HuffmanTree::delete_tree(HeapNode *node)
{
    if (node == NULL)
    {
        return;
    }
    delete_tree(node->left);
    delete_tree(node->right);
    delete node;
}
HuffmanTree::~HuffmanTree()
{
    delete_tree(root);
}
int main(int argc, char const *argv[])
{
    HeapNode *nodes[6] = {new HeapNode('a', 45), new HeapNode('b', 16), new HeapNode('c', 13), new HeapNode('d', 12), new HeapNode('e', 9), new HeapNode('f', 5)};
    MinHeap min_heap(nodes, 6);
    HuffmanTree huffman_tree(min_heap);
    return 0;
}

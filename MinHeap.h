#ifndef MINHEAP_H
#define MINHEAP_H

#include <vector>

class Minheap {
public:
    Minheap();
    void insert(int value);
    int getMin();
    void deleteMin();
    int getSize();

private:
    std::vector<int> heap;
    void heapifyUp(int index);
    void heapifyDown(int index);
};

#endif // MINHEAP_H

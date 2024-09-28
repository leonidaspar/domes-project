#ifndef MAXHEAP_H
#define MAXHEAP_H

#include <vector>

class Maxheap{
public:
    Maxheap();
    void insert(int value);
    int getMax();
    void deleteMax();
    int getSize();
private:
    std::vector<int> heap;
    void heapifyUp(int index);
    void heapifyDown(int index);

};


#endif

#include "MaxHeap.h"

Maxheap::Maxheap(){}

void Maxheap::insert(int value) {
    heap.push_back(value);
    heapifyUp(heap.size() - 1);
}
int Maxheap::getMax() {
    if (heap.empty()) {
        return -1; // Indicate empty heap
    }
    return heap.front();
}

void Maxheap::deleteMax() {
    if (heap.empty()) {
        return; // Nothing to delete
    }
    heap[0] = heap.back();
    heap.pop_back();
    heapifyDown(0);
}

int Maxheap::getSize() {
    return heap.size();
}

void Maxheap::heapifyUp(int index) {
    int parentIndex = (index - 1) / 2;
    while (index > 0 && heap[index] > heap[parentIndex]) {
        std::swap(heap[index], heap[parentIndex]);
        index = parentIndex;
        parentIndex = (index - 1) / 2;
    }
}

void Maxheap::heapifyDown(int index) {
    int leftChildIndex = 2 * index + 1;
    int rightChildIndex = 2 * index + 2;
    int largestIndex = index;

    if (leftChildIndex < heap.size() && heap[leftChildIndex] > heap[largestIndex]) {
        largestIndex = leftChildIndex;
    }

    if (rightChildIndex < heap.size() && heap[rightChildIndex] > heap[largestIndex]) {
        largestIndex = rightChildIndex;
    }

    if (largestIndex != index) {
        std::swap(heap[index], heap[largestIndex]);
        heapifyDown(largestIndex);
    }
}
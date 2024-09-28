#include "Minheap.h"

Minheap::Minheap() {}

void Minheap::insert(int value) {
    heap.push_back(value);
    heapifyUp(heap.size() - 1);
}

int Minheap::getMin() {
    if (heap.empty()) {
        return -1; // Indicate empty heap
    }
    return heap.front();
}

void Minheap::deleteMin() {
    if (heap.empty()) {
        return; // Nothing to delete
    }
    heap[0] = heap.back();
    heap.pop_back();
    heapifyDown(0);
}

int Minheap::getSize() {
    return heap.size();
}

void Minheap::heapifyUp(int index) {
    int parentIndex = (index - 1) / 2;
    while (index > 0 && heap[index] < heap[parentIndex]) {
        std::swap(heap[index], heap[parentIndex]);
        index = parentIndex;
        parentIndex = (index - 1) / 2;
    }
}

void Minheap::heapifyDown(int index) {
    int leftChildIndex = 2 * index + 1;
    int rightChildIndex = 2 * index + 2;
    int smallestIndex = index;

    if (leftChildIndex < heap.size() && heap[leftChildIndex] < heap[smallestIndex]) {
        smallestIndex = leftChildIndex;
    }

    if (rightChildIndex < heap.size() && heap[rightChildIndex] < heap[smallestIndex]) {
        smallestIndex = rightChildIndex;
    }

    if (smallestIndex != index) {
        std::swap(heap[index], heap[smallestIndex]);
        heapifyDown(smallestIndex);
    }
}

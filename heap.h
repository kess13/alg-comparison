#ifndef HEAP_H
#define HEAP_H
#include <iostream>
#include <vector>
using namespace std;
#include <algorithm>
void heapify(vector<int> &vec, int i, int size)
{
    int CurrentElIndex = i;
    int LeftChild = 2 * i + 1;
    int RightChild = 2 * i + 2;
    int SwappedLeft = 0;
    int SwappedRight = 0;
    bool Left = false;
    bool Right = false;
    if (LeftChild < size && vec[LeftChild] > vec[CurrentElIndex])
    {
        swap(vec[CurrentElIndex], vec[LeftChild]);
        SwappedLeft = LeftChild;
        Left = true;
    }

    if (RightChild < size && vec[RightChild] > vec[CurrentElIndex])
    {
        swap(vec[CurrentElIndex], vec[RightChild]);
        SwappedRight = RightChild;
        Right = true;
    }
    if (Left)
        heapify(vec, SwappedLeft, size);

    if (Right)
        heapify(vec, SwappedRight, size);
}

void MakeHeap(vector<int> &vec, int heap_size)
{
    for (int i = heap_size / 2 - 1; i >= 0; i--)
    {
        heapify(vec, i, heap_size);
    }
}

void MainSort(vector<int> &vec, int heap_size)
{
    MakeHeap(vec, heap_size);
    // First, we swap the top with the last element in the array,
    // and we decrease the size of the heap.
    // This in almost all cases destroys the heap property, so we have to fix it, this time from the top to the bottom.
    for (int i = heap_size - 1; i >= 0; i--)
    {
        swap(vec[0], vec[i]);
        heapify(vec, 0, i);
    }
}

#endif
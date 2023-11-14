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
    int largestChild=i;

    if ( LeftChild < size && RightChild < size )
    {
       if (vec[LeftChild] > vec[RightChild])
        {
            largestChild = LeftChild;
        }
        else
        {
            largestChild = RightChild;
        }
    }
 
if (vec[CurrentElIndex]<vec[largestChild])
{
      swap(vec[CurrentElIndex], vec[largestChild]);
       heapify(vec, largestChild, size);
}
    
}

void MakeHeap(vector<int> &vec, int heap_size)
{
    for (int i = heap_size / 2 - 1; i >= 0; i--) // start with the last parent that has children
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
    while (heap_size-- > 0)
    {
        swap(vec[0], vec[heap_size]);
        heapify(vec, 0, heap_size);
    }
}

#endif
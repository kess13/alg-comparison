#ifndef HYBRID_H
#define HYBRID_H
#include <vector>
#include <iostream>

using namespace std;

void quick(vector<int> &vec, int start, int end, int size)
{

    if (start >= end || size < 10)
        return;

    int pivot = vec[start + (end - start) / 2];
    int left = start;
    int right = end;

    while (left <= right)
    {
        while (left <= right && vec[left] < pivot)
        {
            left++;
        }

        while (left <= right && vec[right] > pivot)
        {
            right--;
        }

        if (left <= right)
        {
            swap(vec[left], vec[right]);
            left++;
            right--;
        }
    }
    size--;
    quick(vec, start, right, size);
    quick(vec, left, end, size);
}
void insertionsortforhybrid(vector <int> &vec)
{
    for (int currentIndex = 1; currentIndex < 10; currentIndex++)
    {
        int val = vec[currentIndex];
        int insertionIndex = currentIndex;

        while (insertionIndex > 0 && vec[insertionIndex - 1] > val)
        {
            vec[insertionIndex] = vec[insertionIndex - 1];
            insertionIndex--;
        }

        vec[insertionIndex] = val;
    }
}


void hybrid(vector<int> &vec)
{
    int size = vec.size();
    quick(vec, 0, size - 1, size);
    insertionsortforhybrid(vec);
}
#endif
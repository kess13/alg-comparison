#ifndef INSERTION_SORT_H
#define INSERTION_SORT_H
#include <iostream>
#include <vector>
using namespace std;

void insertionsort(vector<int> &array)
{
    int arrayLength = array.size();

    for (int currentIndex = 1; currentIndex < arrayLength; currentIndex++)
    {
        int insertionIndex = currentIndex;

        while (insertionIndex > 0 && array[insertionIndex - 1] > array[insertionIndex])
        {
            swap(array[insertionIndex], array[insertionIndex - 1]);
            insertionIndex--;
        }
    }
}
#endif

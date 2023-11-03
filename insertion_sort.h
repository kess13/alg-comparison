#ifndef INSERTION_SORT_H
#define INSERTION_SORT_H
#include <iostream>
#include <vector>
using namespace std;
#include <algorithm>
void insertionsort(vector<int> &array, int arrayLength)
{

    for (int currentIndex = 1; currentIndex < arrayLength; currentIndex++)
    {
        int currentValue = array[currentIndex];
        int insertionIndex = currentIndex;

        while (insertionIndex > 0 && array[insertionIndex - 1] > currentValue)
        {
            array[insertionIndex] = array[insertionIndex - 1];
            insertionIndex--;
        }

        array[insertionIndex] = currentValue;
    }
}
#endif
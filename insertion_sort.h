#ifndef INSERTION_SORT_H
#define INSERTION_SORT_H
#include <iostream>
#include <vector>
using namespace std;

void insertionsort(vector <int> &vec)
{
    for (int currentIndex = 1; currentIndex < vec.size(); currentIndex++)
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
#endif

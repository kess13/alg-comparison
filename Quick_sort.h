#ifndef QUICK_SORT_H
#define QUICK_SORT_H
#include <iostream>
#include <vector>
using namespace std;
#include <algorithm>

void quick(vector<int> &vec, int start, int end)
{

    if (start >= end)
        return;

    int pivot = vec[start + (end - start) / 2];
    int left = start;
    int right = end;

    while (left <= right)
    {
        while (vec[left] < pivot)
        {
            left++;
        }

        while (vec[right] > pivot)
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

    quick(vec, start, right);
    quick(vec, left, end);
}

#endif
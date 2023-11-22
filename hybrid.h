#ifndef HYBRID_H
#define HYBRID_H
#include <vector>
#include <iostream>

using namespace std;
void insertionsortforhybrid(vector <int> &vec , int indexfirst , int indexend )
{
    for (int currentIndex = indexfirst ; currentIndex < indexend; currentIndex++)// we sort first ten el anyway
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


void quicksortforhybrid(vector<int> &vec, int start, int end)
{
    
int size= end-start+1;
 if (size <= 10)
    {
        insertionsortforhybrid(vec, start ,end);
        return;
    }
    if (start >= end )
        return;


    int pivot = vec[start + (end - start) / 2];
    int pivotindex = start + (end - start) / 2;
    int left = start;
    int right = end;

    while (left <= right)
    {
        while (left <= right && vec[left] < pivot)
        {
           
            if (pivotindex- left<=10 )
            {
            insertionsortforhybrid(vec, left , pivotindex);
            break;
            }
             left++;
        }

        while (left <= right && vec[right] > pivot)
        {
            
             if (right - pivotindex<=10 )
             {
            insertionsortforhybrid(vec, pivot, right);
            break;
             }
             right--;
            
        }

        if (left <= right)
        {
            swap(vec[left], vec[right]);
            left++;
            right--;
        }
    }

    quick(vec, start, right );
    quick(vec, left, end);
}


void hybrid(vector<int> &vec)
{
    int size = vec.size();
    quicksortforhybrid(vec, 0, size - 1);
  
    
}
#endif
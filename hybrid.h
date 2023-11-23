#ifndef HYBRID_H
#define HYBRID_H
#include <vector>
#include <iostream>

using namespace std;
void insertionsortforhybrid(vector <int> &vec , int indexfirst , int indexend )
{
    for (int currentIndex = indexfirst+1 ; currentIndex <= indexend; currentIndex++)
    {
        int val = vec[currentIndex];
        int insertionIndex = currentIndex;

        while (insertionIndex > indexfirst && vec[insertionIndex - 1] > val)
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
 if (size <= 20)
    {
        insertionsortforhybrid(vec, start ,end);
        
    }
    if (start >= end )
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

    quicksortforhybrid(vec, start, right );
    quicksortforhybrid(vec, left, end);
}


void hybrid(vector<int> &vec)
{
    int size = vec.size();
    quicksortforhybrid(vec, 0, size - 1);
  
    
}
#endif
#ifndef RADIX_H
#define RADIX_H
#include <iostream>
#include <vector>
using namespace std;
#include <algorithm>
#include <string>
void countingsort(vector<int> &vec, int multiplier)
{
    if (vec.empty())
        return;

    
    vector<int> countarr( 10, 0);

    for (int i = 0; i< vec.size(); i++)
    {
        int digit = (vec[i]/multiplier)%10;
        countarr[digit]++;

    }
   
    for (int i = 1; i < 10; i++)
    {
        countarr[i] += countarr[i - 1];
    }

    vector<int> res(vec.size());
    for (int i = vec.size() - 1; i >= 0; i--)
    {
         int digit = (vec[i]/multiplier)%10;
        res[countarr[digit] - 1] = vec[i];
        countarr[digit]--;
    }
    vec = res;
}
void radix(vector<int> &vec)
{
    if (vec.empty())
        return;
    auto max = max_element(vec.begin(), vec.end());
    int maxel = *max;
    int length = 0;
    int temp = maxel;
    while (temp != 0)
    {
        temp /= 10;
        length++;
    }
    int multiplier = 1;
    for (int j = 0; j < length; j++)
    {
        countingsort(vec, multiplier);
        multiplier *= 10;
    }
}

#endif
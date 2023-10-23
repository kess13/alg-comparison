#include <iostream>
#include <vector>
using namespace std;

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

    quick(vec, 0, right);
    quick(vec, left, end);
}

int main()
{
    vector<int> vec{1, 5, 55, 251, 9, 33, 43, 77, 22,89, 24, 46, 58, 20, 37, 94, 72, 86, 14, 35, 77, 96, 22, 41, 63, 87, 10,22};
    int start = 0;
    int end = vec.size() - 1;
    quick(vec, start, end);

    for (size_t i = 0; i < vec.size(); i++)
    {
        cout << vec[i] << " ";
    }
    
    return 0;
}

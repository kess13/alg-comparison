#include <iostream>
#include <vector>
using namespace std;
#include <algorithm>
#include <chrono>
#include <thread> 
#include <cstdlib>

vector<int> generateRandomArray(int size) {
    vector<int> vec(size);
    for (int i = 0; i < size; i++) {
        vec[i] = rand(); 
    }
    return vec;
}
vector<int> SortedArr(int size) {
    vector<int> vec(size);
    for (int i = 0; i < size; i++) {
        vec[i] = i; 
    }
    return vec;
}
vector<int> ReversedSortedArr(int size) {
    vector<int> vec(size);
    for (int i = size-1;  i>=0 ; i--) {
        vec[i] = i; 
    }
    return vec;
}

struct Timer
{
std::chrono::high_resolution_clock::time_point start, end;
chrono::duration<float> duration;
Timer()
{
start =chrono::high_resolution_clock::now();
}

~Timer()
{
end = chrono::high_resolution_clock::now();
duration = end - start;
float ms = duration.count() * 1000.0f;
cout<<"Timer took "<< ms <<"ms"<<endl;
}
};
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

int main()
{
    Timer timer;
    vector <int> vec= generateRandomArray(10000);
    int start = 0;
    int end = vec.size() - 1;
    quick(vec, start, end);

 
    
    return 0;
}

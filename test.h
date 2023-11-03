#ifndef TEST_H
#define TEST_H

using namespace std;
#include <iostream>
#include <chrono>
#include <thread>
#include <cstdlib>
#include <vector>

vector<int> generateRandomArray(int size)
{
    vector<int> vec(size);
    for (int i = 0; i < size; i++)
    {
        vec[i] = rand();
    }
    return vec;
}
vector<int> SortedArr(int size)
{
    vector<int> vec(size);
    for (int i = 0; i < size; i++)
    {
        vec[i] = i;
    }
    return vec;
}
vector<int> ReversedSortedArr(int size)
{
    vector<int> vec(size);
    for (int i = size - 1; i >= 0; i--)
    {
        vec[i] = i;
    }
    return vec;
}

struct Timer
{
    std::chrono::high_resolution_clock::time_point start, end;
    std::chrono::duration<float> duration;
    float totalTime;

    Timer()
    {
        start = std::chrono::high_resolution_clock::now();
        totalTime = 0.0;
    }

    void stop()
    {
        end = std::chrono::high_resolution_clock::now();
        duration = end - start;
        float ms = duration.count() * 1000.0f;
        totalTime += ms;
    }

    ~Timer()
    {
        cout << "Total time: " << totalTime << "ms" << endl;
    }
};

#endif
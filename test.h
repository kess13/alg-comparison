#ifndef TEST_H
#define TEST_H

using namespace std;
#include <iostream>
#include <chrono>
#include <thread>
#include <cstdlib>
#include <vector>
#include <random>

vector<int> generateRandomArray(int size)
{
    vector<int> vec(size);
    random_device rd;
    mt19937 gen(rd());

    uniform_int_distribution<int> dist(0, 1000000);
    for (int i = 0; i < size; i++)
    {
        vec[i] = dist(gen);
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
    float max = 0.0f;
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
        if (max < ms)
            max = ms;
    }

    ~Timer()
    {
        cout << "Total time: " << totalTime << "ms" << endl;
        cout << "The maximum duration is " << max << endl;
    }
};

#endif
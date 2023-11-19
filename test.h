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

struct Timer
{
    std::chrono::high_resolution_clock::time_point start, end;
    std::chrono::duration<float> duration;
    float totalTimeQuick;
    float totalTimeRadix;
    float totalTimeInsertion;
    float totalTimeHeap;
    float totalTimeHybrid = 0.0;
    float max = 0.0f;
    Timer()
    {
        start = std::chrono::high_resolution_clock::now();
        totalTimeQuick = 0.0;
        totalTimeRadix = 0.0;
        totalTimeInsertion = 0.0;
        totalTimeHeap = 0.0;
        totalTimeHybrid = 0.0;
    }

    void startt()
    {
        start = std::chrono::high_resolution_clock::now();
    }

    void stopQuick()
    {
        end = std::chrono::high_resolution_clock::now();
        duration = end - start;
        float ms = duration.count() * 1000.0f;
        totalTimeQuick += ms;
    }

    void stopRadix()
    {
        end = std::chrono::high_resolution_clock::now();
        duration = end - start;
        float ms = duration.count() * 1000.0f;
        totalTimeRadix += ms;
    }

    void stopInsertion()
    {
        end = std::chrono::high_resolution_clock::now();
        duration = end - start;
        float ms = duration.count() * 1000.0f;
        totalTimeInsertion += ms;
    }
    void stopHeap()
    {
        end = std::chrono::high_resolution_clock::now();
        duration = end - start;
        float ms = duration.count() * 1000.0f;
        totalTimeHeap += ms;
    }

     void stopHybrid()
    {
        end = std::chrono::high_resolution_clock::now();
        duration = end - start;
        float ms = duration.count() * 1000.0f;
        totalTimeHybrid += ms;
    }
};

#endif
#include <iostream>
#include <vector>
using namespace std;
#include <algorithm>
#include "insertion_sort.h"
#include "Quick_sort.h"
#include "radix.h"
#include "heap.h"
#include "test.h"

int main()
{
    Timer timer;
    int sortedRightTimes = 0;
    int AmountTests = 10;
    for (int i = 0; i < AmountTests; i++)
    {
        vector<int> vec = generateRandomArray(10000);
        MainSort(vec, vec.size());
        if (is_sorted(vec.begin(), vec.end()))
            sortedRightTimes++;
        timer.stop(); 
    }
    if (AmountTests==sortedRightTimes)
    cout <<"All passed" << endl;
    cout << "Average Execution Time: " << timer.totalTime/ AmountTests  << "ms" << endl;
}

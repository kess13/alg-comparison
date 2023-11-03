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
    const int AmountOfTests = 100;
    vector<int> testSizes = {10, 20, 30, 40, 50, 60, 70, 80, 90, 100, 200, 300, 400, 500, 600, 700, 800, 900, 1000, 2000, 3000, 4000, 5000, 6000, 7000, 8000, 9000, 10000};
    for (int sizes : testSizes){
    for (int i = 0; i < AmountOfTests; i++)
    {
        vector<int> vec = SortedArr(sizes);
        MainSort(vec, vec.size());
        if (is_sorted(vec.begin(), vec.end()))
            sortedRightTimes++;
        timer.stop();
    }
    cout << "Average Execution Time for size "<<sizes << timer.totalTime / AmountOfTests << endl;
    }
    if (AmountOfTests*testSizes.size() == sortedRightTimes)
        cout << "All passed" << endl;
    
}

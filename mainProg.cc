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
    cout << "Quick_sort"
         << " Radix_sort"
         << " Insertion_sort"
         << " Heap_sort" << endl;
    vector<int> testSizes = {10, 20, 30, 40, 50, 60, 70, 80, 90, 100, 200, 300, 400, 500, 600, 700, 800, 900, 1000, 2000, 3000, 4000, 5000, 6000, 7000, 8000, 9000, 10000};
    for (int sizes : testSizes)
    {
        cout << sizes;
        vector<int> originalVec = generateRandomArray(sizes);
        for (int i = 0; i < AmountOfTests; i++)
        {
            vector<int> vec = originalVec; // Create a copy of the original vector
            timer.startt();
            quick(vec, 0, vec.size() - 1);
            timer.stopQuick();
            vec = originalVec;
            timer.startt();
            radix(vec);
            timer.stopRadix();
            vec = originalVec;
            timer.startt();
            insertionsort(vec);
            timer.stopInsertion();
            vec = originalVec;
            timer.startt();
            MainSort(vec, vec.size()); //  <-heap sort
            timer.stopHeap();
           
        }
        cout << " " << timer.totalTimeQuick / AmountOfTests << " " << timer.totalTimeRadix / AmountOfTests << " " << timer.totalTimeInsertion / AmountOfTests << " " << timer.totalTimeHeap / AmountOfTests << "\n ";
    }
   return 0;
   
}

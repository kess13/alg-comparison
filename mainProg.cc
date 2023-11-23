#include <iostream>
#include <vector>
using namespace std;
#include <algorithm>
#include "insertion_sort.h"
#include "Quick_sort.h"
#include "radix.h"
#include "heap.h"
#include "hybrid.h"
#include "test.h"

int main()
{
   
    int sortedRightTimes = 0;
    const int AmountOfTests = 100;
    cout << "  Quick_sort"
         << "   Radix_sort"
         << "   Insertion_sort"
         << "  Heap_sort" 
         <<"  Hybrid_sort" <<endl;
    vector<int> testSizes = {10,15, 20,25, 30, 35,40, 45, 50,55, 60,65,70,75,80, 90, 100, 200, 300, 400, 500, 600, 700, 800, 900, 1000, 2000, 3000, 4000, 5000, 6000, 7000, 8000, 9000, 10000};
    for (int sizes : testSizes)
    {
         Timer timer;
        cout << sizes;
        vector<int> originalVec = generateRandomArray(sizes);
        for (int i = 0; i < AmountOfTests; i++)
        {
            vector<int> vec = originalVec; 
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
            
             vec = originalVec;
             timer.startt();
             hybrid(vec);
             timer.stopHybrid();
         


        }
        cout << "  " << timer.totalTimeQuick / AmountOfTests << "  |  " << timer.totalTimeRadix / AmountOfTests << "  |  " << timer.totalTimeInsertion / AmountOfTests << "  |  " << timer.totalTimeHeap / AmountOfTests <<"  |  "<<timer.totalTimeHybrid/AmountOfTests<< "\n ";
    }
  
   return 0;
   
}

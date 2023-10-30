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
vector <int> vec = generateRandomArray(100);
radix(vec);
}
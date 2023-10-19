#include <iostream>
#include <vector>
using namespace std;
#include <algorithm>




void heapify(vector<int> &vec, int i, int size) {
    int CurrentElIndex = i;
    int LeftChild = 2 * i + 1;
    int RightChild = 2 * i + 2;
    
      
        if (LeftChild < size && vec[LeftChild] > vec[CurrentElIndex])
       { swap(vec[CurrentElIndex], vec[LeftChild]); 
       heapify(vec, CurrentElIndex , size);
       }

   
  if (RightChild < size && vec[RightChild] > vec[CurrentElIndex])
       { swap(vec[CurrentElIndex], vec[RightChild]);
heapify(vec, CurrentElIndex , size);
       }

      
}



void MakeHeap(vector<int> &vec, int heap_size) {
    for (int i = heap_size / 2 - 1; i >= 0; i--) {
        heapify(vec, i, heap_size);
    }
}

void MainSort(vector<int> &vec, int heap_size) {
    MakeHeap(vec, heap_size);
    for (int i = heap_size - 1; i >= 0; i--) {
        heapify(vec, i , heap_size-i);

    }
}

int main()
{
    vector<int> vec = {66,0, 1, 999, 83, 5, 42, 4, 0, 5545, 99};
    int heap_size = vec.size();  

    MainSort(vec, heap_size);
    

    for (int i : vec)
    {
        cout << " " << i;
    }

    return 0;
}

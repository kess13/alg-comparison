#include <iostream>
#include <vector>
using namespace std;
#include <algorithm>




void heapify(vector<int> &vec, int i, int size) {
    int CurrentEl = i;
    int LeftChild = 2 * i + 1;
    int RightChild = 2 * i + 2;
    
}



void MakeHeap(vector<int> &vec, int heap_size) {
    for (int i = heap_size / 2 - 1; i >= 0; i--) {
        heapify(vec, i, heap_size);
    }
    

    

}









int main()
{
    vector<int> vec = {0, 1, 9, 83, 335, 42, 4, 0, 5545, 8888};
    int heap_size = vec.size();  

    MakeHeap(vec, heap_size);

    for (int i : vec)
    {
        cout << " " << i;
    }

    return 0;
}

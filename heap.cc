#include <iostream>
#include <vector>
using namespace std;
#include <algorithm>




void heapify(vector<int> &vec, int i, int size) {
    int CurrentEl = i;
    int LeftChild = 2 * i + 1;
    int RightChild = 2 * i + 2;
    if (LeftChild < size && RightChild < size) {
        while (max(vec[LeftChild], vec[RightChild]) > vec[CurrentEl]) {
            if (vec[LeftChild] > vec[RightChild]) {
                if (vec[LeftChild] > vec[CurrentEl]) {
                    swap(vec[LeftChild], vec[CurrentEl]);
                }
            } else {
                if (vec[RightChild] > vec[CurrentEl]) {
                    swap(vec[CurrentEl], vec[RightChild]);
                }
            }
        }
    }
}



void MakeHeap(vector<int> &vec, int heap_size) {
    for (int i = heap_size / 2 - 1; i >= 0; i--) {
        heapify(vec, i, heap_size);
    }
    
    
    swap(vec[0], vec[heap_size - 1]);

}









int main()
{
    vector<int> vec = {0, 1, 9, 3, 335, 42, 4, 0, 555, 888};
    int heap_size = vec.size();  

    MakeHeap(vec, heap_size);

    for (int i : vec)
    {
        cout << " " << i;
    }

    return 0;
}

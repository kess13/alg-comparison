#include <iostream>
#include <vector>
using namespace std;
#include <algorithm>





void heapify(vector<int> &vec, int i, int size) {
    int CurrentElIndex = i;
    int LeftChild = 2 * i + 1;
    int RightChild = 2 * i + 2;
    int SwappedLeft=0;
    int SwappedRight = 0;
      bool Left=false;
      bool Right=false;
       if (LeftChild < size && vec[LeftChild] > vec[CurrentElIndex])
       { swap(vec[CurrentElIndex], vec[LeftChild]); 
       SwappedLeft = LeftChild;
       Left=true;
       }

   
  if (RightChild < size && vec[RightChild] > vec[CurrentElIndex])
       { swap(vec[CurrentElIndex], vec[RightChild]); 
       SwappedRight= RightChild;
       Right=true;
       }
     if (Left)
     heapify(vec,SwappedLeft, size);
      
     if (Right)
      heapify(vec,SwappedRight, size);

}




void MakeHeap(vector<int> &vec, int heap_size) {
    for (int i = heap_size / 2 - 1; i >= 0; i--) {
        heapify(vec, i, heap_size);
    
    }
}

void MainSort(vector<int> &vec, int heap_size) {
    MakeHeap(vec, heap_size);
    //First, we swap the top with the last element in the array, 
    //and we decrease the size of the heap. 
    //This in almost all cases destroys the heap property, so we have to fix it, this time from the top to the bottom.
    for (int i = heap_size - 1; i >= 0; i--) {
           swap(vec[0], vec[i]);
        heapify(vec, 0, i);
     

    }
}

int main()
{
vector<int> testVector1 = {3, 2, 1};
vector<int> testVector2 = {5, 7, 2, 9, 1, 3};
vector<int> testVector3 = {10, 9, 8, 7, 6, 5, 4, 3, 2, 1};
vector<int> testVector4 = {1, 1, 1, 1, 1, 1};
vector<int> testVector5 = {10, 20, 30, 40, 50, 60, 70, 80, 90, 100};
vector<int> testVector6 = {100, 90, 80, 70, 60, 50, 40, 30, 20, 10};
vector<int> testVector7 = {2};
vector<int> testVector8 = {}; 
 MainSort(testVector1, testVector1.size());
  MainSort(testVector2, testVector2.size());
   MainSort(testVector3, testVector3.size());
    MainSort(testVector4, testVector4.size());
     MainSort(testVector5, testVector5.size());
      MainSort(testVector6, testVector6.size());
       MainSort(testVector7, testVector7.size());
        MainSort(testVector8, testVector8.size());
 
if (is_sorted(testVector1.begin(),testVector1.end()))
{
cout<<"success! Vector 1 passed"<<endl;
}
if ( is_sorted(testVector2.begin(),testVector2.end()))
{
cout<<"success! Vector 2 passed"<<endl;
}
if (is_sorted(testVector3.begin(),testVector3.end()))
{
cout<<"success! Vector 3 passed"<<endl;
}
if (is_sorted(testVector4.begin(),testVector4.end()))
{
cout<<"success! Vector 4 passed"<<endl;
}
if (is_sorted(testVector5.begin(),testVector5.end()))
{
cout<<"success! Vector 5 passed"<<endl;
}
if (is_sorted(testVector6.begin(),testVector6.end()))
{
cout<<"success! Vector 6 passed"<<endl;
}
if (is_sorted(testVector7.begin(),testVector7.end()))
{
cout<<"success! Vector 7 passed"<<endl;
}
if ( is_sorted(testVector8.begin(),testVector8.end()))
{
cout<<"success! Vector 8 passed"<<endl;
}
return 0;
}

#include <iostream>
#include <vector>
using namespace std;
#include <algorithm>




void heapify(vector<int> &vec, int i)
{
    int size = vec.size()-i;
int CurrentEl=i;
int LeftChild = 2*i+1; // we need to make both children  be smaller than parent
int RightChild = 2*i+2;
if (LeftChild<size  && RightChild<size){
   while (max(vec[LeftChild],vec[RightChild])>vec[CurrentEl])
   {
        if (vec[LeftChild]>vec[RightChild])
        {
            if (vec[LeftChild]>vec[CurrentEl])
            
            swap(vec[LeftChild],vec[CurrentEl]);}
        else 
        {
              if (vec[RightChild]>vec[CurrentEl])
            swap(vec[CurrentEl],vec[RightChild]);
            
        } 


   }

}

}
void MakeHeap (int heap_size, vector<int> &vec)
{
for (int i = 0; i<heap_size; i++)
{
heapify(vec, i);
}
}








int main()
{

vector <int> vec = {0,1,9,3,35,42,4,0,55,8};
MakeHeap(vec.size(),vec);

for (int i : vec)
{
cout << " " <<i;

}

}
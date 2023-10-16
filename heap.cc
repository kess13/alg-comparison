#include <iostream>
#include <vector>
using namespace std;
#include <algorithm>

void MakeHeap (int heap_size, vector<int> vec)
{



}
void heapify(vector<int> &vec, int i)
{
int CurrentEl=i;
int LeftChild = 2*i+1; // we need to make both children  be smaller than parent 
int RightChild = 2*i+2;
    if (vec[LeftChild]>vec[RightChild])
   {
     if (vec[LeftChild]>vec[CurrentEl])
     swap(vec[LeftChild],vec[CurrentEl]);
   }

    if (vec[RightChild]>vec[LeftChild])
       { 
        
        if (vec[RightChild]>vec[CurrentEl])
         swap(vec[RightChild],vec[CurrentEl]);

       }


}

void heapsort(vector <int>&vec)
{
    
for (int i = 0; i < vec.size(); i++)
{
MakeHeap(vec.size()-i, vec);
}



}






int main()
{

vector <int> vec = {0,1,9,3,35,42,4,0,55,8};

heapsort(vec);

for (int i : vec)
{
cout << " " <<i;

}

}
#include <iostream>
#include <vector>
using namespace std;
#include <algorithm>
#include <chrono>
#include <thread> 
#include <cstdlib>

vector<int> generateRandomArray(int size) {
    vector<int> vec(size);
    for (int i = 0; i < size; i++) {
        vec[i] = rand(); 
    }
    return vec;
}
vector<int> SortedArr(int size) {
    vector<int> vec(size);
    for (int i = 0; i < size; i++) {
        vec[i] = i; 
    }
    return vec;
}
vector<int> ReversedSortedArr(int size) {
    vector<int> vec(size);
    for (int i = size-1;  i>=0 ; i--) {
        vec[i] = i; 
    }
    return vec;
}

struct Timer
{
std::chrono::high_resolution_clock::time_point start, end;
chrono::duration<float> duration;
Timer()
{
start =chrono::high_resolution_clock::now();
}

~Timer()
{
end = chrono::high_resolution_clock::now();
duration = end - start;
float ms = duration.count() * 1000.0f;
cout<<"Timer took "<< ms <<"ms"<<endl;
}
};
void insertionsort(vector<int> &vec)
{
    Timer timer;
       int temp = 0;
    for (int key = 1; key < vec.size(); key++)
    {
        int pos = 0;
        bool change = false;
        for (int ElemBefore = key - 1; ElemBefore >= 0; ElemBefore--) 
        {
            if (vec[ElemBefore] > vec[key])

            {
                pos = ElemBefore;
                change = true;
                temp = vec[key];
            }

           
        }
        if (change)
        {
            vec.erase(vec.begin() + key);
            vec.insert(vec.begin() + pos, temp);
        }
    }
}



  int main()
{
vector <int> large= generateRandomArray(10000);
insertionsort(large);
 

return 0;
}



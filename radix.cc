#include <iostream>
#include <vector>
using namespace std;
#include <algorithm>
#include <string>
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
void countingsort(vector<int> vec, vector<int> &MainVec) {
    if (vec.empty()) return;
    auto max = max_element(vec.begin(), vec.end());
    int maxel= *max;
    vector<int> countarr(maxel+1,0);

   for (int i=0; i <= maxel; i++)
{
countarr[i]=count(vec.begin(),  vec.end(), i);
}
    for (int i=1; i <= maxel; i++) {
        countarr[i] += countarr[i-1];
    }

    vector<int> res(vec.size());
    for (int i = vec.size()-1; i >= 0; i--) {
        res[countarr[vec[i]] - 1] = MainVec[i];
        countarr[vec[i]]--;
    }
    MainVec=res;
    
}
void radix(vector<int> &vec) {
    Timer timer;
     if (vec.empty()) return ;
    auto max = max_element(vec.begin(), vec.end());
    int maxel = *max;
    string maxDigit = to_string(maxel);
    vector<int> VecWithCutValues(vec);
    vector<int> VecForCountSort(vec.size());
int multiplier=1;
    for (int j = 0; j < maxDigit.length(); j++) {
            vector<int> VecWithCutValues(vec);
            multiplier*=10;

        for (int v = 0; v < vec.size(); v++) {
            int temp = VecWithCutValues[v] % multiplier;
            
            VecForCountSort[v] = temp;
        }

         countingsort(VecForCountSort,vec);
    }

    
}



int main()
{
vector <int> large= generateRandomArray(10000);
radix(large);
  
return 0;
}

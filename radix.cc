#include <iostream>
#include <vector>
using namespace std;
#include <algorithm>

vector<int> countingsort(vector<int> vec) {
    auto max = max_element(vec.begin(), vec.end());
    int maxel= *max;
    vector<int> countarr(maxel+1,0);//Initialize a countArray[] of length max+1 with all elements as 0. This array will be used for storing the occurrences of the elements of the input array.

   for (int i=0; i <= maxel; i++)
{
countarr[i]=count(vec.begin(),  vec.end(), i);
}
    for (int i=1; i <= maxel; i++) {
        countarr[i] += countarr[i-1];//We can calculate the cumulative frequency by adding the current value to the previous index value
    }

    vector<int> res(vec.size());
    for (int i = 0; i < vec.size(); i++) {
        res[countarr[vec[i]] - 1] = vec[i];
        countarr[vec[i]]--;
    }
    
    return res;
}

int main() {
    vector<int> vec = {0,1,7,6,6,3,9,3,5,2,4,0,6,8,5,6,7,8,2,1};
    vec = countingsort(vec);
    for (int i : vec) {
        cout << " " <<i;
    }
}

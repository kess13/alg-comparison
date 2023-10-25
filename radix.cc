#include <iostream>
#include <vector>
using namespace std;
#include <algorithm>
#include <string>
vector<int> countingsort(vector<int> vec, vector<int> &MainVec) {
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
vector<int> radix(vector<int> vec) {
    auto max = max_element(vec.begin(), vec.end());
    int maxel = *max;
    string maxDigit = to_string(maxel);
    vector<int> VecWithCutValues(vec);
    vector<int> VecForCountSort(vec.size());

    for (int j = 0; j < maxDigit.length(); j++) {
        for (int v = 0; v < vec.size(); v++) {
            int temp = VecWithCutValues[v] % 10;
            VecWithCutValues[v] = VecWithCutValues[v] / 10;
            VecForCountSort[v] = temp;
        }

         vec=(VecForCountSort,vec);
    }

    return vec;
}


int main() {
    vector<int> vec = {0,1,127,6,6,3333,9,3333,2229,9,9,9,39,5,12,4,0,6,8,5,6,7,38,2,1};
    vec = countingsort(vec);
    for (int i : vec) {
        cout << " " <<i;
    }
    if (is_sorted(vec.begin(), vec.end()))
    {
        cout << "  true" << endl;
        return 0;
    }
}
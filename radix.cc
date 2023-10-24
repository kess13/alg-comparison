#include <iostream>
#include <vector>
using namespace std;
#include <algorithm>
#include <string>
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

        vec = countingsort(vec);
    }

    return vec;
}


int main() {
    vector<int> vec = {3,2,1,0,213,123,14,12,31,14,12,431,41,23,1222,1};
    vec = radix(vec);
    for (int i : vec) {
        cout << " " <<i;
    }
     if (is_sorted(vec.begin(), vec.end()))
    {
        cout << "  true" << endl;
        return 0;
    }
}

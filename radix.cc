#include <iostream>
#include <vector>
#include<string>
using namespace std;
#include <algorithm>
vector <int> radix(vector<int> vec)
{
     vector<int> VecWithCutValues(vec);
     vector<int> VecForCountSort(vec);
 int maxel = vec[0];  

    for (size_t i = 1; i < vec.size()-1; i++) {
        if (vec[i] > maxel) {
            maxel = vec[i];  
        }
    }
int temp=0;
  string maxDigit = to_string(maxel);


for (int j = 0; j < maxDigit.length(); j++) {
    
 for (int i=0; i<vec.size(); i++) {
    temp=VecWithCutValues[i]%10;
    VecWithCutValues[i]=VecWithCutValues[i]/10;
   VecForCountSort[i]=temp;
    }
  vector<int> countarr(10,0);//Right.Initialize a countArray[] of length max+1 with all elements as 0. This array will be used for storing the occurrences of the elements of the input array.
 


for (int i=0; i < VecForCountSort.size(); i++)
{
    countarr[VecForCountSort[i]]++;
}


 for (int i=1; i <= maxel; i++) {
        countarr[i]=countarr[i] +countarr[i-1];
    }
vector<int> res(vec.size());
 for (int i = vec.size() - 1; i >= 0; i--) {
        res[countarr[VecForCountSort[i]] - 1] = vec[i];
            countarr[VecForCountSort[i]]--;
    }
    vec=res;

}
    return vec;
}
 



int main()
{
vector <int> vec = {1, 1, 9, 3,33,43, 3, 4, 4, 0, 4454,3, 8};
vec=radix(vec);
for (int i : vec)
{
cout << " " <<i;
}
}

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


int main()
{
vector<int> testVector1 = {3132, 2123123, 11};
vector<int> testVector2 = {5, 7, 2, 9, 1, 3};
vector<int> testVector3 = {10, 9, 8, 7, 6, 5, 4, 3, 2, 1};
vector<int> testVector4 = {1, 1, 1, 1, 1, 1};
vector<int> testVector5 = {10, 20, 30, 40, 50, 60, 70, 80, 90, 100};
vector<int> testVector6 = {100, 90, 80, 70, 60, 50, 40, 30, 20, 10};
vector<int> testVector7 = {2};
vector<int> testVector8 = {}; 
 testVector1=radix(testVector1);
  testVector2=radix(testVector2);
   testVector3=radix(testVector3);
   testVector4= radix(testVector4);
    testVector5= radix(testVector5);
     testVector6= radix(testVector6);
       testVector7=radix(testVector7);
       testVector8= radix(testVector8);
 
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


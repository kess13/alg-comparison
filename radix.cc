#include <iostream>
#include <vector>
using namespace std;
#include <algorithm>
#include <string>
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
vector<int> testVector1 = {3, 2, 1};
vector<int> testVector2 = {5, 7, 2, 9, 1, 3};
vector<int> testVector3 = {10, 9, 8, 7, 6, 5, 4, 3, 2, 1};
vector<int> testVector4 = {1, 1, 1, 1, 1, 1};
vector<int> testVector5 = {10, 20, 30, 40, 50, 60, 70, 80, 90, 100};
vector<int> testVector6 = {100, 90, 80, 70, 60, 50, 40, 30, 20, 10};
vector<int> testVector7 = {2};
vector<int> testVector8 = {}; 
vector <int> testVector9 = {10234, 15467, 19876, 14567, 17890, 12345, 16789, 18765, 19876, 15678}; 
 radix(testVector1);
  radix(testVector2);
   radix(testVector3);
   radix(testVector4);
    radix(testVector5);
     radix(testVector6);
       radix(testVector7);
       radix(testVector8);
 radix(testVector9);
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
if ( is_sorted(testVector9.begin(),testVector9.end()))
{
cout<<"success! Vector 9 passed"<<endl;
}
return 0;
}

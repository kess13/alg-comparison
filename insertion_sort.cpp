#include <iostream>
#include <vector>
using namespace std;
#include <algorithm>
void insertionsort(vector<int> &vec)
{
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
vector<int> testVector1 = {3, 2, 1};
vector<int> testVector2 = {5, 7, 2, 9, 1, 3};
vector<int> testVector3 = {10, 9, 8, 7, 6, 5, 4, 3, 2, 1};
vector<int> testVector4 = {1, 1, 1, 1, 1, 1};
vector<int> testVector5 = {10, 20, 30, 40, 50, 60, 70, 80, 90, 100};
vector<int> testVector6 = {100, 90, 80, 70, 60, 50, 40, 30, 20, 10};
vector<int> testVector7 = {2,1};
vector<int> testVector8 = {}; 
 insertionsort(testVector1);
  insertionsort(testVector2);
   insertionsort(testVector3);
   insertionsort(testVector4);
    insertionsort(testVector5);
     insertionsort(testVector6);
       insertionsort(testVector7);
       insertionsort(testVector8);
 
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



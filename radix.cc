#include <iostream>
#include <vector>
using namespace std;
#include <algorithm>
vector <int> countingsort(vector<int> vec)
{

auto max = max_element(vec.begin(), vec.end());
int maxel= *max;
int temp=0;
vector<int> countarr(maxel+1,0);//vector wiht size max value +1 filled with zeroes
for (int i=0; i <= maxel; i++)
{
countarr[i]=count(vec.begin(), vec.end(), i);
}
for (int i=0; i <= maxel; i++) //to make cumulative sum of count array elements
{
temp=temp+countarr[i];
countarr[i]=temp;
}
 for (int i = 0; i <= vec.size()-1; i++) {
    
        vec[countarr[vec[i]] - 1] = vec[i];
        
    }
    return vec;

}




int main()
{

vector <int> vec = {0,1,9,3,5,2,4};
vec=countingsort(vec);
for (int i : vec)
{
cout << " " <<i;

}

}

#include <iostream>
#include <vector>
using namespace std;
#include <algorithm>
vector <int> radixsort(vector<int> vec)
{
    vector <int> MainCopy=vec;
    vector <int> SecondCopy=vec;
auto max = max_element(vec.begin(), vec.end());
int maxel= *max;
string maxstr= to_string(maxel);
for (int j=maxstr.length(); j>0;j--){
    for (int i=0; i < vec.size(); i++)
{
MainCopy[i]=SecondCopy[i]%10;// to extract last digit 
SecondCopy[i]=SecondCopy[i]/10;// to erase last digit


}
int MaxForSmallerVec= *max_element(MainCopy.begin(), MainCopy.end());

int temp=0;
vector<int> countarr(MaxForSmallerVec+1,0);
for (int i=0; i <= MaxForSmallerVec; i++)
{
countarr[i]=count(MainCopy.begin(), MainCopy.end(), i);
}
for (int i=0; i <= MaxForSmallerVec; i++) 
{
temp=temp+countarr[i];
countarr[i]=temp;
}
vector<int> res(MainCopy.size());
 for (int i = MainCopy.size() - 1; i >= 0; i--) {
        int pos=countarr[MainCopy[i]]-1;
        vec[pos]=vec[i];
    }
}
    return vec;

}




int main()
{

vector <int> vec = {0,13,129,3,5,442,42,0,61,28};
vec=radixsort(vec);
for (int i : vec)
{
cout << " " <<i;

}

}

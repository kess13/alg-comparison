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
MainCopy[i]=SecondCopy[i]%10;
SecondCopy[i]=SecondCopy[i]/10;


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
        res[pos]=vec[i];

    }
    vec=res;
}
    return vec;

}




int main()
{

vector <int> vec = {0,3,9,3,51,4,2,0,6,8};
vec=radixsort(vec);
for (int i : vec)
{
cout << " " <<i;

}

}

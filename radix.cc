#include <iostream>
#include <vector>
using namespace std;
#include <algorithm>
vector <int> countingsort(vector<int> vec)
{

auto max = max_element(vec.begin(), vec.end());
int maxel= *max;
int temp=0;
vector<int> countarr(maxel+1,0);
for (int i=0; i <= maxel; i++)
{
countarr[i]=count(vec.begin(), vec.end(), i);
}
for (int i=0; i <= maxel; i++) 
{
temp=temp+countarr[i];
countarr[i]=temp;
}
vector<int> res(vec.size());
 for (int i = vec.size() - 1; i >= 0; i--) {
        int pos=countarr[vec[i]]-1;
        res[pos]=vec[i];
    }
    return res;

}
 
 
vector <int> radix (vector<int> vec) {
vector <int> copy(vec), MainCopy(vec);
auto max = max_element(vec.begin(), vec.end());
int maxel= *max;
string maxDigit=to_string(maxel);
for (int i=0; i < maxDigit.length(); i++)
{
    for (int j=0; j <vec.size(); j++)
    {
MainCopy[j]=copy[j]%10;
copy[j]=vec[j]/10;
    }
    vec=countingsort(MainCopy);


}
return vec;


}



int main()
{

vector <int> vec = {0,1,9,3,335,42,4,0,55,8};
vec=radix(vec);
for (int i : vec)
{
cout << " " <<i;

}

}
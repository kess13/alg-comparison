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
        res.push_back(pos);
    }
    return res;

}
 
 
vector <int> radix (vector<int> vec) {
vector <int> copy(vec), MainCopy(vec),res,positionvec;
auto max = max_element(vec.begin(), vec.end());
int maxel= *max;
string maxDigit=to_string(maxel);
for (int i=maxDigit.length(); i > 0; i--)
{
    for (int j=0; j <vec.size(); j++)
    {
MainCopy[j]=copy[j]%10;
copy[j]=copy[j]/10;
    }
    positionvec=countingsort(MainCopy);
    for (int i=positionvec.size()-1; i>0;i--)
    {
    res[i]=vec[positionvec[i]];
    }


}
return res;


}



int main()
{

vector <int> vec = {0,1,9,3,35,42,4,0,55,8};
vec=radix(vec);
for (int i : vec)
{
cout << " " <<i;

}

}
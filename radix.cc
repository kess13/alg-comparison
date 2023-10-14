#include <iostream>
#include <vector>
using namespace std;
#include <algorithm>
vector <int> countingsort(vector<int> vec)
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
}

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




int main()
{

vector <int> vec = {0,13,129,3,5,442,42,0,61,28};

for (int i : vec)
{
cout << " " <<i;

}

}

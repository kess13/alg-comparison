#include <iostream>
#include <vector>
using namespace std;
#include <algorithm>
vector <int> countingsort(vector<int> vec)
{
vector <int> copy=vec;
auto max = max_element(vec.begin(), vec.end());
int maxel= *max;
int temp=1;
vector<int> countarr(maxel+1);//vector wiht size max value +1 fill with zeroes
for (int i=0; i<vec.size(); i++)
{
countarr[i]=count(countarr.begin(), countarr.end(), i);



}

return vec;

}




int main()
{
    string biggest =to_string(maxel);
for (int i=biggest.length(); i>0; i--)
{
    vector <int> copy=vec;
for (int i=0; i<vec.size(); i++)
{
    
int a=vec[i]%10;
copy.push_back(a);
if ()

}
}
vector <int> vec = {0,11,32,43,554,15,6,337};
vec=countingsort(vec);
for (int i : vec)
{
cout << " " <<i;

}

}

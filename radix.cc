#include <iostream>
#include <vector>
using namespace std;
#include <algorithm>
vector <int> countingsort(vector<int> vec)
{
vector <int> copy=vec;
auto max = max_element(vec.begin(), vec.end());
int maxel= *max;

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
return vec;
}



int main()
{
vector <int> vec = {0,11,32,43,554,15,6,337};
vec=countingsort(vec);
for (int i : vec)
{
cout << " " <<i;

}

}
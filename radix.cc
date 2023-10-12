#include <iostream>
#include <vector>
using namespace std;
#include <algorithm>
vector <int> countingsort(vector<int> vec)
{
vector <int> copy=vec;
auto max = max_element(vec.begin(), vec.end());
string biggest = to_string(max);
for (int i=biggest.length()-1; i>0; i--)
{
for (int i=0; i<vec.size(); i++)
{
int a=vec[i]%10;
if (a==0)

}


}
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
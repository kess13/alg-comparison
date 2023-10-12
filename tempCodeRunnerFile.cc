vector <int> countingsort(vector<int> vec)
{
vector <int> copy=vec;
auto max = max_element(vec.begin(), vec.end());
int maxel= *max;
string biggest =to_string(*max);
for (int i=biggest.length()-1; i>0; i--)
{
for (int i=0; i<vec.size(); i++)
{
int a=vec[i]%10;
if (a==0)

}


}
}

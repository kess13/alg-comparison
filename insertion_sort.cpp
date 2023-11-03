#include <iostream>
#include <vector>
using namespace std;
#include <algorithm>
void insertionsort(vector<int> &vec)
{
    
       int temp = 0;
    for (int key = 1; key < vec.size(); key++)
    {
        int pos = 0;
        bool change = false;
        for (int ElemBefore = key - 1; ElemBefore >= 0; ElemBefore--) 
        {
            if (vec[ElemBefore] > vec[key])

            {
                pos = ElemBefore;
                change = true;
                temp = vec[key];
            }

           
        }
        if (change)
        {
            vec.erase(vec.begin() + key);
            vec.insert(vec.begin() + pos, temp);
        }
    }
}



 


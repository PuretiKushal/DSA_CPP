#include <bits/stdc++.h>
using namespace std;
void explainPair()
{
    pair<int, int> p = {1,3};
    cout << "first element of pair p is: " << p.first << endl;
    cout << "second element: " << p.second << endl;
    
    pair<int, pair<int,int>> p1= {1,{2,3}};
    cout << "nested pair p1 is: " << p1.first << " " << p1.second.first << " " << p1.second.second << endl;
    
    pair<int,int> a[]={{1,2},{23,40}};
    cout << "array of pair datatype is: ";
    for(int i=0;i<2;i++)
    {
        cout << " " << a[i].first << "," << a[i].second << " ";
    }
}
int main()
{
    explainPair();
}
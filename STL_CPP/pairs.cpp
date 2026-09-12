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
    //so to create multiple pairs we can use vector of pairs

    //sorting a vector of pair
    vector<pair<int,int>> p2={{1,2},{23,40},{4,5}};
    sort(p2.begin(),p2.end()); //sorts the vector of pairs in asceding order based on first element of pair
    sort(p2.begin(),p2.end(),[](auto x, auto y){
        return x.second<y.second;
    }); //sorts the vector of pairs in asceding order based on second element of pair
}   
int main()
{
    explainPair();
}
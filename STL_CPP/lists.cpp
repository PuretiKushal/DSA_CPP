#include<bits/stdc++.h>
using namespace std;
void explainLists()
{
    list<int> l; //declaration
    l.push_back(1); //inserts at end -->{1}
    l.push_front(2); //inserts at front --> {2,1}

    for(auto i: l) //i is iterator and auto doesn't need * before i
    {
        cout << i << " "; // 2 1
    }
    //begin,end,size,swap and other functions are same as vectors


}
int main()
{
    explainLists();

}
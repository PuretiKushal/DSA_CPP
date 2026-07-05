#include<bits/stdc++.h>
using namespace std;
void explainMultiSet()
{
    //same like set but can store duplicates also
    multiset<int> ms;
    ms.insert(2); //{2}
    ms.insert(2); //{2,2}
    ms.insert(2); //{2,2,2}
    ms.insert(2); //{2,2,2}
    ms.insert(1); //{1,2,2,2}
    ms.insert(1); //{1,1,2,2,2}
    ms.insert(1); //{1,1,1,2,2,2}
    ms.insert(10); //{1,1,1,2,2,2,10}
    ms.insert(5); //{1,1,1,2,2,2,5,10}
    ms.insert(8); //{1,1,1,2,2,2,5,8,10}

    ms.erase(1); //erases all 1s
    for(auto i: ms)
    {
        cout << i << " ";
    }
    cout << endl;
    cout << ms.count(2) << endl; //counts no of 2s
    ms.erase(ms.find(5)); //erases one occurence of 2
    for(auto i: ms)
    {
        cout << i << " ";
    }





}
int main()
{
    explainMultiSet();

}
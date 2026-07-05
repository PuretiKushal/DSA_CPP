#include<bits/stdc++.h>
using namespace std;
void explainDeque()
{
    //can be accessed using indices
    deque<int> d;
    d.push_back(1);
    d.push_front(2);
    cout << d.front() << endl; //returns 1st value
    cout << d.back() << endl; //returns last value

    d.clear(); //deletes all elements of deque
    for(auto i:d)
    {
        cout << i << " ";
    }
}
int main()
{
    explainDeque();

}
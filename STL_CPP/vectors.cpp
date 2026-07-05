#include <bits/stdc++.h>
using namespace std;
void explainVector()
{
    //can be accessed using indices
    vector <int> v; //declaration of vector
    v.push_back(1); //inserts 1 into v -- 1
    v.emplace_back(2); //automatically increases size to 2 and inserts 2 into v -- 1 2
    
    vector<int> vec(5); //creates a vector of size 5
    vector<int> v1(5,20); //20 20 20 20 20
    vector<int> v2(v1); //creates copy of v1 -- 20 20 20 20 20

    vector<int>:: iterator it=v.begin(); //it --> assigned to memory location of v[0]
    cout << *it << endl; //prints v[0] -- 1
    auto ite = v.end(); //points at the location after end element
    cout << *(ite-1) << endl; //to print last element -- 2
    cout << v.back() << endl; //last element -- 2
    cout << v.front() << endl; //first element -- 1
    //auto gets the datatype automatically

    //to print whole vector at once:
    for(auto it: v1)
    {
        cout << it << " "; //20 20 20 20 20
        //for auto loop doesn't need * before it
    }

    v1.erase(v1.begin()+2,v1.begin()+4); //erases elements from begin+2 to begin+4(begin+4 not included)
    v1.insert(v1.begin()+1,2,10); //(position,frequency,element)
    v.size(); //returns size
    v.pop_back(); //pops last element


}
int main()
{
    explainVector();
    
}
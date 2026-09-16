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

    //To insert an element at a particular position:
    v1.insert(v1.begin()+2,15); //inserts 15 at position begin+2

     //sorting a vector of pair
    vector<pair<int,int>> p2={{1,2},{23,40},{4,5}};
    sort(p2.begin(),p2.end()); //sorts the vector of pairs in asceding order based on first element of pair
    sort(p2.begin(),p2.end(),[](auto x, auto y){
        return x.second<y.second;
    }); //sorts the vector of pairs in asceding order based on second element of pair

    //To concatenate two vectors:
    //let them be a1 and a2 and we want to create a new vector ans, which is concatenation of a1 and a2
    vector<int>ans=v1; //copying a1 into ans
    ans.insert(ans.end(),v2.begin(),v2.end()); //inserts a2 at the end of ans
}
int main()
{
    explainVector();
    
}
#include<bits/stdc++.h>
using namespace std;
void explainSet()
{
    //stores everything in sorted order and only unique occurences
    //every operation has a time complexity of O(logn)
    set<int> s;
    s.insert(2); //{2}
    s.insert(1); //{1,2}
    s.insert(44); //{1,2,44}
    s.insert(44); //{1,2,44} - won't be inserted if it is not unique
    s.insert(13); //{1,2,13,44}

    auto it=s.find(1);
    cout << *(it) << endl;
    s.count(44); //always returns 1 for any element if it is present, as it allows only unique

    auto it1=s.find(1);
    auto it2=s.find(13);
    s.erase(it1,it2); //deletes elements from 1 to 13 without 13(dlts sorted order)
    for(auto i:s)
    {
        cout << i << " ";
    }
    cout << endl;
    s.insert(2); 
    s.insert(2); 
    s.insert(2);
    s.insert(44); 
    s.insert(44);
    s.insert(56);
    for(auto i:s)
    {
        cout << i << " ";
    }

    cout << s.size() << endl; //returns the number of elements in the set

    if(s.empty())
    {
        cout << "Set is empty";
    } //returns true if the set is empty

    s.clear(); //deletes all elements from the set

    if(s.find(44)!=s.end())
    {
        cout << "44 found";
    } //another way to check if an element exists

    cout << s.count(13); //returns 1 if present, 0 if absent - can be used to check if an element exists
    
    auto lb=s.lower_bound(44); //points to first element>=x, i.e >=44 -->44
    
    cout << endl << *(lb) << " ";
    auto ub=s.upper_bound(44); //points to first element >x, i.e >44 --> 56
    //if upper bound doesnt exist,i.e x is the largest element,ub points to s.end(), which cant be printed
    //so check it is not equal to s.end()
    if(ub!=s.end())
    {
    cout << endl << *(ub) << " ";
    }

}
int main()
{
    explainSet();

}
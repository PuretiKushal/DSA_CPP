#include<bits/stdc++.h>
using namespace std;
void explainMap()
{
    //O(log n) is time complexity of all
    //map is like a set, sorts elements
    //sorts by key
    //map means key,value pairs
    //value can be repeating but key must be unique
    map<int,int> m; //key is of int, value is of int
    m.insert({1,12});
    m[7]=2; //{1,2} //key is .first, value is .second
    m.emplace(3,4);
    for(auto i: m)
    {
        cout << i.first <<" " <<  i.second << " ";
        cout << endl;
        //first 1,12 then 3,4 then 7,12 will be printed
    }
    auto i1=m.find(7); //searches only keys, can't search values
    //if that key isn't found, i1 will point to m.end()
    //in that case, 0 will be output
    cout << (*i1).second << endl; //gives value of 7 i.e 2
    auto lb= m.lower_bound(3); //lb means >=x, here 3>=3 so value of 3 will be output i.e 4
    cout << (*lb).second << endl;
    auto ub=m.upper_bound(3);
    cout << (*ub).second << endl; //ub means >x, 7>3 so value of 7 will be o/p i.e 2
    //if given key is greater than all existing elements in the map, lb and ub will both point to m.end()


    map<pair<int,int>,int> mp;
    mp.insert({{1,24},8});
    mp.insert({{50,1},9});
    mp[{1,12}]=30;
    for(auto it: mp)
    {
        cout << it.first.first <<" " <<  it.first.second <<" " << it.second << " ";
        cout << endl;
        //1,12 30 first then 1,24 8 because 12<24(1 equal in both) and then 50,1 9
    }
    auto i2=mp.find({1,2});
    cout << (*i2).second << endl; //gives output 0 as i2 points to mp.end()

    auto i3=mp.find({1,24});
    cout << (*i3).second << endl; //output is value of 1,24 i.e 8
    auto lb1= mp.lower_bound({1,22}); //lb means >=x, here 1=1 but 24>=22 so value of 1,24 will be output i.e 8
    cout << (*lb1).second << endl;
    auto ub1=mp.upper_bound({1,20});
    cout << (*ub1).second << endl; //ub means >x, 1=1 but 24>20 so value of 1,24 will be o/p i.e 8
    //if given key is greater than all existing elements in the map, lb and ub will both point to mp.end()
    //erase, size, swap and empty same as sets etc

}
int main()
{
    explainMap();
}
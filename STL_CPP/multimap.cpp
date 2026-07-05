#include<bits/stdc++.h>
using namespace std;
void explainMultimap()
{
    //O(log n) is time complexity of all
    //keys can be repeated, values can be repeated
    //doesn't allow mm.[](insert,emplace etc)
    //if there are multiple keys, and we use find(key), value of first occurence of key will be o/p
    multimap<int,int> mm;
}
int main()
{
    explainMultimap();
}
#include<bits/stdc++.h>
using namespace std;
void explainQueue()
{
    queue<int> q;
    q.push(1); //{1}
    q.push(2); //{1,2}
    q.emplace(4); //{1,2,4}
    q.emplace(3); //{1,2,4,3}

    q.back(); //last
    q.front(); //first

    while(q.empty()==0)
    {
        cout << q.front() << " "; //{1,2,4,3}
        q.pop();
    }

    cout << endl << q.empty(); //1(true) as queue became empty now


}
int main()
{
    explainQueue();

}
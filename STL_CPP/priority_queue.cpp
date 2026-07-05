#include<bits/stdc++.h>
using namespace std;
void explainPriorityQueue()
{
    //time complexity: push,pop--> O(log n), top-->O(1) 
    priority_queue<int> pq; //max heap, i.e descending order
    pq.push(4); //{4}
    pq.push(2); //{4,2}
    pq.push(7); //{7,4,2}
    pq.emplace(3); //{7,4,3,2}
    while(!pq.empty())
    {
        cout << pq.top() << " ";
        pq.pop();
    }
    cout << endl;

    priority_queue<int, vector<int>,greater<int>> pq1; //min heap, i.e ascending order
    pq1.push(90); //{90}
    pq1.push(1); //{1,90}
    pq1.push(23); //{1,23,90}
    pq1.push(42); //{1,23,42,90}
    while(!pq1.empty())
    {
        cout << pq1.top() << " ";
        pq1.pop();
    }
}
int main()
{
    explainPriorityQueue();
}
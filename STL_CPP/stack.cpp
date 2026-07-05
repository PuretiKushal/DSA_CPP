#include<bits/stdc++.h>
using namespace std;
void explainStack()
{   //every operation complexity is O(1)
    stack<int> st;
    st.push(1); //{1}
    st.push(2); //{2,1} 
    st.emplace(5); //{5,2,1}
    st.push(3); //{3,5,2,1}
    st.emplace(10); //{10,3,5,2,1}

    cout<< st.top() << " "; //returns first element --> 10
    st.pop(); //pops the top element;
    st.size(); //returns size
    cout << st.empty() << endl; //checks if stack is empty, 1(true) if empty, 0(false) if not
    stack<int> st1;
    st1.push(1);
    st1.push(2);
    st1.push(5);
    st1.push(100);
    st1.push(3);
    
    st1.swap(st);

    while(st.empty()==0)
    {
        cout << st.top() << " ";
        st.pop();
    }
    

}
int main()
{
    explainStack();
}
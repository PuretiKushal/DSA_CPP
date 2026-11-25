/*
Problem: 225. Implement Stack using Queues
Pattern: Queue / Stack Implementation
Difficulty: Easy

Time Complexity:
- push(): O(n) - Inserts the element and rotates the remaining queue elements behind it.
- pop(): O(1) - Removes and returns the front element.
- top(): O(1) - Returns the front element without removing it.
- empty(): O(1) - Checks whether the queue is empty.

Space Complexity: O(n)
- Uses a single queue to store all stack elements.

Key Idea:
- Use a single queue to simulate LIFO (Last In, First Out) behaviour.
- After inserting a new element, rotate all previous elements to the back of the queue.
- This keeps the most recently inserted element at the front.
- The front element can then be directly used for pop() and top().
*/

class MyStack {
public:
    queue<int> q;
    MyStack() {

    }
    void push(int x) {
        q.push(x);
        int n=q.size();
        for(int i=0;i<n-1;i++)
        {
            q.push(q.front());
            q.pop();
        }
    }
    int pop() {
        int x=q.front();
        q.pop();
        return x;
    }
    int top() {
        return q.front();
    }
    bool empty() {
        return q.empty();
    }
};
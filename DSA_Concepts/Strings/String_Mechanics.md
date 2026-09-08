# String Mechanics

## 1. String View / Access

string s="hello";

cout<<s[0];              // Access character at index 0
cout<<s.substr(1,3);     // Get part of a string

// String indexing starts from 0.


## 2. Pass-by-Reference

### What is Pass-by-Reference?

void change(string &s)
{
    s[0]='A';
}

// '&' makes s refer to the original string.
// Changes made to s inside the function affect the original string.


### Pass-by-Reference vs Pass-by-Value

void change(string s)
{
    s[0]='A';
}

// A copy of the string is created.
// Changes do NOT affect the original string.

void change(string &s)
{
    s[0]='A';
}

// No copy is created.
// Changes DO affect the original string.


### Why '&' Matters in DSA

// Consider a large vector:

void solve(vector<int> &a)
{
    // Work directly on the original vector
}

// Without '&':

void solve(vector<int> a)
{
    // A copy of the entire vector is created.
}

// Passing large arrays/vectors by value can cause unnecessary O(n) copying.
// Passing by reference avoids that copy.


### Read-Only Reference

void print(string const &s)
{
    cout<<s;
}

// const & means:
// - No copy is created.
// - Original string cannot be modified inside the function.


// Common forms:

void solve(vector<int> &a)       // Modify original
void solve(const vector<int> &a) // Read original without copying
void solve(vector<int> a)        // Make a copy


### Reference and Original Variable

int x=10;
int &y=x;

y=20;

// x is now 20.
// y is another name (reference) for x.


### Reference with Characters

void change(string &s)
{
    s[0]='x';
}

// Original string is modified.


### Reference with Vectors

void change(vector<int> &a)
{
    a[0]=100;
}

// Original vector is modified.


### Reference in Two Pointers

void reverse(string &s)
{
    int l=0;
    int r=s.size()-1;

    while(l<r)
    {
        swap(s[l],s[r]);
        l++;
        r--;
    }
}

// The string is passed by reference because we modify it directly.


### Important DSA Pattern

// Whenever a function needs to modify the original:
//     vector<int> &a
//     string &s
//
// Whenever a function only needs to read a large object:
//     const vector<int> &a
//     const string &s
//
// Passing without '&':
//     vector<int> a
//     string s
// creates a copy.


## 3. starts_with()

string s="leetcode";

s.starts_with("leet");   // true
s.starts_with("code");   // false

// Checks whether a string begins with the given prefix.


## 4. compare()

string s="apple";

s.compare("apple");      // 0 → strings are equal
s.compare("banana");     // non-zero → strings are different

// compare() returns 0 when both strings are equal.


## 5. Two Pointers — Basic Idea

int l=0;
int r=s.size()-1;

while(l<r)
{
    // Use s[l] and s[r]

    l++;
    r--;
}

// Two pointers use two indices to process different positions.
// A common example is comparing elements from both ends.


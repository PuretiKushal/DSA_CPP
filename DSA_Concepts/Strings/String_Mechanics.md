# String Mechanics

## 1. String Access & View

string s="hello";

cout<<s[0];              // Access character at index 0
cout<<s.substr(1,3);     // Get a substring starting at index 1 with length 3

// String indexing starts from 0.
// Strings can be accessed and modified using s[i].


## 2. Pass-by-Reference

### Basic Idea

void change(string &s)
{
    s[0]='A';
}

// '&' makes s a reference to the original string.
// No copy of the string is created.
// Changes made to s affect the original string.


### Pass-by-Reference vs Pass-by-Value

void change(string s)
{
    s[0]='A';
}

// Pass-by-value creates a copy.
// Changes do NOT affect the original string, it only alters the created copy.

void change(string &s)
{
    s[0]='A';
}

// Pass-by-reference works directly with the original.
// Changes DO affect the original string.


### Why '&' Matters in DSA

void solve(vector<int> &a)
{
    // Works directly on the original vector
}

// Without '&':

void solve(vector<int> a)
{
    // A copy of the entire vector is created.
}

// Passing large vectors/strings by value can cause O(n) copying.
// Passing by reference avoids this unnecessary copy.


### Read-Only Reference

void print(const string &s)
{
    cout<<s;
}

// const & means:
// - No copy is created.
// - The original object cannot be modified.
// - Useful when a function only needs to read the data.


### Common Forms

void solve(vector<int> &a)        // Modify original vector
void solve(const vector<int> &a)  // Read without copying
void solve(vector<int> a)        // Create a copy

void solve(string &s)             // Modify original string
void solve(const string &s)       // Read without copying
void solve(string s)              // Create a copy


### Reference Variable

int x=10;
int &y=x;

y=20;

// y is another name for x.
// Changing y also changes x.
// x is now 20.


### Reference with Characters

void change(string &s)
{
    s[0]='x';
}

// Original string is modified because s is a reference.


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


### Key Rule

// Modify original → use &
// Read large object without copying → use const &
// Need an independent copy → pass by value


## 3. starts_with()

string s="leetcode";

s.starts_with("leet");  // true
s.starts_with("code");  // false

// Checks whether a string starts with the given prefix.


## 4. compare()

string s="apple";

s.compare("apple");     // 0 → strings are equal
s.compare("banana");    // non-zero → strings are different

// compare() returns 0 when both strings are equal.


## 5. ASCII Character Manipulation

// Lowercase letters have consecutive ASCII values:
//
// 'a' → 97
// 'b' → 98
// ...
// 'z' → 122

s[i]-'a';               // Convert lowercase character to index 0-25

// Example:
// 'a'-'a' → 0
// 'b'-'a' → 1
// 'z'-'a' → 25


## 6. Fixed Frequency Array

int f[26]={0};

for(int i=0;i<s.size();i++)
{
    f[s[i]-'a']++;      // Count frequency of each lowercase character
}

// f[0] → frequency of 'a'
// f[1] → frequency of 'b'
// ...
// f[25] → frequency of 'z'


## 7. Two Pointers on Strings

int l=0;
int r=s.size()-1;

while(l<r)
{
    // Process s[l] and s[r]

    l++;
    r--;
}

// Two pointers use two indices to process different positions of the same string.
// Commonly used when comparing or modifying characters from both ends.



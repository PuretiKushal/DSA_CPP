# String Basics

## 1. Reading Strings

```cpp
string s;
cin >> s;                 // Reads only one word, stops at whitespace

// NOTE: If using getline() after cin, clear the buffer first
cin.ignore(); 
getline(cin, s);          // Reads the complete line, including spaces
```

## 2. String Size

```cpp
int n = s.size();         // Number of characters in the string

// Example:
// string s = "hello";
// n = 5
```

## 3. Accessing Characters

```cpp
s[i]                      // Access the character at index i

// Indexing starts from 0:
// "hello"
//  01234
// s[0] is 'h'
// s[4] is 'o'
```

## 4. Traversing a String

```cpp
int i, n;
n = s.size();

for(i = 0; i < n; i++)
{
    cout << s[i];         // Access each character sequentially
}

// Alternative (Modern C++ Range-based loop):
for(char ch : s) {
    cout << ch;
}
```

## 5. Modifying a String

```cpp
string s = "hello";
s[0] = 'H';               // Modify a character -> s becomes "Hello"
s[i] = 'x';               // Replace character at index i
```

## 6. Important Character Functions

```cpp
isalpha(ch);             // Checks if ch is a letter
isdigit(ch);             // Checks if ch is a digit
isalnum(ch);             // Checks if ch is a letter or digit
islower(ch);             // Checks if ch is lowercase
isupper(ch);             // Checks if ch is uppercase

// Note: These return an integer value; assign them back to change the character
ch = tolower(ch);        // Converts ch to lowercase
ch = toupper(ch);        // Converts ch to uppercase
```

## 7. ASCII

```text
// Lowercase letters are consecutive
'a' = 97, 'b' = 98, 'c' = 99 ... 'z' = 122

// Uppercase letters are consecutive
'A' = 65, 'B' = 66 ... 'Z' = 90

// Digits are consecutive
'0' = 48, '1' = 49 ... '9' = 57
```

## 8. Character to Index

```cpp
s[i] - 'a'                // Converts lowercase character to index 0-25
s[i] - 'A'                // Converts uppercase character to index 0-25
s[i] - '0'                // Converts character digit (like '5') to true integer (5)

// Examples:
// 'a' - 'a' = 0
// 'b' - 'a' = 1
// 'z' - 'a' = 25
```

## 9. Fixed Frequency Array

```cpp
int f[26] = {0};          // Array initialized to zero for each letter

for(int i = 0; i < s.size(); i++)
{
    f[s[i] - 'a']++;      // Increase frequency of current character
}

// Example: s = "banana"
// f[0] (matches 'a') = 3
// f[1] (matches 'b') = 1
// f[13] (matches 'n') = 2
```

## 10. unordered_map

```cpp
#include <unordered_map>

unordered_map<char, int> mp;       // Stores character -> frequency

for(int i = 0; i < s.size(); i++)
{
    mp[s[i]]++;                    // Increase frequency
}

// Core Operations:
mp[key]++;                         // Increment value
mp[key];                           // Access value
mp.find(key);                      // Find key (returns iterator)
mp.count(key);                     // Check if key exists (returns 1 or 0)
mp.erase(key);                     // Remove key from map
```

## 11. unordered_set

```cpp
#include <unordered_set>

unordered_set<char> st;            // Stores unique elements

st.insert('a');                    // Insert element

if(st.count('a'))
{
    // Element exists in set
}

st.erase('a');                     // Remove element from set
```

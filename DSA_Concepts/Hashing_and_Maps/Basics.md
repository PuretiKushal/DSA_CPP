# Hashing & Maps Basics

## 1. Core Intuition
Hashing is the process of mapping arbitrary data (Keys) to fixed-size values (Indexes) using a mathematical formula called a **Hash Function**. 
* **unordered_map**: Built using a **Hash Table**. Elements are unordered.
* **map**: Built using a Self-Balancing Binary Search Tree (usually a **Red-Black Tree**). Elements are stored in sorted order of keys.

---

## 2. Time & Space Complexities

| Operation | `unordered_map` (Average) | `unordered_map` (Worst Case) | `map` (Always) |
| :--- | :--- | :--- | :--- |
| **Insertion** | O(1) | O(N) | O(log N) |
| **Deletion** | O(1) | O(N) | O(log N) |
| **Search / Lookup** | O(1) | O(N) | O(log N) |
| **Space Complexity**| O(N) | O(N) | O(N) |

> ⚠️ **Interview Warning:** The worst-case O(N) for `unordered_map` occurs due to **Hash Collisions** (when multiple keys map to the same bucket). If an online assessment test case explicitly triggers this, switch to a ordered `map` to secure a guaranteed O(log N) runtime.

---

## 3. Basic Syntax Template

```cpp
#include <bits/stdc++.h>
using namespace std;

int main() {
    // Declaration: unordered_map<Key_Type, Value_Type> mp;
    unordered_map<int, string> rollMap;

    // 1. Insertion
    rollMap[101] = "Alice";
    rollMap[102] = "Bob";
    rollMap.insert({103, "Charlie"});

    // 2. Lookup / Search
    int searchKey = 102;
    if (rollMap.find(searchKey) != rollMap.end()) {
        cout << "Found: " << rollMap[searchKey] << endl;
    }

    // 3. Size and Deletion
    cout << "Total Elements: " << rollMap.size() << endl;
    rollMap.erase(101); // Removes key 101 from map
}
```

---

## 4. The `mp[key]` Behavior Trap
Accessing a key using brackets `mp[key]` does **not** just read data. If the key does not exist in the map, C++ will **automatically insert the key** with a default value (`0` for integers, empty string for strings). So, to find if a key exists or not, use .find() or .count().

```cpp
unordered_map<int, int> mp;
cout << mp[5]; // Output: 0 (Key 5 is now permanently inserted into the map!)

// To safely check if a key exists WITHOUT modifying the map, use .find() or .count():
if (mp.count(5)) {
    // Key exists
}
```

---

## 5. Iterating Through a Map
Maps store data as elements of type `std::pair`. You access the key using `.first` and the value using `.second`.

```cpp
unordered_map<string, int> items = {{"Pen", 10}, {"Book", 5}};

// Using structure binding (Modern C++17)
for (auto& [key, value] : items) {
    cout << key << " -> " << value << endl;
}

// Classical Iterator approach
for (auto it = items.begin(); it != items.end(); it++) {
    cout << it->first << " -> " << it->second << endl;
}
```

---

## 6. Common Interview Patterns
1. **Frequency Counting:** Tracking occurrences of items (`mp[element]++`).
2. **Complement Tracking (Two-Sum):** Checking if `Target - Current_Element` exists in the map from past history.
3. **Index Storage:** Storing the index where an item was last seen to calculate subarray metrics.

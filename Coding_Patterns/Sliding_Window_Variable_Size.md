# Variable Size Sliding Window

## When to Identify

Use Variable Size Sliding Window when:

- Window size is NOT fixed.
- We need the **minimum** or **maximum** valid window.
- Left pointer (`l`) and right pointer (`r`) move independently.

---

## General Flow

```
Expand Window
      ↓
Window becomes valid?
      ↓
     No
      ↓
Expand More
      ↓
     Yes
      ↓
Update Answer
      ↓
Shrink Window
      ↓
Still Valid?
      ↓
     Yes
      ↓
Update Answer Again
      ↓
Shrink Again
      ↓
     No
      ↓
Expand Again
```

---

## General Template

```cpp
l=0;

for(r=0;r<n;r++)
{
    // Add s[r] to current window

    while(Window is Valid)
    {
        // Update answer if needed

        // Remove s[l] from current window
        l++;
    }
}
```

---

## Important Questions

### 1. What makes the window valid?

Examples:

```text
209  -> sum >= target

3    -> No repeated characters

424  -> Changes Needed <= k
        (Window Length - Maximum Frequency <= k)

76   -> count == distinct
```

---

### 2. What should the window store?

Depends on the problem.

Examples:

```text
209 -> Sum

3 -> Set

424 -> Frequency Array

76 -> Frequency Array
```

---

### 3. What to do when the window becomes valid?

If the problem asks for:

```text
Minimum Window
```

```
Update Answer
Shrink Window
```

If the problem asks for:

```text
Maximum Window
```

```
Update Answer
Keep Expanding
```

(Shrink only if the window becomes invalid.)

---

## Common Variables

```cpp
l -> Left Pointer

r -> Right Pointer

ans -> Final Answer

sum -> Current Window Sum

count -> Number of satisfied conditions

dist -> Number of distinct required characters

h -> Maximum Frequency

len -> Current Window Length
```

---

## Frequency Array Problems

```cpp
vector<int> f(26,0);
```

or

```cpp
vector<int> f(128,0);
```

Use:

```cpp
f[s[r]]++;
```

Remove:

```cpp
f[s[l]]--;
```

---

## Time Complexity

Right pointer moves at most:

```text
0 → n-1
```

Left pointer also moves at most:

```text
0 → n-1
```

Therefore:

```text
O(2n)

↓

O(n)
```

---

## Problems Solved

### Minimum Size Subarray Sum (209)

```text
Window Valid:

sum >= target
```

---

### Longest Substring Without Repeating Characters (3)

```text
Window Valid:

No repeated characters
```

---

### Longest Repeating Character Replacement (424)

```text
Window Valid:

Window Length - Maximum Frequency <= k
```

---

### Minimum Window Substring (76)

```text
Window Valid:

count == distinct
```

---

## Pattern Summary

Every Variable Size Sliding Window problem can be solved by answering these three questions:

1. What makes the window valid?
2. What should be stored inside the window?
3. When the window becomes valid, should I shrink or keep expanding?
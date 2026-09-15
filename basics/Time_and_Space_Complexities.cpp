````md
# Time and Space Complexity

## 1. Big-O Notation

Big-O describes how the amount of computational work or additional memory grows as the input size `n` grows.

It describes **growth**, not exact execution time or exact memory usage.

---

# 2. Common Time Complexities

## O(1) — Constant

The amount of work stays approximately the same regardless of the input size.

Example:

```cpp
cout<<a[5];
````

Whether the array has 10 elements or 1,000,000 elements, only one element is accessed.

```text
n = 10        → roughly 1 operation
n = 100       → roughly 1 operation
n = 1000      → roughly 1 operation
```

### Why?

The operation does not depend on `n`.

### Common Examples

* Array indexing
* Vector indexing
* Accessing the top of a stack
* Accessing the front of a queue
* Basic arithmetic
* Variable assignment
* Hash table operation on average

---

## O(log n) — Logarithmic

The amount of work grows logarithmically when the problem size is repeatedly reduced by a constant factor.

The most common case is repeatedly dividing by `2`.

```text
n
↓
n/2
↓
n/4
↓
n/8
↓
...
↓
1
```

After `k` divisions:

```text
n / 2^k = 1

n = 2^k

k = log₂(n)
```

Therefore, the number of operations is `O(log n)`.

### Example

For `n = 16`:

```text
16 → 8 → 4 → 2 → 1
```

Number of divisions = `4`

```text
log₂(16) = 4
```

For `n = 32`:

```text
32 → 16 → 8 → 4 → 2 → 1
```

Number of divisions = `5`

```text
log₂(32) = 5
```

### Common Examples

* Binary Search
* Operations on a balanced BST
* Heap insertion
* Heap deletion
* Moving through the height of a balanced tree

---

## O(n) — Linear

The amount of work grows directly with the input size.

Example:

```cpp
for(i=0;i<n;i++)
{
    cout<<a[i];
}
```

The loop runs `n` times.

```text
n = 10       → 10 operations
n = 100      → 100 operations
n = 1000     → 1000 operations
```

### Why?

Every element may need to be processed.

### Common Examples

* Array traversal
* String traversal
* Linear Search
* Two Pointers
* Sliding Window
* Tree traversal

---

## O(n log n)

The amount of work grows approximately as:

```text
n × log n
```

A common example is efficient comparison-based sorting.

```cpp
sort(a.begin(),a.end());
```

### Common Examples

* `sort()`
* Merge Sort
* Heap Sort
* Many divide-and-conquer algorithms

---

## O(n²) — Quadratic

The amount of work grows approximately as:

```text
n × n
```

Usually caused by nested loops that both depend on `n`.

Example:

```cpp
for(i=0;i<n;i++)
{
    for(j=0;j<n;j++)
    {
        ...
    }
}
```

The inner loop runs `n` times for every outer iteration.

```text
n × n = n²
```

Therefore:

```text
Time: O(n²)
```

### Example Growth

```text
n = 10       → 100
n = 100      → 10,000
n = 1000     → 1,000,000
```

### Common Examples

* Brute-force pair checking
* Bubble Sort
* Selection Sort
* Nested-loop comparisons

---

## O(2ⁿ) — Exponential

The amount of work approximately doubles whenever `n` increases by `1`.

```text
n = 1   → 2
n = 2   → 4
n = 3   → 8
n = 4   → 16
n = 10  → 1024
n = 20  → 1,048,576
```

### Common Examples

* Generating all subsets
* Some brute-force recursive algorithms
* Some backtracking algorithms

---

## O(n!) — Factorial

The amount of work grows extremely quickly.

```text
1!  = 1
2!  = 2
3!  = 6
4!  = 24
5!  = 120
10! = 3,628,800
```

### Common Examples

* Generating all permutations
* Brute-force solutions involving all possible orderings

---

# 3. Complexity Growth Order

For sufficiently large `n`, the common growth rates are approximately:

```text
O(1)
<
O(log n)
<
O(n)
<
O(n log n)
<
O(n²)
<
O(2ⁿ)
<
O(n!)
```

A lower growth rate is generally better for large inputs.

---

# 4. Deriving Time Complexity

## Single Loop

```cpp
for(i=0;i<n;i++)
{
    ...
}
```

The loop runs `n` times.

```text
Time: O(n)
```

---

## Two Separate Loops

```cpp
for(i=0;i<n;i++)
{
    ...
}

for(i=0;i<n;i++)
{
    ...
}
```

Total work:

```text
n + n = 2n
```

Constants are ignored in Big-O.

```text
Time: O(n)
```

---

## Nested Loops

```cpp
for(i=0;i<n;i++)
{
    for(j=0;j<n;j++)
    {
        ...
    }
}
```

The inner loop runs `n` times for every outer iteration.

```text
n × n = n²
```

```text
Time: O(n²)
```

---

## Nested Loops With Different Input Sizes

```cpp
for(i=0;i<n;i++)
{
    for(j=0;j<m;j++)
    {
        ...
    }
}
```

The outer loop runs `n` times.

The inner loop runs `m` times.

Therefore:

```text
Time: O(nm)
```

Do not automatically write `O(n²)` when the two input sizes are different.

---

## Loop That Doubles

```cpp
for(i=1;i<n;i*=2)
{
    ...
}
```

Values of `i`:

```text
1
2
4
8
16
32
...
```

The value doubles every iteration.

The number of iterations needed to reach `n` is logarithmic.

```text
Time: O(log n)
```

---

## Loop That Halves

```cpp
for(i=n;i>0;i/=2)
{
    ...
}
```

Values:

```text
n
n/2
n/4
n/8
...
1
```

The number of iterations is logarithmic.

```text
Time: O(log n)
```

---

## Sequential Different Complexities

```cpp
for(i=0;i<n;i++)
{
    ...
}

for(i=0;i<n;i++)
{
    for(j=0;j<n;j++)
    {
        ...
    }
}
```

Complexities:

```text
First loop  → O(n)
Second part → O(n²)
```

Total:

```text
O(n) + O(n²)
```

The dominant term is `O(n²)`.

Therefore:

```text
Time: O(n²)
```

---

## Dependent Inner Loop

Example:

```cpp
for(i=0;i<n;i++)
{
    for(j=0;j<i;j++)
    {
        ...
    }
}
```

The inner loop runs:

```text
0 + 1 + 2 + 3 + ... + (n-1)
```

times.

The sum is:

```text
n(n-1)/2
```

which grows proportionally to `n²`.

Therefore:

```text
Time: O(n²)
```

---

# 5. Dominant Term Rule

When adding complexities, keep the term that grows fastest.

```text
O(n) + O(n²)
→ O(n²)

O(n) + O(log n)
→ O(n)

O(n²) + O(n³)
→ O(n³)
```

Constants are ignored:

```text
O(2n)   → O(n)
O(5n)   → O(n)
O(10n²) → O(n²)
```

---

# 6. Binary Search Complexity

Binary Search repeatedly reduces the search space by half.

```text
n
→ n/2
→ n/4
→ n/8
→ ...
→ 1
```

After `k` steps:

```text
n / 2^k = 1

n = 2^k

k = log₂(n)
```

Therefore:

```text
Time: O(log n)
```

### Iterative Binary Search

```text
Time: O(log n)
Space: O(1)
```

### Recursive Binary Search

```text
Time: O(log n)
Space: O(log n)
```

The recursive version uses stack space for the recursive calls.

---

# 7. Two Pointers Complexity

Typical implementation:

```cpp
i=0;
j=n-1;

while(i<j)
{
    ...
}
```

If both pointers move toward each other, each pointer can move through the input at most once.

```text
i → O(n) movements
j → O(n) movements
```

Total:

```text
O(n) + O(n)
= O(n)
```

Therefore:

```text
Time: O(n)
```

If no additional data structure is used:

```text
Space: O(1)
```

---

# 8. Sliding Window Complexity

A typical Sliding Window uses two pointers:

```text
left
right
```

The pointers generally move through the input rather than restarting from the beginning.

```text
right → O(n) movements
left  → O(n) movements
```

Total:

```text
O(n) + O(n)
= O(n)
```

Therefore:

```text
Time: O(n)
```

### Space

If using a fixed alphabet frequency array:

```text
Space: O(1)
```

Example:

```cpp
int f[26]={0};
```

If using a hashmap containing `k` distinct elements:

```text
Space: O(k)
```

---

# 9. Hashing Complexity

## `unordered_map`

Average-case:

```text
insert()  → O(1)
find()    → O(1)
access    → O(1)
erase()   → O(1)
```

Worst-case for hash operations can reach:

```text
O(n)
```

due to collisions.

For normal DSA analysis:

```text
unordered_map operation
→ O(1) average
```

If the map stores `n` elements:

```text
Space: O(n)
```

---

## `unordered_set`

Average-case:

```text
insert()  → O(1)
find()    → O(1)
count()   → O(1)
erase()   → O(1)
```

Worst-case:

```text
O(n)
```

due to collisions.

Space:

```text
O(n)
```

for `n` stored elements.

---

# 10. Frequency Array Complexity

For lowercase English letters:

```cpp
int f[26]={0};

for(char c:s)
{
    f[c-'a']++;
}
```

The string is traversed once.

```text
Time: O(n)
```

The frequency array always has 26 positions.

```text
Space: O(26)
      = O(1)
```

Important:

```text
Fixed-size data structure
→ O(1) space
```

even when the input size `n` grows.

---

# 11. String Complexity

For a string of length `n`:

## Character Access

```cpp
s[i]
```

```text
Time: O(1)
```

---

## String Traversal

```cpp
for(i=0;i<n;i++)
{
    ...
}
```

```text
Time: O(n)
```

---

## Sorting

```cpp
sort(s.begin(),s.end());
```

```text
Time: O(n log n)
```

---

## Copying a String

```cpp
string temp=s;
```

If the string has length `n`:

```text
Time: O(n)
Space: O(n)
```

---

# 12. STL Complexity

## `vector`

```text
v[i]              → O(1)
push_back()       → O(1) amortized
pop_back()        → O(1)
search            → O(n)
insert middle     → O(n)
erase middle      → O(n)
sort              → O(n log n)
```

Space for `n` elements:

```text
O(n)
```

### Why `push_back()` is O(1) Amortized

Most insertions simply place the new element at the end.

Occasionally, when the vector's capacity is full, it allocates a larger block and moves/copies existing elements.

That expensive operation does not happen on every insertion.

Therefore, over a sequence of insertions:

```text
push_back()
→ O(1) amortized
```

---

## `string`

```text
s[i]              → O(1)
s.size()          → O(1)
traversal         → O(n)
sort              → O(n log n)
```

Space for a string of length `n`:

```text
O(n)
```

---

## `array`

For:

```cpp
array<int,n> a;
```

or a fixed C-style array:

```cpp
int a[n];
```

Common operations:

```text
a[i]              → O(1)
search            → O(n)
traversal         → O(n)
```

Space:

```text
O(n)
```

---

## `unordered_map`

```text
insert()          → O(1) average
find()            → O(1) average
access            → O(1) average
erase()           → O(1) average
```

Space:

```text
O(n)
```

---

## `unordered_set`

```text
insert()          → O(1) average
find()            → O(1) average
count()           → O(1) average
erase()           → O(1) average
```

Space:

```text
O(n)
```

---

## `map`

`map` is generally implemented using a balanced Binary Search Tree.

```text
insert()          → O(log n)
find()            → O(log n)
access            → O(log n)
erase()           → O(log n)
```

Space:

```text
O(n)
```

Elements are maintained in sorted order.

---

## `set`

`set` is generally implemented using a balanced Binary Search Tree.

```text
insert()          → O(log n)
find()            → O(log n)
count()           → O(log n)
erase()           → O(log n)
```

Space:

```text
O(n)
```

Elements are maintained in sorted order.

---

## `stack`

```text
push()            → O(1)
pop()             → O(1)
top()             → O(1)
empty()           → O(1)
```

Space for `n` elements:

```text
O(n)
```

---

## `queue`

```text
push()            → O(1)
pop()             → O(1)
front()           → O(1)
back()            → O(1)
empty()           → O(1)
```

Space:

```text
O(n)
```

---

## `deque`

```text
push_front()      → O(1)
push_back()       → O(1)
pop_front()       → O(1)
pop_back()        → O(1)
access [i]        → O(1)
middle insertion  → O(n)
middle erase      → O(n)
```

Space:

```text
O(n)
```

---

## `priority_queue`

`priority_queue` is implemented using a heap.

```text
top()             → O(1)
push()            → O(log n)
pop()             → O(log n)
```

Building a heap from an existing collection:

```text
O(n)
```

Space:

```text
O(n)
```

---

## `sort()`

```cpp
sort(a.begin(),a.end());
```

```text
Time: O(n log n)
```

For normal DSA analysis:

```text
sort() → O(n log n)
```

---

## `binary_search()`

For a sorted range:

```cpp
binary_search(a.begin(),a.end(),x);
```

```text
Time: O(log n)
Space: O(1)
```

---

# 13. Space Complexity

## O(1) Space

Only a fixed number of variables are used.

```cpp
int i,j,temp;
```

The number of variables does not grow with `n`.

```text
Space: O(1)
```

---

## O(n) Space

Memory grows with the input size.

```cpp
vector<int> b(n);
```

The vector contains `n` elements.

```text
Space: O(n)
```

---

## O(k) Space

Sometimes the algorithm stores only `k` distinct or relevant elements.

Example:

```cpp
unordered_map<char,int> mp;
```

If there are `k` distinct characters:

```text
Space: O(k)
```

If the possible characters are fixed to 26 lowercase letters:

```text
k ≤ 26
```

Therefore:

```text
O(26) = O(1)
```

---

# 14. Recursion and Space

Recursive calls use the call stack.

Example:

```cpp
int f(int n)
{
    if(n==0)
    {
        return 0;
    }

    return f(n-1);
}
```

There can be `n` active recursive calls.

```text
Space: O(n)
```

For tree recursion, if the maximum recursion depth is the tree height `h`:

```text
Space: O(h)
```

---

## Balanced Tree

For a balanced tree:

```text
h = O(log n)
```

Therefore:

```text
Recursive stack space: O(log n)
```

---

## Skewed Tree

For a completely skewed tree:

```text
h = O(n)
```

Therefore:

```text
Recursive stack space: O(n)
```

---

# 15. Tree Traversal Complexity

For a tree containing `n` nodes:

```text
DFS/BFS visits each node once.
```

Therefore:

```text
Time: O(n)
```

## Recursive DFS

The recursion stack depends on the tree height.

```text
Space: O(h)
```

where `h` is the height of the tree.

## BFS

BFS uses a queue.

In the worst case, the queue can contain a large portion of the tree.

```text
Space: O(n)
```

---

# 16. Prefix Sum Complexity

Given an array of `n` elements:

```cpp
pref[0]=a[0];

for(i=1;i<n;i++)
{
    pref[i]=pref[i-1]+a[i];
}
```

Every element is processed once.

```text
Build Time: O(n)
```

The prefix array contains `n` elements.

```text
Space: O(n)
```

After construction, a range sum can be answered using two prefix values:

```text
sum = pref[right] - pref[left-1]
```

Therefore:

```text
Query Time: O(1)
```

---

# 17. Common Algorithm Complexity Patterns

## Linear Search

```text
Time: O(n)
Space: O(1)
```

Potentially checks every element.

---

## Binary Search

```text
Time: O(log n)
Space: O(1) iterative
```

The search space is repeatedly divided by 2.

---

## Two Pointers

Usually:

```text
Time: O(n)
Space: O(1)
```

when both pointers move through the input without additional storage.

---

## Sliding Window

Usually:

```text
Time: O(n)
```

because the left and right pointers each move through the input a limited number of times.

Space depends on what the window stores:

```text
Fixed alphabet frequency array → O(1)
Hashmap of k distinct elements → O(k)
```

---

## Hashing

Typical frequency/existence solution:

```text
Time: O(n) average
Space: O(n)
```

The input is traversed once and the hash table may store up to `n` distinct elements.

---

## Sorting + Traversal

```text
sort()     → O(n log n)
traversal  → O(n)
```

Total:

```text
O(n log n) + O(n)
= O(n log n)
```

---

## Nested Loops

If both loops run `n` times:

```text
O(n²)
```

If there are three nested loops, each running `n` times:

```text
O(n³)
```

---

# 18. Complexity of Common Foundation Concepts

| Concept                   | Typical Time |             Typical Space |
| ------------------------- | -----------: | ------------------------: |
| Array indexing            |         O(1) |                O(1) extra |
| Array traversal           |         O(n) |                O(1) extra |
| String indexing           |         O(1) |                O(1) extra |
| String traversal          |         O(n) |                O(1) extra |
| Frequency array           |         O(n) |                      O(1) |
| `unordered_map` frequency | O(n) average |                      O(n) |
| `unordered_set` existence | O(n) average |                      O(n) |
| Two Pointers              |         O(n) |                      O(1) |
| Sliding Window            |         O(n) |              O(1) or O(k) |
| Binary Search             |     O(log n) |            O(1) iterative |
| Prefix Sum construction   |         O(n) |                      O(n) |
| Prefix Sum query          |         O(1) |                      O(1) |
| Tree DFS                  |         O(n) |            O(h) recursive |
| Tree BFS                  |         O(n) |           O(n) worst case |
| Sorting                   |   O(n log n) | Depends on implementation |

---

# 19. Constraint-Based Complexity Selection

Use input constraints to estimate what complexity is likely to be acceptable.

These are rough guidelines, not strict limits.

```text
n ≤ 10
→ O(n!), O(2ⁿ) may be possible

n ≤ 20
→ O(2ⁿ) may be possible

n ≤ 100
→ O(n³) may be possible

n ≤ 1,000
→ O(n²) may be possible

n ≤ 100,000
→ Usually O(n log n) or O(n)

n ≤ 1,000,000
→ Usually O(n) or better
```

Always consider:

* Number of test cases
* Actual operations inside loops
* Programming language
* Memory limit
* Constant factors
* Whether the input is sorted
* Whether the input has special properties

---

# 20. Time Complexity vs Space Complexity

## Time Complexity

Describes how the amount of computational work grows with input size.

Common growth rates:

```text
O(1)
O(log n)
O(n)
O(n log n)
O(n²)
O(2ⁿ)
O(n!)
```

## Space Complexity

Describes how additional memory usage grows with input size.

Common growth rates:

```text
O(1)
O(log n)
O(n)
...
```

Time and space are independent.

An algorithm can have:

```text
Time: O(n)
Space: O(1)
```

or:

```text
Time: O(n)
Space: O(n)
```

or:

```text
Time: O(n log n)
Space: O(1)
```

---

# 21. Auxiliary Space vs Output Space

## Auxiliary Space

Extra memory used by the algorithm apart from the required output.

Example:

```cpp
vector<int> temp(n);
```

If `temp` is temporary working memory:

```text
Auxiliary Space: O(n)
```

## Output Space

Memory required to store the answer.

If the problem requires returning `n` elements, that output memory may be reported separately.

When discussing space complexity, clarify whether output space is included or excluded.

---

# 22. Important Complexity Rules

## O(1)

Fixed amount of work.

Example:

```cpp
x=a[5];
```

One direct access.

---

## O(log n)

The problem size is repeatedly reduced by a constant factor.

Example:

```text
n
→ n/2
→ n/4
→ n/8
→ ...
→ 1
```

---

## O(n)

Every element may need to be processed.

Example:

```cpp
for(i=0;i<n;i++)
{
    ...
}
```

---

## O(n log n)

`n` work combined with `log n` work.

Common example:

```text
Efficient sorting
```

---

## O(n²)

Approximately `n` work for each of `n` elements.

Example:

```cpp
for(i=0;i<n;i++)
{
    for(j=0;j<n;j++)
    {
        ...
    }
}
```

---

## O(2ⁿ)

The number of possibilities approximately doubles when one more input element is added.

Common example:

```text
Generating all subsets
```

---

## O(n!)

All possible orderings/permutations are considered.

Common example:

```text
Generating all permutations
```

---

# 23. Core Complexity Reference

```text
Array/vector indexing
→ O(1)

Array/vector traversal
→ O(n)

String indexing
→ O(1)

String traversal
→ O(n)

Binary Search
→ O(log n)

Two Pointers
→ usually O(n)

Sliding Window
→ usually O(n)

Frequency Array
→ O(n) time, O(1) space for fixed alphabet

unordered_map operation
→ O(1) average

unordered_set operation
→ O(1) average

map operation
→ O(log n)

set operation
→ O(log n)

Stack operations
→ O(1)

Queue operations
→ O(1)

Deque front/back operations
→ O(1)

Priority Queue top
→ O(1)

Priority Queue push/pop
→ O(log n)

sort()
→ O(n log n)

binary_search()
→ O(log n)

Tree DFS/BFS
→ O(n) time

Recursive tree DFS
→ O(h) stack space

Prefix Sum construction
→ O(n)

Prefix Sum query
→ O(1)
```

---

# 24. Complexity Analysis Checklist

When solving a new problem:

```text
1. Read the constraints.

2. Identify the input size.

3. Estimate what complexity can work.

4. Think of possible approaches.

5. For each approach, calculate Time Complexity:
   - How many loops?
   - Are loops nested?
   - How many times does each loop run?
   - Is the problem repeatedly divided?
   - Are pointers moving through the input?
   - Are there recursive calls?
   - Are STL operations being used?

6. Calculate Space Complexity:
   - Arrays/vectors?
   - Maps/sets?
   - Strings/copies?
   - Stack/queue?
   - Recursion stack?

7. Check whether the complexity fits the constraints.

8. Choose the approach.

9. Implement the solution.

10. Re-check Time and Space Complexity.

---

# 25. Final Rules

- Big-O describes growth, not exact seconds or bytes.
- `O(1)` means the amount of work or memory does not grow with `n`.
- `O(log n)` commonly comes from repeatedly reducing the problem by a constant factor.
- `O(n)` means the work grows proportionally with the input size.
- `O(n log n)` commonly appears in efficient sorting.
- `O(n²)` commonly comes from nested loops.
- `unordered_map` and `unordered_set` provide average `O(1)` operations, not guaranteed `O(1)`.
- `map` and `set` provide `O(log n)` operations because they are generally implemented using balanced trees.
- Two Pointers and Sliding Window are usually `O(n)` because the pointers move through the input a limited number of times.
- A fixed-size array such as `int f[26]` uses `O(1)` space because its size does not depend on `n`.
- Recursive algorithms must account for call-stack memory.
- Time and space complexity should be derived from the actual code and algorithm rather than blindly memorized.
- Always consider input constraints before choosing an algorithm.
```

# Recursion

# What is Recursion?

Recursion is a programming technique where a function calls itself to solve a smaller version of the same problem.

Instead of using loops, the problem is repeatedly reduced until it reaches a stopping condition.

---

# Why Recursion?

Some problems are naturally recursive.

Examples:

- Trees
- Graph DFS
- Backtracking
- Divide & Conquer
- Dynamic Programming

Without recursion, many of these problems become much harder to write.

---

# Two Important Parts

Every recursive function must contain:

1. Base Case
2. Recursive Case

---

# Base Case

The condition that stops recursion.

Without a Base Case,

↓

Infinite function calls

↓

Stack Overflow

↓

Program Crash

Example

```cpp
if(n==0)
    return;
```

Think of it as the stopping condition of a loop.

---

# Recursive Case

The function calls itself with a smaller problem.

Example

```cpp
print(n-1);
```

Every recursive call should move closer to the Base Case.

---

# General Structure

```cpp
void fun(parameters)
{
    // Base Case

    if(condition)
        return;

    // Work

    ...

    // Recursive Call

    fun(smaller_problem);

    // Remaining Work (optional)
}
```

---

# Golden Rule

Everything written

BEFORE

the recursive call

↓

executes while going DOWN.

Everything written

AFTER

the recursive call

↓

executes while coming BACK UP.

Example

```cpp
cout<<n;

fun(n-1);

cout<<n;
```

Output for

fun(3)

↓

Going Down

3 2 1

↓

Coming Up

1 2 3

Final Output

3 2 1 1 2 3

---

# Call Stack

Every recursive function call is stored in memory.

Example

fun(1)

↓

fun(2)

↓

fun(3)

↓

fun(4)

↓

Base Case

After reaching the Base Case,

the function returns one level at a time.

This process is called

Stack Unwinding.

---

# Mental Model

Think of recursion like climbing stairs.

Going Up

↓

Recursive Calls

Reaching the Top

↓

Base Case

Coming Down

↓

Returning from Function Calls

---

# Common Mistakes

❌ Forgetting the Base Case.

❌ Base Case never becomes true.

❌ Recursive call does not reduce the problem.

❌ Infinite recursion causing Stack Overflow.

❌ Confusing return with break.

return

↓

Ends the current function.

break

↓

Ends only a loop.

---

# Questions to Ask Before Writing Recursion

1.

What is the smallest version of this problem?

↓

Base Case

----------------------------

2.

How can I reduce the current problem into a smaller one?

↓

Recursive Call

----------------------------

3.

What should happen

before

the recursive call?

----------------------------

4.

What should happen

after

the recursive call?

---

# Problems To Solve

Easy

- [ ] Factorial
- [ ] Sum of First N Numbers
- [ ] Print 1 to N
- [ ] Print N to 1
- [ ] Fibonacci

---------------------------------------

Medium

- [ ] Reverse Array
- [ ] Check Palindrome
- [ ] Binary Search (Recursive)

---------------------------------------

Advanced

- [ ] Subsequences
- [ ] Combination Sum
- [ ] Permutations
- [ ] N Queens
- [ ] Sudoku Solver

---

# Key Takeaways

✔ Every recursion needs a Base Case.

✔ Every recursive call must move closer to the Base Case.

✔ Think in terms of smaller subproblems.

✔ Learn the Call Stack before solving recursion problems.

✔ Trees are simply Recursion applied to nodes.

---


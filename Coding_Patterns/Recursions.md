# Recursion

# What is Recursion?

Recursion is a programming technique where a function calls itself to solve a smaller version of the same problem.

Instead of repeating work using loops, recursion repeatedly reduces the problem until it reaches a stopping condition.

---

# Why Recursion?

Some problems are naturally recursive.

Examples:

- Trees
- Graph DFS
- Backtracking
- Divide & Conquer
- Dynamic Programming

Without recursion, solving many of these problems becomes much harder.

---

# When Should I Think of Recursion?

Whenever:

- The problem can be divided into smaller identical subproblems.
- The current answer depends on the answer of a smaller problem.
- A tree or graph traversal is involved.
- The problem naturally asks to "do the same thing again."

Always ask yourself:

**"Can I solve a smaller version of this problem?"**

If yes, recursion is probably a good choice.

---

# Two Important Parts

Every recursive function must have:

1. Base Case
2. Recursive Case

Missing either one usually leads to incorrect or infinite recursion.

---

# Base Case

The Base Case is the stopping condition.

It prevents the recursive function from calling itself forever.

Example:

```cpp
if(n==0)
    return;
```

Think of it exactly like the condition of a loop.

For Loop

```cpp
for(i=1;i<=5;i++)
```

Stopping Condition

```cpp
i>5
```

Recursion

```cpp
if(n>5)
    return;
```

Without a Base Case:

↓

Infinite Function Calls

↓

Stack Overflow

↓

Program Crash

---

# Recursive Case

The Recursive Case solves a smaller version of the same problem.

Example

```cpp
print(n+1);
```

or

```cpp
factorial(n-1);
```

Every recursive call should move closer to the Base Case.

Otherwise,

the recursion never ends.

---

# General Structure

```cpp
return_type fun(parameters)
{
    // Base Case

    if(condition)
        return value;

    // Current Work

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

Calling

```cpp
fun(3);
```

Output

```
3 2 1 1 2 3
```

Going Down

↓

3 2 1

Coming Up

↓

1 2 3

---

# Call Stack

Every function call is stored separately in memory.

Example

```
fun(1)
```

↓

```
fun(2)
```

↓

```
fun(3)
```

↓

```
fun(4)
```

↓

Base Case

Once the Base Case is reached,

the functions finish one by one in reverse order.

This process is called

**Stack Unwinding.**

---

# Mental Model

Imagine climbing stairs.

Going Up

↓

Recursive Calls

Reach the Top

↓

Base Case

Come Down

↓

Returning from Function Calls

---

# return vs break

Many beginners confuse these.

return

↓

Ends the current function immediately.

Everything below it inside that function is skipped.

Example

```cpp
cout<<"A";

return;

cout<<"B";
```

Output

```
A
```

----------------------------

break

↓

Ends only the current loop.

It cannot be used to end a function.

---

# Dry Run Example

```cpp
void print(int n)
{
    if(n>5)
        return;

    cout<<n<<" ";

    print(n+1);

    cout<<"Done ";
}
```

Calling

```cpp
print(1);
```

Output

```
1 2 3 4 5 Done Done Done Done Done
```

Why?

- Numbers are printed while going DOWN.
- "Done" is printed while coming BACK UP.

---

# Questions To Ask Before Writing Recursion

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

What should happen BEFORE the recursive call?

↓

Going Down

----------------------------

4.

What should happen AFTER the recursive call?

↓

Coming Back Up

---

# Common Mistakes

❌ Forgetting the Base Case.

❌ Base Case is unreachable.

❌ Recursive call does not reduce the problem.

❌ Infinite recursion causing Stack Overflow.

❌ Confusing return with break.

❌ Not understanding the call stack.

---

# Problems To Solve

## Easy

- [ ] Factorial
- [ ] Sum of First N Numbers
- [ ] Print 1 to N
- [ ] Print N to 1
- [ ] Fibonacci

---------------------------------------

## Medium

- [ ] Reverse Array
- [ ] Check Palindrome
- [ ] Recursive Binary Search

---------------------------------------

## Advanced

- [ ] Subsequences
- [ ] Combination Sum
- [ ] Permutations
- [ ] N Queens
- [ ] Sudoku Solver

---

# Key Takeaways

✔ Every recursive function must have a Base Case.

✔ Every recursive call should move closer to the Base Case.

✔ Think in terms of smaller subproblems.

✔ Everything before the recursive call executes while going DOWN.

✔ Everything after the recursive call executes while coming BACK UP.

✔ Trees are simply recursion applied to nodes.

✔ Understanding the Call Stack is more important than memorizing recursion.

---

Status

🟨 In Progress
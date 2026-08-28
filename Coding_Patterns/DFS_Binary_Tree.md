# DFS — Depth First Search

## What is DFS?

DFS (Depth First Search) explores one branch as deeply as possible before coming back and exploring another branch.

Example:

        1
       / \
      2   3
     / \
    4   5

One DFS order:

1 → 2 → 4 → 5 → 3

DFS can be implemented using:

- Recursion
- Stack

For trees, recursion is usually the simplest.

---

## Basic Recursive DFS

    void dfs(TreeNode* p)
    {
        if(p==NULL)
        {
            return;
        }

        // process p

        dfs(p->left);
        dfs(p->right);
    }

Basic idea:

    current node
         ↓
       left
         ↓
       right

The order of processing `p` determines the traversal.

---

## DFS Traversal Orders

### Preorder

Root → Left → Right

    process p
    dfs(p->left)
    dfs(p->right)

### Inorder

Left → Root → Right

    dfs(p->left)
    process p
    dfs(p->right)

### Postorder

Left → Right → Root

    dfs(p->left)
    dfs(p->right)
    process p

---

## When to Think DFS

Think DFS when the problem involves:

- root-to-leaf paths
- paths
- subtrees
- height/depth
- recursively combining left and right subtree results
- exploring all possible branches
- backtracking
- carrying information down a path

Main idea:

    Path / subtree / recursive relationship
                    ↓
                   DFS

This is not a strict rule. Some problems can be solved using either BFS or DFS.

---

## Recursive Tree Thinking

Every node can be treated as:

    Current node
        +
    Left subtree
        +
    Right subtree

So many problems become:

    Solve left
        ↓
    Solve right
        ↓
    Use/combine the results

For example:

    left height
    right height
         ↓
    1 + max(left,right)

---

## DFS With Extra State

Sometimes the recursive call needs information from the path above it.

Then pass that information as a parameter.

Example:

    void dfs(TreeNode* p,int target)

Here:

    p      → current node
    target → remaining state

Other common state:

    int sum
    int num
    int mx
    vector<int>& path

Ask:

"What information must travel with me as I go deeper?"

---

## Path + DFS

For root-to-leaf path problems:

    path.push_back(p->val);

    dfs(p->left);
    dfs(p->right);

    path.pop_back();

`push_back()` means:

    go deeper with this node in the path

`pop_back()` means:

    come back from this node

This is called BACKTRACKING.

---

## DFS + Backtracking

General pattern:

    choose
       ↓
    explore
       ↓
    undo

For a tree path:

    path.push_back(p->val);

    explore left
    explore right

    path.pop_back();

The `pop_back()` is important when the same path vector is shared between recursive calls.

---

## Helper Functions

A helper is useful when the recursive process needs extra state or a separate recursive function is more convenient.

Before creating one, ask:

"Can the recursive function work with the parameters I already have?"

If yes, a separate helper may not be needed.

If extra state is needed:

    dfs(node, state)

---

## Choosing the Return Type

After deciding that a recursive/helper function is needed, ask:

"What does the caller need back?"

YES / NO:

    bool

A number:

    int

A node:

    TreeNode*

Nothing:

    void

Examples:

    Does this subtree contain the value?
    → bool

    What is the height of this subtree?
    → int

    Which node should be returned?
    → TreeNode*

    Just traverse and update ans/path:
    → void

---

## Common DFS Patterns

### 1. Return Information From Children

    left=dfs(p->left);
    right=dfs(p->right);

    // combine left and right

Use this when the current node needs results from its children.

Example idea:

    height = 1 + max(left,right)

---

### 2. Carry Information Down

    dfs(p->left,target);
    dfs(p->right,target);

Here `target` changes as we go deeper.

Useful for:

- target sums
- current number
- current sum
- maximum seen so far
- current path

---

### 3. Global / Shared Answer

Sometimes the DFS does not need to return the final answer.

Instead:

    int ans;

and the DFS updates it.

Example:

    ans=max(ans,value);

Then:

    void dfs(...)

can be enough.

---

## DFS vs BFS

### DFS

    Go deep
        ↓
    Come back
        ↓
    Explore next branch

Usually:

    recursion / stack

Natural for:

    paths
    subtrees
    height
    recursive relationships
    backtracking

### BFS

    Finish current level
        ↓
    Move to next level

Usually:

    queue

Natural for:

    levels
    distance
    nearest/closest
    shortest path in an unweighted graph

---

## DFS Is Not Only for Trees

DFS is a general traversal algorithm.

It can also be used on graphs.

Tree:

    dfs(TreeNode* p)

Graph:

    dfs(int node)

The main idea stays the same:

    Start
      ↓
    Visit current
      ↓
    Visit an unvisited neighbour
      ↓
    Continue deeper
      ↓
    Backtrack when necessary

For graphs, we usually need a `visited` structure to avoid visiting the same node repeatedly.

---

## DFS Decision

When you see a problem:

    What is it asking?
          ↓
    Path / subtree / recursive relationship?
          ↓
         DFS

Then ask:

    What information must travel down?
          ↓
    Add it as state/parameter

Then ask:

    Does the caller need something back?
          ↓
       Yes → choose return type
       No  → void/shared result

---

DFS + Path

When the problem asks for root-to-leaf paths:

    carry the current path downward
        ↓
    reach a leaf
        ↓
    save the path

The path can be passed as a parameter:

    dfs(node,path)

If using a shared vector/string:
    add current node
    explore
    remove current node

If passing `path` by value:
    each recursive call gets its own copy,
    so explicit backtracking is not required.

## Core Idea

DFS = depth-first exploration.

For trees, think:

    Current node
         ↓
    Left subtree
         ↓
    Right subtree

And when solving a recursive problem, always identify:

    What do I know now?
        ↓
    What must I pass down?
        ↓
    What must I get back?
        ↓
    What do I do with the result?
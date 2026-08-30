# Trees

## What is a Tree?

A tree is a hierarchical data structure made of nodes connected by edges.

Unlike arrays/linked lists, a tree can branch into multiple nodes.

Example:

        1
       / \
      2   3
     / \
    4   5

---

## Basic Terminology

- Root → topmost node of the tree.
- Parent → node directly above another node.
- Child → node directly below another node.
- Leaf → node with no children.
- Edge → connection between two nodes.
- Subtree → a node together with all of its descendants.
- Depth → number of edges from the root to a node.
- Height → number of edges on the longest path from a node to a leaf.


## Height vs Depth

### Depth

Depth tells us how far a node is from the root.

Root:

    depth = 0

Each edge going downward increases depth by 1.

### Height

Height tells us how far a node is from its deepest leaf.

Leaf:

    height = 0

For a node:

    height = 1 + max(left height,right height)

### Example

        1
       / \
      2   3
     /
    4

Depth:

    1 → 0
    2 → 1
    4 → 2

Height:

    4 → 0
    2 → 1
    1 → 2

### Important

Depth is measured from:

    Root → Node

Height is measured from:

    Node → Deepest Leaf

In recursive DFS problems, we commonly calculate height
because the information can be returned from the children
back to the parent.


---

## Binary Tree

A binary tree is a tree where every node has at most two children:

- Left child
- Right child

Typical C++ representation:

    struct TreeNode
    {
        int val;
        TreeNode* left;
        TreeNode* right;
    };

A node can have:

- 0 children → leaf
- 1 child
- 2 children

---

## Binary Tree vs BST

### Binary Tree

Only restriction:

Each node has at most 2 children.

There is no ordering requirement.

### Binary Search Tree (BST)

A BST follows an ordering rule:

left subtree < root < right subtree

Example:

        8
       / \
      3   10
     / \    \
    1   6    14

This ordering can be used to search efficiently.

---

## Tree Traversal

Traversal means visiting the nodes of a tree in a systematic order.

### DFS — Depth First Search

Go deeper into a branch before coming back.

Common recursive traversals:

Preorder  → Root → Left → Right

Inorder   → Left → Root → Right

Postorder → Left → Right → Root

### BFS — Breadth First Search

Visit nodes level by level.

DFS and BFS are general traversal techniques and are not limited to trees.

---

## Recursive Thinking in Trees

Trees are naturally recursive because every node can be viewed as:

Current node
+
Left subtree
+
Right subtree

Common structure:

    if(p==NULL)
    {
        return;
    }

    solve(p->left);
    solve(p->right);

The base case usually handles p==NULL.

Then the current node is processed and the smaller subtrees are solved recursively.

---

## How to Approach a Tree Problem

Before coding, ask:

### 1. What is the problem asking?

Examples:

- level / distance
- path
- height / depth
- subtree
- search
- maximum / minimum
- sum

### 2. What traversal fits naturally?

Levels / distance → BFS is often natural.

Paths / subtrees / recursive relationships → DFS is often natural.

This is not a strict rule. Many tree problems can be solved using either approach.

### 3. What information needs to move through the traversal?

Examples:

- remaining target
- current sum
- current number
- maximum seen so far
- current path
- level information

That information becomes part of the recursive state or traversal state.

---

## Helper Functions in Tree Problems

A helper function is useful when the recursive process needs something that the main function does not naturally provide.

For example:

    void dfs(TreeNode* p,int target)

Here:

p → current node

target → extra state needed during recursion

Before creating a helper, ask:

Can the recursive function work using only the parameters I already have?

If yes, a separate helper may not be necessary.

If extra state is needed, a helper can carry it.

---

## Choosing the Helper Return Type

After deciding that a helper is needed, ask:

What does the caller need back from the recursive call?

YES / NO
→ bool

A number
→ int

A node
→ TreeNode*

Nothing
→ void

Examples:

"Does this subtree contain it?"
→ bool

"What is the height of this subtree?"
→ int

"Which node did you find?"
→ TreeNode*

"Just explore and update the answer."
→ void

---

## Parameters of a Recursive Helper

The parameters should represent the information required to solve the smaller version of the problem.

Common examples:

TreeNode* p
→ current node

int target
→ remaining target

int sum
→ current sum

int num
→ number formed so far

vector<int>& path
→ current path

int mx
→ maximum value seen so far

Important question:

"What information must travel with me as I go deeper?"

---

## Common Tree Problem Patterns

### 1. Simple Recursive Tree Problem

Current node
↓
Solve left subtree
↓
Solve right subtree
↓
Combine/use results

### 2. Path Problem

Move down the tree
↓
Carry current path/state
↓
Reach leaf
↓
Check condition

May require backtracking when using a shared path.

### 3. Level Problem

Use BFS
↓
Process one level
↓
Calculate required information

### 4. BST Problem

Use the ordering property:

left < root < right

This can allow us to avoid exploring unnecessary parts of the tree.

---

## Key Mental Model

When you see a tree problem:

TREE
↓
What is being asked?
↓
Choose traversal / technique
↓
What information must be carried?
↓
Do I need a helper?
↓
If yes:
    What parameters?
    What return type?
↓
Solve current node + smaller subtrees

---

## Core Idea to Remember

A tree problem is usually about deciding what information you need from the current node, its left subtree, and its right subtree — and how that information should move through the tree.
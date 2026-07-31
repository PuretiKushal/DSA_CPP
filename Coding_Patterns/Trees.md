# Trees

# What is a Tree?

A Tree is a hierarchical (non-linear) data structure.

Unlike Arrays and Linked Lists, where elements are arranged in a line,
Trees organize data in parent-child relationships.

Example:

        A
      /   \
     B     C
    / \   / \
   D   E F   G

A is the Root.

B and C are children of A.

D, E, F and G are leaf nodes.

---

# Why Trees?

Arrays

10 20 30 40

↓

Linear

----------------------------

Linked List

10 → 20 → 30 → 40

↓

Linear

----------------------------

Tree

        A
      /   \
     B     C
    / \
   D   E

↓

Hierarchical

One node can have multiple children.

---

# Basic Terminology

Root
- The first node of the tree.

Parent
- A node having one or more children.

Child
- A node connected below a parent.

Leaf Node
- A node having no children.

Internal Node
- A node having at least one child.

Sibling
- Nodes having the same parent.

Ancestor
- Any node above the current node.

Descendant
- Any node below the current node.

Edge
- Connection between two nodes.

Path
- Sequence of nodes connected by edges.

Degree
- Number of children of a node.

---

# Binary Tree

A Binary Tree is a tree where every node has at most two children.

Possible children:

0

1

2

Not more than 2.

---

# Height

Height of a node

↓

Longest path from that node to any leaf.

Leaf node height = 0

---

# Depth

Depth of a node

↓

Distance from the Root to that node.

Root depth = 0

---

# Level

Level = Depth + 1

(Some books start levels from 0.)

---

# Important Properties

If a tree has N nodes,

Edges = N - 1

Every node except the Root has exactly one parent.

---

# Topics To Learn

- Tree Representation
- DFS
- BFS
- Tree Traversals
- Binary Search Tree
- Recursion on Trees
- Advanced Tree Problems

---

# Notes

(To be updated as I learn.)
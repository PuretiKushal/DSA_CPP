# Trees

# What is a Tree?

A Tree is a non-linear data structure used to represent hierarchical relationships between data.

Unlike an array or linked list, elements in a tree are connected through parent-child relationships.

Example

```
        A
       / \
      B   C
     / \
    D   E
```

---

# Why Do We Need Trees?

Arrays and linked lists store data linearly.

```
1 → 2 → 3 → 4 → 5
```

They tell us the order of elements but not their relationships.

For example, if we want to represent a family tree,

```
        Grandpa
        /     \
     Dad      Uncle
    /   \
 You   Sister
```

an array cannot naturally represent these parent-child connections.

Trees solve this problem by storing links between nodes.

---

# Tree Terminology

## Node

Each element of a tree is called a Node.

Example

```
        10
       /  \
      5    20
```

10, 5 and 20 are nodes.

---

# Root Node

The topmost node of a tree.

Every tree has exactly one root.

```
        10
       /  \
      5    20
```

Root = 10

---

# Parent and Child

If a node is directly connected to another node below it,

the upper node is the Parent,

the lower node is the Child.

```
      10
     /
    5
```

Parent of 5 = 10

Child of 10 = 5

---

# Leaf Node

A node with no children.

```
        10
       /  \
      5    20
     /
    2
```

Leaf Nodes = 2, 20

---

# Binary Tree

A Binary Tree is a tree in which every node can have at most two children.

```
        10
       /  \
      5    20
```

Children are usually called

- Left Child
- Right Child

---

# Representation in C++

```cpp
struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
};
```

Every TreeNode stores

- Value
- Pointer to left child
- Pointer to right child

---

# Why Are left and right Pointers?

Suppose we write

```cpp
TreeNode left;
```

inside the structure.

Now every TreeNode would contain another complete TreeNode.

That new TreeNode would again contain another TreeNode.

This process would continue forever.

To avoid infinite nesting, we store only the memory address of the child node.

```cpp
TreeNode *left;
TreeNode *right;
```

A pointer stores only the address of another TreeNode.

---

# Pointer Meaning

```cpp
TreeNode *root;
```

Creates only a pointer variable.

No TreeNode exists yet.

---

```cpp
TreeNode root;
```

Creates one TreeNode object.

---

```cpp
new TreeNode();
```

Creates one TreeNode object on the heap and returns its memory address.

---

```cpp
TreeNode *root = new TreeNode();
```

Creates

- one pointer variable (`root`)
- one TreeNode object

The pointer stores the address of the TreeNode.

---

# Stack vs Heap

Local variables are stored on the Stack.

Example

```cpp
TreeNode root;
```

The object is automatically destroyed when the function ends.

---

Objects created using

```cpp
new TreeNode();
```

are stored on the Heap.

They continue to exist until explicitly deleted.

---

# The Arrow Operator (->)

The arrow operator accesses a member of the object pointed to by a pointer.

```cpp
root->val
```

is exactly the same as

```cpp
(*root).val
```

Example

```cpp
root->left->right->val
```

Mental Model

```
Start at root

↓

Follow left pointer

↓

Follow right pointer

↓

Read val
```

Every `->` means:

**Follow the pointer, then access a member.**

---

# Multiple Pointers

```cpp
TreeNode *root = new TreeNode();

TreeNode *p = root;
```

No new TreeNode is created.

Only another pointer is created.

Both pointers store the same memory address.

Changing the node through one pointer affects the same node.

---

# Mental Model

Whenever you see

```cpp
root->left->right->left->val
```

Think

```
Start from root

↓

Go to left child

↓

Go to right child

↓

Go to left child

↓

Read value
```

Do not memorize the syntax.

Always visualize moving from one node to another using pointers.

---

# Key Takeaways

✔ Trees represent hierarchical relationships.

✔ Every node stores a value and links to its children.

✔ `TreeNode *left` stores an address, not a complete node.

✔ `TreeNode *root;` creates only a pointer.

✔ `new TreeNode()` creates a TreeNode on the heap.

✔ `->` means follow the pointer and access a member.

✔ Multiple pointers can point to the same TreeNode.

✔ Always visualize memory instead of memorizing syntax.

---

Status

🟨 In Progress
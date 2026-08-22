# BFS — Breadth First Search

## What is BFS?

BFS (Breadth First Search) explores nodes level by level.

In a tree:

        1
       / \
      2   3
     / \
    4   5

BFS order:

1 → 2 → 3 → 4 → 5

BFS usually uses a queue.

Queue → FIFO (First In, First Out)

---

## Basic BFS

    queue<TreeNode*> q;

    q.push(root);

    while(!q.empty())
    {
        TreeNode* p=q.front();
        q.pop();

        // process p

        if(p->left!=NULL)
        {
            q.push(p->left);
        }

        if(p->right!=NULL)
        {
            q.push(p->right);
        }
    }

Basic queue operations:

q.push(x) → add to queue

q.front() → get first element

q.pop() → remove first element

q.empty() → check whether queue is empty

---

## Level-by-Level BFS

If the problem needs information for each level, use:

    n=q.size();

    for(i=0;i<n;i++)

Example:

    while(!q.empty())
    {
        n=q.size();

        for(i=0;i<n;i++)
        {
            TreeNode* p=q.front();
            q.pop();

            // process p

            if(p->left!=NULL)
            {
                q.push(p->left);
            }

            if(p->right!=NULL)
            {
                q.push(p->right);
            }
        }
    }

Important:

n = number of nodes in the current level.

Take n BEFORE processing the level.

Children added during the loop belong to the next level.

---

## When to Think BFS

Think BFS when the problem involves:

- levels
- level order
- each row
- leftmost/rightmost node of a level
- sum/max/min per level
- average per level
- nearest / closest
- minimum distance
- shortest path in an unweighted graph

Main idea:

Level / distance → BFS is often natural.

---

## Common Level Operations

Maximum:

    mx=INT_MIN;
    mx=max(mx,p->val);

Minimum:

    mn=INT_MAX;
    mn=min(mn,p->val);

Sum:

    sum=0;
    sum=sum+p->val;

Count:

    count++;

First node of level:

    if(i==0)

Last node of level:

    if(i==n-1)

Average:

    sum/n

---

## One Answer Per Level

If every level produces one value:

    vector<int> ans;

After processing the level:

    ans.push_back(value);

Example:

    while(!q.empty())
    {
        n=q.size();
        mx=INT_MIN;

        for(i=0;i<n;i++)
        {
            TreeNode* p=q.front();
            q.pop();

            mx=max(mx,p->val);

            if(p->left!=NULL)
            {
                q.push(p->left);
            }

            if(p->right!=NULL)
            {
                q.push(p->right);
            }
        }

        ans.push_back(mx);
    }

---

## Whole Level as a Vector

If the answer needs all nodes of every level:

    vector<vector<int>> ans;

For each level:

    vector<int> temp;

    temp.push_back(p->val);

After the level:

    ans.push_back(temp);

This is useful for level order and zigzag traversal.

---

## First and Last Node

BFS processes a level from left to right.

First node:

    if(i==0)

Last node:

    if(i==n-1)

Therefore:

Leftmost → i==0

Rightmost → i==n-1

---

## Zigzag BFS

Normal BFS:

left → right
left → right
left → right

Zigzag:

left → right
right → left
left → right

Still use BFS.

Collect the current level into temp, then reverse when required:

    reverse(temp.begin(),temp.end());

The BFS structure itself does not change.

---

## When n=q.size() Is NOT Needed

If the problem does not care about individual levels:

    queue<TreeNode*> q;

    q.push(root);

    while(!q.empty())
    {
        TreeNode* p=q.front();
        q.pop();

        // process p

        if(p->left!=NULL)
        {
            q.push(p->left);
        }

        if(p->right!=NULL)
        {
            q.push(p->right);
        }
    }

No n.

No inner for loop.

---

## Empty Tree

For problems returning a vector:

    if(root==NULL)
    {
        return ans;
    }

This prevents putting NULL into the queue.

---

## BFS Decision

When you see a tree problem:

What is it asking?

    Level / distance?
        ↓
       BFS

If it needs information for each level:

    BFS
     ↓
    n=q.size()
     ↓
    for(i=0;i<n;i++)

Then decide what to calculate:

    maximum → mx
    minimum → mn
    sum     → sum
    count   → count
    first   → i==0
    last    → i==n-1
    average → sum/n

---

## Important Exception

Maximum Width of Binary Tree is different.

Normal:

    n=q.size();

only counts actual nodes.

For maximum width, empty positions also matter.

So we may need to store:

    node + position

instead of only:

    node

This is an extension of BFS.

---

## Core Idea

BFS = queue + breadth/level-wise exploration.

If the problem cares about levels:

BFS + n=q.size()

If it cares about distance in an unweighted structure:

BFS is often a strong choice.

The queue controls the order in which nodes are explored.
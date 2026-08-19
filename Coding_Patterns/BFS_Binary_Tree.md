/*
BFS — Binary Tree

PATTERN:
- BFS = Breadth First Search.
- Traverses the tree level by level.
- Main data structure = queue (FIFO).

--------------------------------------------------

BASIC BFS:

queue<TreeNode*> q;
q.push(root);

while(!q.empty())
{
    TreeNode* p=q.front();
    q.pop();

    // process p

    if(p->left!=NULL)
        q.push(p->left);

    if(p->right!=NULL)
        q.push(p->right);
}

--------------------------------------------------

LEVEL-BY-LEVEL BFS:

If the question asks something for EACH LEVEL:

n=q.size();

while(!q.empty())
{
    n=q.size();

    for(i=0;i<n;i++)
    {
        TreeNode* p=q.front();
        q.pop();

        // process p

        if(p->left!=NULL)
            q.push(p->left);

        if(p->right!=NULL)
            q.push(p->right);
    }
}

IMPORTANT:
- n = number of nodes in the current level.
- Take n BEFORE processing the level.
- Children pushed during this loop belong to the next level.

--------------------------------------------------

WHAT TO USE:

Maximum:
mx=max(mx,p->val);

Minimum:
mn=min(mn,p->val);

Sum:
sum=sum+p->val;

Count:
count++;

First node:
if(i==0)

Last node:
if(i==n-1)

Average:
sum/n

--------------------------------------------------

IF EACH LEVEL NEEDS A VECTOR:

vector<int> temp;

temp.push_back(p->val);

After the level:
ans.push_back(temp);

Used for problems like Level Order / Zigzag.

--------------------------------------------------

ZIGZAG:

Normal:
left → right

Next:
right → left

Collect the level in temp, then:

reverse(temp.begin(),temp.end());

--------------------------------------------------

WHEN TO THINK BFS:

- Level order
- Each level / each row
- Leftmost / rightmost node of a level
- Maximum / minimum per level
- Sum / average per level
- Zigzag level order

Think:

BFS → queue

Level information → queue + n=q.size()

--------------------------------------------------

IMPORTANT EXCEPTION:

Maximum Width of Binary Tree:

n=q.size() is NOT enough because empty positions
also matter.

Use:
node + position

--------------------------------------------------

PROBLEMS DONE:

102 → Level Order
199 → Right Side View
637 → Average of Levels
515 → Largest Value in Each Row
1161 → Maximum Level Sum
513 → Bottom Left Value
103 → Zigzag Level Order

--------------------------------------------------

KEY THING TO REMEMBER:

Normal BFS:
queue + while

Level BFS:
queue + while + n=q.size() + for
*/
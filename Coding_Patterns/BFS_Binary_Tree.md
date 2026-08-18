/*
BFS — Binary Tree

Pattern:
- BFS = level-by-level traversal.
- Uses queue → FIFO.

Basic blueprint:

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


LEVEL-BY-LEVEL:

Use n=q.size() when the question needs
information for EACH LEVEL.

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

n = number of nodes in the current level.

Important:
- n is taken BEFORE adding children.
- Children added during the loop belong to the next level.


COMMON CONDITIONS:

Maximum:
mx=max(mx,p->val);

Sum:
sum=sum+p->val;

First node:
if(i==0)

Last node:
if(i==n-1)

Average:
sum/n


If every level needs a separate vector:

vector<int> temp;

process level → temp.push_back(p->val)

then:
ans.push_back(temp);


ZIGZAG:
- Normal BFS gives left → right.
- For alternate levels, reverse temp.


WHEN TO THINK BFS:

level
level order
each row
leftmost/rightmost of each level
sum/max/average per level
zigzag


KEY IDEA:

Normal BFS:
queue

Level BFS:
queue + n=q.size()


Problems done:
102 Level Order
199 Right Side View
637 Average of Levels
515 Largest Value in Each Row
1161 Maximum Level Sum
513 Bottom Left Value
103 Zigzag Level Order
*/
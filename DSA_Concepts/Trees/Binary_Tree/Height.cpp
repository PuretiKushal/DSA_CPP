/*
Topic: Height of a Binary Tree

Key Idea:
- The height of a tree is the longest path from the root to a leaf.
- For every node:
    height = 1 + max(left subtree height, right subtree height)
- An empty tree has height 0.
*/

#include<bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    Node* left;
    Node* right;

    Node(int x)
    {
        data=x;
        left=NULL;
        right=NULL;
    }
};

int height(Node* root)
{
    if(root==NULL)
    {
        return 0;
    }

    int left=height(root->left);
    int right=height(root->right);

    return 1+max(left,right);
}

int main()
{
    Node* root=new Node(1);
    root->left=new Node(2);
    root->right=new Node(3);
    root->left->left=new Node(4);
    root->left->right=new Node(5);

    cout<<height(root)<<endl;

    return 0;
}
/*
Topic: Binary Tree Traversals

Traversals:
- Preorder  -> Root -> Left -> Right
- Inorder   -> Left -> Root -> Right
- Postorder -> Left -> Right -> Root

Time Complexity: O(n)
(Every node is visited exactly once.)

Space Complexity: O(h)
(Recursion uses the call stack up to the height of the tree.)
*/

#include<bits/stdc++.h>
using namespace std;

struct Node
{
    int data;        // Stores the value of the node
    Node* left;      // Points to the left child
    Node* right;     // Points to the right child

    Node(int x)
    {
        data=x;      // Store the given value
        left=NULL;   // Initially, no left child
        right=NULL;  // Initially, no right child
    }
};

// Root -> Left -> Right
void preorder(Node* root)
{
    if(root==NULL)   // If there is no node, stop this recursive call
    {
        return;
    }

    cout<<root->data<<" ";   // Visit the root first
    preorder(root->left);    // Then traverse the left subtree
    preorder(root->right);   // Finally traverse the right subtree
}

// Left -> Root -> Right
void inorder(Node* root)
{
    if(root==NULL)   // If there is no node, stop this recursive call
    {
        return;
    }

    inorder(root->left);     // First traverse the left subtree
    cout<<root->data<<" ";   // Then visit the root
    inorder(root->right);    // Finally traverse the right subtree
}

// Left -> Right -> Root
void postorder(Node* root)
{
    if(root==NULL)   // If there is no node, stop this recursive call
    {
        return;
    }

    postorder(root->left);   // First traverse the left subtree
    postorder(root->right);  // Then traverse the right subtree
    cout<<root->data<<" ";   // Finally visit the root
}

int main()
{
    int n,i,x;
    Node* root=NULL;

    /*
            1
           / \
          2   3
         / \
        4   5

        This tree is created manually to understand traversal.
    */

    root=new Node(1);
    root->left=new Node(2);
    root->right=new Node(3);
    root->left->left=new Node(4);
    root->left->right=new Node(5);

    cout<<"Preorder: ";
    preorder(root);

    cout<<endl<<"Inorder: ";
    inorder(root);

    cout<<endl<<"Postorder: ";
    postorder(root);

    return 0;
}
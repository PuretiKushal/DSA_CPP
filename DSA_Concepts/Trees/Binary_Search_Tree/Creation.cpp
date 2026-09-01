#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;        // Stores the value of the node
    Node* left;      // Points to the left child
    Node* right;     // Points to the right child

    Node(int x)      // Constructor: initializes a new node
    {
        data=x;      // Store the given value
        left=NULL;   // Initially, no left child
        right=NULL;  // Initially, no right child
    }
};

Node* insert(Node* root,int x)
{
    if(root==NULL)   // Empty position found, so create the new node
    {
        return new Node(x);   // Return its address to the parent
    }

    if(x<root->data)         // Smaller values go to the left
    {
        root->left=insert(root->left,x);   // Insert into left subtree
    }
    else                     // Greater or equal values go to the right
    {
        root->right=insert(root->right,x); // Insert into right subtree
    }

    return root;             // Return the current root of this subtree
}

bool search(Node* root,int x)
{
    if(root==NULL)
    {
        return false;
    }

    if(root->data==x)
    {
        return true;
    }

    if(x<root->data)
    {
        return search(root->left,x);
    }

    return search(root->right,x);
}

int main()
{
    int n,x;                 // n = number of values, x = current value
    Node* root=NULL;         // Start with an empty BST

    cin>>n;                  // Read number of values

    for(int i=0;i<n;i++)     // Insert each value into the BST
    {
        cin>>x;              // Read the current value
        root=insert(root,x); // Insert it and keep the root pointer updated
    }

    cout << search(root,3) << endl;
    cout << search(root,10) << endl;

    cout << "Binary Search Tree created successfully." << endl; // Confirmation message
    return 0;
}
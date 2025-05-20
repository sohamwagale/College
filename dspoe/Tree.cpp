#include<iostream>
#include<string>
using namespace std;

/*
    20. Write a program to create binary tree and perform all traversing techniques. 

    21. Write a program to create BST and perform all traversing techniques. 
    
*/

class Node{
public:
    int data;
    Node* left;
    Node* right;

    Node(int val) {
        data = val;
        left = nullptr;
        right = nullptr;
    }
};

Node* createTree(){
    int data;

    cout<<"Enter node value : ";
    cin>> data;
    Node *root = new Node(data);

    char response;

    cout<<"\nDo you want to insert left child for "<<data<<" (y/n) : ";
    cin>>response;
    if(response == 'y') root->left = createTree();
    else root->left = nullptr;
    
    cout<<"\nDo you want to insert right child for "<<data<<" (y/n) : ";
    cin>>response;
    if(response == 'y') root->right = createTree();
    else root->right = nullptr;

    return root;    
}

Node *insertBST(Node *root,int data){
    if(root = nullptr) return new Node(data);

    if(data < root->data) root->left = insertBST(root->left,data);
    if(data > root->data) root->right = insertBST(root->right,data);

    return root;
}

Node* createBST(){
    Node *root = nullptr;
    int data;

    cout<<"Enter values ";
    while(cin>>data){
        root = insertBST(root,data);
    }

    return root;    
}

void preorder(Node* node){
    if (node == nullptr) return;
    cout<<node->data<<" ";
    preorder(node->left);
    preorder(node->right);
}

void inorder(Node* node){
    if (node == nullptr) return;
    inorder(node->left);
    cout<<node->data<<" ";
    inorder(node->right);
}

void postorder(Node* node){
    if (node == nullptr) return;
    postorder(node->left);
    postorder(node->right);
    cout<<node->data<<" ";
}

int main(){
    Node* root = createTree();
    cout<<"Preorder Traversal : ";
    preorder(root);
    return 0;
}
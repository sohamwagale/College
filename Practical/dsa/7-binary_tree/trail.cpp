#include<iostream>
using namespace std;

class Node {
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

Node* createNode(){
    int data;
    cout<<"Enter node value : ";
    cin>> data;

    Node *root = new Node(data);

    char response;

    cout<<"\nDo you want to insert left child for "<<data<<" (y/n) : ";
    cin>>response;
    if(response == 'y'){
        root->left = createNode();
    } else {
        root->left = nullptr;
    }

    cout<<"\nDo you want to insert right child for "<<data<<" (y/n) : ";
    cin>>response;
    if(response == 'y'){
        root->right = createNode();
    } else { 
        root->right = nullptr;
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
    Node* root = createNode();
    cout<<"Preorder Traversal : ";
    preorder(root);
    return 0;
}
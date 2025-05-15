#include<iostream>
#include "Node.cpp"
using namespace std;

void preorder(Node<int>* node){
    if (node == nullptr) return;
    cout<<node->data<<" ";
    preorder(node->left);
    preorder(node->right);
}

void inorder(Node<int>* node){
    if (node == nullptr) return;
    inorder(node->left);
    cout<<node->data<<" ";
    inorder(node->right);
}

void postorder(Node<int>* node){
    if (node == nullptr) return;
    postorder(node->left);
    postorder(node->right);
    cout<<node->data<<" ";

}

int main(){
    Node<int>* root = createNode<int>();
    cout<<"Preorder Traversal : ";
    preorder(root);
    return 0;
}
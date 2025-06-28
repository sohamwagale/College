#include<iostream>
#include<string>
#include"Node.cpp"
using namespace std;


template <typename T>
Node<T>* createNode(){
    int data;
    cout<<"Enter node value : ";
    cin>> data;

    Node<T> *root = new Node<T>(data);

    char response;

    cout<<"\nDo you want to insert left child for "<<data<<" (y/n) : ";
    cin>>response;
    if(response == 'y'){
        root->left = createNode<T>();
    } else {
        root->left = nullptr;
    }

    cout<<"\nDo you want to insert right child for "<<data<<" (y/n) : ";
    cin>>response;
    if(response == 'y'){
        root->right = createNode<T>();
    } else { 
        root->right = nullptr;
    }

    return root;    
}

template <typename T>
Node<T>* createTree() {
    Node<T>* root = new Node<T>(1);  // or T(1) if T is not int
    root->left = new Node<T>(2);
    root->right = new Node<T>(3);

    root->left->left = new Node<T>(4);
    root->left->right = new Node<T>(5);
    root->right->left = new Node<T>(6);
    root->right->right = new Node<T>(7);

    root->left->right->left = new Node<T>(8);
    root->right->right->left = new Node<T>(9);
    root->right->right->right = new Node<T>(10);

    return root;
}

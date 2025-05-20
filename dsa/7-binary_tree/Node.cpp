#include<iostream>
using namespace std;

template <typename T>
class Node {
public:
    T data;
    Node<T>* left;
    Node<T>* right;

    Node(T val) {
        data = val;
        left = nullptr;
        right = nullptr;
    }
};
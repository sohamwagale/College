#include<iostream>
using namespace std;

class Node{
public:
    int data;
    Node* next;

    Node(int data){
        this->data = data;
        this->next = nullptr;
    }

    Node(int data, Node* next){
        this->data = data;
        this->next = next;
    }
};

class Steck{
public:
    Node* top = nullptr;
    int size = 0;

    void push(int elem){
        Node* temp = new Node(elem);
        temp->next = top;
        top = temp;
        ++size;
    }

    int pop(){
        if(top==nullptr){
            cerr<<"Stack is empty"<<endl;
            return -1;
        }
        Node* temp = top;
        top = top->next;
        int elem = temp->data;
        delete temp;
        --size;
        return elem;
    }

    bool isEmpty(){
        if(top==nullptr){
            cerr<<"Stack is empty"<<endl;
            return true;
        }
        return false;
    }

    int topElement(){
        return top->data;
    }

    int totalSize(){
        return size;
    }

    void display(){
        Node* trav = top;
        while(trav != nullptr){
            cout<< trav->data <<" ";
            trav = trav->next;
        }
    }
};

int main(){
    Steck s1;
    s1.push(2);
    s1.push(3);
    s1.push(6);
    s1.push(4);
    cout<<endl<<"Topmost Element is : "<<s1.topElement()<<endl;
    cout<<endl<<"Popped Element is : "<<s1.pop()<<endl;
    cout<<endl<<"Total Size is :"<<s1.totalSize()<<endl;
    s1.display();
}
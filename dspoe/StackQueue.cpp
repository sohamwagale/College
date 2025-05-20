#include<iostream>
using namespace std;

class Node{
public:
    int data;
    Node *next;
    Node *prev;

    Node(int data){
        this->data = data;
        this->next = nullptr;
        this->prev = nullptr;
    }

    Node(int data,Node *next){
        this->data = data;
        this->next = next;
        this->prev = nullptr;
    }
};

class StackLL{
public:
    Node* top = nullptr;
    StackLL(int arr[],int size){
        for(int i=0;i<size;i++){
            top = new Node(arr[i],top);
        }
    }

    void push(int val){
        top = new Node(val,top);
    }

    int pop(){
        Node *temp = top;
        top = top->next;
        int ret = temp->data;
        delete temp;
        return ret;
    }

    void display(){
        Node *trav = top;
        while(trav!=nullptr){
            cout<<trav->data<<" ";
            trav = trav->next;
        }
    }
};


class Stack{
    void create(int arr[]){
        
    }

    void push(){

    }

    void pop(){

    }

    int top(){

    }

    void display(){

    }
};

int main(){
    int arr[] = {4,5,6,7,8,9};
    StackLL st(arr,6);
    st.display();
    cout<<endl<<st.top->data;
}
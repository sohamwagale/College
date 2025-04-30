#include<bits/stdc++.h>
using namespace std;

template<typename T>
class Node{
public:
    T data;
    Node<T>* next;

    Node(T data){
        this->data = data;
        this->next = nullptr;
    }

    Node(T data, Node<T>* next){
        this->data = data;
        this->next = next;
    }

};

template<typename T>
class Que{
public:
    int size = 0;
    Node<T>* start = nullptr;
    Node<T>* end = nullptr;

    void push(T elem){
        Node<T>* temp = new Node<T>(elem);
        if(start == nullptr){
            start = end = temp;
        }
        else{
            end->next = temp;
            end =temp;
        }
        ++size;
    }

    T pop(){
        if(start == nullptr) 
            throw runtime_error("Queue is Empty");

        Node<T>* temp = start; 
        start = start->next;
        if(start == nullptr){
            end = nullptr;//end->next alwys pnts to a null ptr but not end;
        }

        T elem = temp->data;
        delete temp;
        --size;
        return elem;
    }

    int totalSize(){
        return size;
    }

    T top(){
        if(start == nullptr) 
            throw runtime_error("Queue is Empty");
        return start->data;
    }

    void display(){
        Node<T>* trav = start;
        while(trav != nullptr){
            cout<<trav->data<<" ";
            trav = trav->next; 
        }
    }

};

int main(){
    Que<int> q1;
    q1.push(2);
    q1.push(3);
    q1.push(6);
    q1.push(4);

    cout << "Starting Element is: " << q1.top() << endl;
    cout << "Popped Element is: " << q1.pop() << endl;
    cout << "Total Size is: " << q1.totalSize() << endl;

    cout << "Stack Elements: ";
    q1.display();

    return 0;
}
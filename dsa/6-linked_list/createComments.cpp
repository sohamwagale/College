#include<bits/stdc++.h>
using namespace std;

class Node{

public:
    int data;
    Node* next;

public:
    Node(int data,Node* ptr){
        this->data = data;
        this->next = ptr;
    }

public:
    Node(int data){
        this->data = data;
        this->next = nullptr;
    }
};

Node* create(vector<int> &arr){
    Node* head = new Node(arr[0]);
    Node* mover = head;

    for(int i=1;i<arr.size();i++){
        Node* temp = new Node(arr[i]);
//Adhichyacha haath utchlun next la lavtoy and next kada jatoy
        mover->next = temp;
//The next 3 statements have same meaning
//        mover = mover->next;
//          (*mover).next = temp;
        mover = temp;
    }
    cout<<"The linked list is created... The head is  : "<<head->data<<endl;
    return head;
}

void traverse(Node* head){
    Node* temp = head;
    cout<<"The elements of the linked list are : ";
    while(temp!=nullptr){
        cout<<temp->data<<" ";
        temp = temp->next;
    }
    cout<<endl;
}

void count(Node* head){
    Node* trav = head;
    int cnt =0;
    while(trav){
        cnt++;
        trav = trav->next;
    }
    cout<<"Count is : "<<cnt<<endl;
}

bool find(Node* head,int elem){
    Node* trav = head;
    Node* elemAddress;
    while(trav){
        if(trav->data == elem){
            cout<<"Element "<<elem<<" is present"<<endl;
            return true;
        } 
        trav = trav->next;
    }
    cout<<"Element "<<elem<<" is NOT present"<<endl;
    return false;
}

int main(){
    vector<int> arr = {4,5,6,7,8,9};

    //Creating a linked list
    Node* header = create(arr);

    //Outputting the data of the first element
    //cout<< header->data<<endl;

    //traversing and printing all the elems of the linked list
    traverse(header);

    //counts the elems by traversing and keeping the counters
    count(header);

    //finds if a particular elm is present or not
    find(header,2);
    find(header,4);

}
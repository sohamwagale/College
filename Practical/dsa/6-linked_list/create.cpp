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
        mover->next = temp;
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

Node* insHead(Node* head,int elem){
    Node* temp = new Node(elem);
    temp->next = head;
    head = temp;
    return head;
}

Node* insb4Val(Node* head,int elem,int val){
    if(head == nullptr) return new Node(elem);
    if(head->data == val) return new Node(elem,head);
    Node* trav = head;

    while(trav->next->data != val)
        trav = trav->next;

    if (trav->next == nullptr)
        return head;

    Node* nn = new Node(elem,trav->next);
    trav->next = nn;
    return head;
}

Node* insPos(Node* head, int elem, int pos){
    if(head == nullptr) 
        if(pos == 1)
            return new Node(elem); 
        else
            return head;

    if(pos == 1)
        return new Node(elem,head);

    int size = 0;
    Node* trav = head;
    while(trav!=nullptr){
        size++;
        if(size==pos){
            Node* nn = new Node(elem,trav->next);
            trav->next = nn; 
            break;
        }
        trav = trav->next;
    }
    return head;
}

Node* insTail(Node* head,int elem){
    Node* trav = head;
    while(trav->next!=nullptr){
        trav = trav->next;
    }
    trav->next = new Node(elem);
    return head;
}

Node* delHead(Node* head){
    if(head==nullptr) return head;
    Node* temp = head;
    head = head->next;
    delete temp;
    return head;
}

Node* delTail(Node* head){
    if(head->next == nullptr || head == nullptr){
        return nullptr;
    }
    Node* trav =head;
    while(trav->next->next!=nullptr){
        trav = trav->next;
    }
    delete trav->next;
    trav->next = nullptr;
    return head;
}

Node* delPos(Node* head, int pos){
    if(pos == 1){
        Node* temp = head;
        head = head->next;
        delete temp;
        return head;
    }
    Node* prev = nullptr;
    Node* trav =head;
    int currPos = 0;
    while(trav!=nullptr){
        currPos++;
        if(currPos==pos){
            prev->next = trav->next;
            delete trav;
            break;
        }
        prev = trav;
        trav = trav->next;
    }
    return head;
}

Node* delEl(Node* head, int elem){
    if(head->data == elem){
        Node* temp = head;
        head = head->next;
        delete temp;
        return head;
    }
    Node* prev = nullptr;
    Node* trav =head;
    while(trav!=nullptr){
        if(trav->data == elem){
            prev->next = trav->next;
            delete trav;
            break;
        }
        prev = trav;
        trav = trav->next;
    }
    return head;
}

Node* delElem(Node* head, int val){
    if(head==nullptr) return head;
    if(head->data == val){
        Node* temp = head;
        head = head->next;
        delete temp;
        return head;
    }
    Node* trav =head;
    while(trav->next!=nullptr){
        if(trav->next->data == val){
            Node* temp = trav->next;
            trav->next = trav->next->next;
            delete temp;
            break;
        }
        trav = trav->next;
    }
    return head;
}

int main(){
    vector<int> arr = {4,5,6,7,8,9};

    Node* header = create(arr);
    traverse(header);
    count(header);
    find(header,2);
    find(header,4);

}
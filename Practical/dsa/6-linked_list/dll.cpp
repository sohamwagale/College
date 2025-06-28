#include<iostream>
#include<vector>
using namespace std;

class Node{
public:
    int data;
    Node* next;
    Node* back;

    Node(int data,Node* next, Node* back){
        this->data = data;
        this->next = next;
        this->back = back;
    }
    Node(int data){
        this->data = data;
        this->next = nullptr;
        this->back = nullptr;
    }
};

Node* arr2dll(vector<int> &arr){
    Node* head = new Node(arr[0]);
    Node* prev = head;
    for(int i =1;i<5;i++){
        Node* nn = new Node(arr[i],nullptr,prev);
        prev->next = nn;
        prev = prev->next;
    }
    return head;
}

void printLL(Node* head){
    Node* trav = head;
    while(trav!=nullptr){
        cout<<trav->data<<" ";
        trav = trav->next;
    }
}

Node* insHead(Node* head,int data){
    head->back = new Node(data,head,nullptr);
    return head->back;
}

Node* delHead(Node* head){
    if(head == nullptr || head->next == nullptr){
        return nullptr;
    }
    Node* temp = head;
    head= head->next;
    head->back = nullptr;
    temp->next = nullptr;
    delete temp;
    return head;
}

Node* insTail(Node* head,int data){
    if(head == nullptr){
        return new Node(data,head,nullptr);
    }
    Node* trav = head;
    while(trav->next!=nullptr){
        trav = trav->next;
    }
    trav->next = new Node(data,nullptr,trav);
    return head;
}

Node* delTail(Node* head){
    if(head == nullptr || head->next == nullptr){
        return nullptr;
    }
    Node* trav = head;
    while(trav->next!= nullptr){
        trav = trav->next;
    }
    Node* ls = trav->back;
    trav->back = nullptr;
    ls->next = nullptr;
    delete trav;
    return head;
}

Node* insB4(Node* head,int data,int pos){
    if(pos == 1){
        return insHead(head,data);
    }
    int size=0;
    Node* trav = head;
    while(trav!=nullptr){
        size++;
        if(size == pos) break;
        trav=trav->next;
    }
    Node* prev = trav->back;
    Node* nn =new Node(data,trav,prev);
    prev->next = nn;
    trav->back = nn;
    return head;
}

Node* insAf(Node* head, int data, int pos){
    int currPos = 1;
    Node* trav = head;

    while (trav && currPos<pos){
        currPos++;
        trav = trav->next;
    }

    if(!trav->next){
        Node* nn = new Node(data,nullptr,trav);
        trav->next = nn;
        return head;
    }

    Node* front = trav->next;
    Node* nn = new Node(data,front,trav);
    front->back = trav->next = nn;
    return head;   
}

Node* delpos(Node* head, int pos){
    if (!head) return head;
    if(pos == 1){
        return delHead(head);
    }
    Node* trav = head;
    int currPos =1;
    while(trav!=nullptr){
        currPos++;
        trav = trav->next;
        if(currPos == pos) break;
    }
    Node* prev = trav->back;
    Node* front = trav->next;
    if(front==nullptr){
        return delTail(head);
    }
    prev->next = front;
    front->back = prev;
    trav->next = trav->back = nullptr;
    delete trav;
    return head;
}

Node* delB4(Node* head, int pos){
    if (!head || pos < 2) return head;
    if(pos == 2){
        return delHead(head);
    }
    Node* trav = head;
    int currPos =1;
    while(trav!=nullptr){
        currPos++;
        trav = trav->next;
        if(currPos == pos-1) break;
    }
    Node* prev = trav->back;
    Node* front = trav->next;
    prev->next = front;
    front->back = prev;
    trav->next = trav->back = nullptr;
    delete trav;
    return head;
}

Node* delAf(Node* head, int pos){
    int currPos = 1;
    Node* trav = head;

    while (trav->next->next && currPos<pos){
        currPos++;
        trav = trav->next;
    }

    Node* temp = trav->next;
    Node* front = temp->next;
    front->back = trav->next = temp;
    temp->next = temp->back = nullptr;
    delete temp; 
}

Node* insNodeB4(Node* head,Node* node,int pos){
    if(!head) return node;
    if(pos == 1){
        node->back = nullptr;
        node->next =head;
        head->back = node;
        return node;
    }    
    Node* trav = head;
    int currPos = 1;
    while(trav && currPos < pos){
        currPos++;
        trav = trav->next;
    }

    if(!trav) return head;

    Node* prev = trav->back;
    
    if(prev) prev->next = node; 
    trav->back = node;

    node->next = trav;
    node->back = prev;
    return head;

}

Node* insNodeAf(Node* head,Node* node,int pos){

}

void delNode(Node* node){
    Node* front = node->next;
    Node* prev = node->back;

    if(!front){
        prev->next = nullptr;
        node->back=nullptr;
        delete node;
        return;
    }

    front->back = prev;
    prev->next= front;

    node->back = node->next = nullptr;
    delete node;
    return;
}



int main(){
    vector<int> arr = {20,30,50,80,90};
    Node* head = arr2dll(arr);
    head = insNodeB4(head,new Node(12),3);
    printLL(head);
}
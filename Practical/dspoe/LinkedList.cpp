#include<iostream>
#include<vector>
using namespace std;

/*
    15. Write a program to create a singly linked list. Perform the following operations on created linked list. 
        d) Insertion at the any position 
        e) Deletion at the any position 
        f) Display linked list 

    18. Write a program to create a doubly linked list. Perform the following operations on created linked list. 
        a) Insertion at the any position 
        b) Deletion at the position 
        c) Display linked list 

    19. Write a program to create a circular linked list and display it. 

*/

class Node{
public:
    int data;
    Node *next;
    Node *back;

    Node(int data){
        this->data = data;
        this->next = nullptr;
        this->back = nullptr;
    }

    Node(int data,Node *next){
        this->data = data;
        this->next = next;
        this->back = nullptr;
    }

    Node(int data,Node* next, Node* back){
        this->data = data;
        this->next = next;
        this->back = back;
    }
};

class SinglyLinkedList{
public:
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

};

class DoublyLinkedList{
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
};

class CircularLinkedList{
public:
    Node *create(vector<int> arr){
        if(arr.empty()) return nullptr;
        Node *head = new Node(arr[0]);
        Node *trav = head;
        for(int i=1;i<arr.size();i++){
            trav->next = new Node(arr[i]);
            trav = trav->next;
        }
        trav->next = head;
        return head;
    }

    void display(Node *head){
        if(!head) return;
        Node *trav = head;
        do{
            cout<<trav->data<<" ";
            trav = trav->next;
        }while(trav!=head);
    }
};

int main(){
    vector<int> arr = {4,5,6,7,8,9};

    SinglyLinkedList ll;
    Node* header =  ll.create(arr);
    ll.traverse(header);
    ll.count(header);
    ll.find(header,2);
    ll.find(header,4);
    cout<<endl;

    CircularLinkedList cll;
    cll.display(cll.create(arr));
}
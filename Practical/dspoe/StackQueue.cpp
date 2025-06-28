#include<iostream>
#include<bits/stdc++.h>
using namespace std;

/*
    9. Write a program to create a stack using array. Take input an array from the user. Perform all the stack operations. 
    
    10. Write a program to create a stack using linked list. Take input an array from the user. Perform all the stack operations. 
    
    11. Write a program to create a queue using array. Take input an array from the user. Perform all the queue operations. 
    
    12. Write a program to create a queue using linked list. Take input an array from the user. Perform all the queue operations. 

    28. Write a program to create priority queue and display its data. 

    29. Write a program to create descending priority queue and display its data. 

    30. Write a program to convert infix expression into postfix expression. 

    31.  Write a program to convert infix expression into prefix expression. 

*/

class Node{
public:
    int data;
    Node *next;

    Node(int data){
        this->data = data;
        this->next = nullptr;
    }

    Node(int data,Node *next){
        this->data = data;
        this->next = next;
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
public:
    int top = -1;
    int size;
    int arr[];

    Stack(int sz){
        arr[size];
        size = sz;
    }

    void push(int data){
        if(top==size) return;
        arr[++top] = data;
    }

    int pop(){
        return arr[top--];
    }

    void display(){
        for(int i=0;i<=top;i++){
            cout<<arr[i]<<" ";
        }
    }
};

class Queue{
private: 
    int rear,front,cap;
    int size;
    int *arr;
public:
    Queue(int sz){
        arr = new int[sz];
        front = 0;
        rear = -1;
        cap = sz;
        size = sz;
    }

    void nq(int data){
        if(cap==size){
            cout<<"Full";
            return;
        }
        arr[++rear] = data;
        size++;
    }

    int dq(){
        if(size==0){
            cout<<"Empty";
            return;
        }
        size--;
        return arr[front++];
    }

};

class QueueLL{
public:
    int size = 0;
    Node* start = nullptr;
    Node* end = nullptr;

    void push(int elem){
        Node* temp = new Node(elem);
        if(start == nullptr){
            start = end = temp;
        }
        else{
            end->next = temp;
            end =temp;
        }
        ++size;
    }

    int pop(){
        if(start == nullptr) 
            throw runtime_error("Queue is Empty");

        Node* temp = start; 
        start = start->next;
        if(start == nullptr){
            end = nullptr;//end->next alwys pnts to a null ptr but not end;
        }

        int elem = temp->data;
        delete temp;
        --size;
        return elem;
    }

    int totalSize(){
        return size;
    }

    int top(){
        if(start == nullptr) 
            throw runtime_error("Queue is Empty");
        return start->data;
    }

    void display(){
        Node* trav = start;
        while(trav != nullptr){
            cout<<trav->data<<" ";
            trav = trav->next; 
        }
    }

};

class Conversion {
private:
    // Helper: get operator precedence
    static int priority(char op) {
        if (op == '^')              return 3;
        if (op == '*' || op == '/') return 2;
        if (op == '+' || op == '-') return 1;
        return -1;
    }

public:
    // Convert infix → postfix
    static string infixToPostfix(const string& str) {
        stack<char> st;
        string ans;
        for (char ch : str) {
            if (isalnum(ch)) {
                ans += ch;
            } else if (ch == '(') {
                st.push(ch);
            } else if (ch == ')') {
                while (!st.empty() && st.top() != '(') {
                    ans += st.top();
                    st.pop();
                }
                if (!st.empty()) st.pop();  // pop '('
            } else { // operator
                if (ch == '^') {
                    while (!st.empty() && priority(ch) < priority(st.top())) {//equal wali asli tar chatay.... Jast priority ahe more samjukdar
                        ans += st.top();
                        st.pop();
                    }
                } else {
                    while (!st.empty() && priority(ch) <= priority(st.top())) {//equal wale pan chalat nahit... less priority more baad or egoistic
                        ans += st.top();
                        st.pop();
                    }
                }
                st.push(ch);
            }
        }
        while (!st.empty()) {
            ans += st.top();
            st.pop();
        }
        return ans;
    }

    // Convert infix → prefix
    static string infixToPrefix(string str) {
        // 1) reverse, 2) swap ()s
        reverse(str.begin(), str.end());
        for (char &ch : str) {
            if      (ch == '(') ch = ')';
            else if (ch == ')') ch = '(';
        }

        // 3) get postfix of that
        string ans;
        stack<char> st;
        for (char ch : str) {
            if (isalnum(ch)) {
                ans += ch;
            } else if (ch == '(') {
                st.push(ch);
            } else if (ch == ')') {
                while (!st.empty() && st.top() != '(') {
                    ans += st.top();
                    st.pop();
                }
                if (!st.empty()) st.pop();
            } else { // operator
                if (ch == '^') {///just reverse madhe ^ jara jast greedy hotay
                    while (!st.empty() && priority(ch) <= priority(st.top())) {
                        ans += st.top();
                        st.pop();
                    }
                } else {
                    while (!st.empty() && priority(ch) < priority(st.top())) {
                        ans += st.top();
                        st.pop();
                    }
                }
                st.push(ch);
            }
        }
        while (!st.empty()) {
            ans += st.top();
            st.pop();
        }

        // 4) reverse result to get prefix
        reverse(ans.begin(), ans.end());
        return ans;
    }
};

class Deque{
private:
    int* arr;
    int front, rear, capacity;

public:
    Deque(int cap) {
        capacity = cap;
        arr = new int[capacity];
        front = -1;
        rear = -1;
    }

    bool isFull() {
        return (rear == capacity - 1 && front == 0) || (rear - front + 1 == capacity);
    }

    bool isEmpty() {
        return front == -1;
    }

    void insertFront(int x) {
        if (isFull()) {
            cout << "Deque is full\n";
            return;
        }

        if (isEmpty()) {
            front = rear = 0;
        } else if (front > 0) {
            front--;
        } else {
            cout << "Cannot insert at front\n";
            return;
        }

        arr[front] = x;
    }

    void insertRear(int x) {
        if (isFull()) {
            cout << "Deque is full\n";
            return;
        }

        if (isEmpty()) {
            front = rear = 0;
        } else if (rear < capacity - 1) {
            rear++;
        } else {
            cout << "Cannot insert at rear\n";
            return;
        }

        arr[rear] = x;
    }

    void deleteFront() {
        if (isEmpty()) {
            cout << "Deque is empty\n";
            return;
        }

        if (front == rear) {
            front = rear = -1;
        } else {
            front++;
        }
    }

    void deleteRear() {
        if (isEmpty()) {
            cout << "Deque is empty\n";
            return;
        }

        if (front == rear) {
            front = rear = -1;
        } else {
            rear--;
        }
    }

    void display() {
        if (isEmpty()) {
            cout << "Deque is empty\n";
            return;
        }

        cout << "Deque elements: ";
        for (int i = front; i <= rear; i++) {
            cout << arr[i] << " ";
        }
        cout << "\n";
    }
};

//TO DO YET
class PriorityQueue{
private:
    int *queue;
    int size;
    int capacity;

public:
    PriorityQueue(int capacity) {
        this->capacity = capacity;
        queue = new int[capacity];
        size = 0;
    }

    // Insert while keeping array sorted (ascending order)
    void insert(int value) {
        if (size == capacity) {
            cout<<"Full";
            return;
        }

        int i = size - 1;
        // Shift elements greater than value to the right
        while (i >= 0 && queue[i] > value) {
            queue[i + 1] = queue[i];
            i--;
        }
        queue[i + 1] = value;
        size++;
    }

    // Return element with highest priority (smallest value)
    int peek() {
        if (isEmpty()) {
            throw runtime_error("Queue is empty.");
        }
        return queue[0];
    }

    // Remove and return highest priority element
    int poll() {
        if (isEmpty()) {
            throw runtime_error("Queue is empty.");
        }
        int top = queue[0];
        // Shift all elements to the left
        for (int i = 1; i < size; i++) {
            queue[i - 1] = queue[i];
        }
        size--;
        return top;
    }

    bool isEmpty() {
        return size == 0;
    }

    void display() {
        if (isEmpty()) {
            cout<<"Queue is empty.";
            return;
        }
        cout<<"Priority Queue: "<<endl;
        for (int i = 0; i < size; i++) {
            cout<< queue[i] << " ";
        }
        cout<<endl;
    }
};

class DescendingPriorityQueue{
private:
    int *queue;
    int size;
    int capacity;

public:
    DescendingPriorityQueue(int capacity){
        this->capacity = capacity;
        queue = new int[capacity];
        size = 0;
    }

    // Insert while keeping array sorted (ascending order)
    void insert(int value) {
        if (size == capacity) {
            cout << "Full";
            return;
        }

        int i = size - 1;
        // Shift elements smaller than value to the right
        while (i >= 0 && queue[i] < value) {
            queue[i + 1] = queue[i];
            i--;
        }
        queue[i + 1] = value;
        size++;
    }


    // Return element with highest priority (smallest value)
    int peek() {
        if (isEmpty()) {
            throw runtime_error("Queue is empty.");
        }
        return queue[0];
    }

    // Remove and return highest priority element
    int poll() {
        if (isEmpty()) {
            throw runtime_error("Queue is empty.");
        }
        int top = queue[0];
        // Shift all elements to the left
        for (int i = 1; i < size; i++) {
            queue[i - 1] = queue[i];
        }
        size--;
        return top;
    }

    bool isEmpty() {
        return size == 0;
    }

    void display() {
        if (isEmpty()) {
            cout<<"Queue is empty.";
            return;
        }
        cout<<"Priority Queue: "<<endl;
        for (int i = 0; i < size; i++) {
            cout<< queue[i] << " ";
        }
        cout<<endl;
    }
};

int main(){
    int arr[] = {4,5,6,7,8,9};
    //StackLL st2(arr,6);
    //st2.display();
    //cout<<endl<<st2.top->data;

    Stack st(5);
    st.push(6);
    st.push(7);
    st.push(8);
    st.display();

    PriorityQueue pq(7);
    pq.insert(30);
    pq.insert(10);
    pq.insert(20);
    pq.display(); // 10 20 30
    cout<<"Peek: " << pq.peek(); // 10
    cout<<"Poll: " << pq.poll(); // 10
    pq.display(); // 20 30

    string expr = "(a+b)*c";
    cout << "Postfix: " << Conversion::infixToPostfix(expr) << endl;
    cout << "Prefix: " << Conversion::infixToPrefix(expr) << endl;
}

//jyachi priority kami typ jast greedy and baher kadhnara

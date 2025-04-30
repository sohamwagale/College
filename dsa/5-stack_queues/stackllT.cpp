#include <iostream>
using namespace std;

template <typename T>
class Node {
public:
    T data;
    Node<T>* next;  // Correct template usage

    Node(T data) {
        this->data = data;
        this->next = nullptr;
    }

    Node(T data, Node<T>* next) {
        this->data = data;
        this->next = next;
    }
};

template <typename T>
class Steck {
public:
    Node<T>* top = nullptr;  // Correct template usage
    int size = 0;  // Use int instead of T for size

    void push(T elem) {
        Node<T>* temp = new Node<T>(elem);
        temp->next = top;
        top = temp;
        ++size;
    }

    T pop() {
        if (top == nullptr) {
            throw runtime_error("Stack is empty");  // Better error handling
        }
        Node<T>* temp = top;
        top = top->next;
        T elem = temp->data;
        delete temp;
        --size;
        return elem;
    }

    bool isEmpty() {
        return top == nullptr;
    }

    T topElement() {
        if (top == nullptr) {
            throw runtime_error("Stack is empty");  // Prevent access to nullptr
        }
        return top->data;
    }

    int totalSize() {
        return size;
    }

    void display() {
        Node<T>* trav = top;
        while (trav != nullptr) {
            cout << trav->data << " ";
            trav = trav->next;
        }
        cout << endl;
    }
};

int main() {
    Steck<int> s1;
    s1.push(2);
    s1.push(3);
    s1.push(6);
    s1.push(4);

    cout << "Topmost Element is: " << s1.topElement() << endl;
    cout << "Popped Element is: " << s1.pop() << endl;
    cout << "Total Size is: " << s1.totalSize() << endl;

    cout << "Stack Elements: ";
    s1.display();

    return 0;
}
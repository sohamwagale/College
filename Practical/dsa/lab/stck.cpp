#include <iostream>
using namespace std;

class Stack {
    int size;
    int top;
    int *stk;

public:
    Stack(int size) {
        this->size = size;
        stk = new int[size];
        top = -1;
    }

    ~Stack() {
        delete[] stk;
    }

    void push(int elem) {
        if (top == size - 1) {
            cout << "The Stack is Full!!" << endl;
        } else {
            stk[++top] = elem;
        }
    }

    int pop() {
        if (top != -1) {
            return stk[top--];
        } else {
            cout << "Error...Stack is Empty" << endl;
            return -1;
        }
    }

    bool isEmpty() {
        return (top == -1);
    }

    bool isFull() {
        return (top == size - 1);
    }

    int topElement() {
        if (top != -1) {
            return stk[top];
        } else {
            cout << "Stack is empty" << endl;
            return -1;
        }
    }

    void display_all() {
        for (int i = top; i >= 0; i--) {
            cout << stk[i] << " ";
        }
        cout << endl;
    }
};

int main() {
    int size;
    cout << "Enter Size of the Stack: ";
    cin >> size;
    Stack stck(size);

    while (true) {
        cout << "\nChoose an operation:" << endl;
        cout << "1. Push" << endl;
        cout << "2. Pop" << endl;
        cout << "3. Display" << endl;
        cout << "4. Top" << endl;
        cout << "5. Is Full" << endl;
        cout << "6. Is Empty" << endl;
        cout << "7. Exit" << endl;
      
        cout << "Enter your choice: ";
        
        int choice;
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter value to push: ";
                int val;
                cin >> val;
                stck.push(val);
                break;
            case 2:
                stck.pop();
                break;
            case 3:
                stck.display_all();
                break;
            case 4: 
                cout << "The topmost Element is :" << stck.topElement();
                break;
            case 5:
                cout<< stck.isFull();
                break;
            case 6:
                cout<< stck.isEmpty();
                break;
            case 7:
                cout << "Exiting..." << endl;
                return 0;
            default:
                cout << "Invalid choice. Please try again." << endl;
        }
    }
}

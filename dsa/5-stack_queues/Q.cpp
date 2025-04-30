#include <iostream>
using namespace std;

class Q {
private:
    int *queue;
    int front, rear, size, capacity;

public:
    Q(int capacity) {
        this->capacity = capacity;
        queue = new int[capacity];
        front = 0;
        rear = -1;
        size = 0;
    }

    bool isFull() {
        return size == capacity;
    }

    bool isEmpty() {
        return size == 0;
    }

    void enq(int item) {
        if (isFull()) {
            cout << "Queue is full" << endl;
            return;
        }
        rear = (rear + 1) % capacity;
        queue[rear] = item;
        size++;
    }

    int deq() {
        if (isEmpty()) {
            cout << "Queue is empty" << endl;
            return -1;
        }
        int item = queue[front];
        queue[front] = 0;
        front = (front + 1) % capacity;
        size--;
        return item;
    }

    int frontElem() {
        if (isEmpty()) {
            cout << "Queue is empty" << endl;
            return -1;
        }
        return queue[front];
    }

    void display() {
        if (isEmpty()) {
            cout << "Queue is empty" << endl;
            return;
        }
        int pos = front;
        for (int i = 0; i < size; i++) {
            cout << queue[pos] << " ";
            pos = (pos + 1) % capacity;
        }
        cout << endl;
    }
};

int main() {
    Q q(5);

    while (true) {
        cout << "\nChoose an operation:" << endl;
        cout << "1. Enqueue" << endl;
        cout << "2. Dequeue" << endl;
        cout << "3. Display" << endl;
        cout << "4. Front" << endl;
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
                q.enq(val);
                break;
            case 2:
                q.deq();
                break;
            case 3:
                q.display();
                break;
            case 4: 
                cout << "The Front Element is :" << q.frontElem();
                break;
            case 5:
                cout<< q.isFull();
                break;
            case 6:
                cout<< q.isEmpty();
                break;
            case 7:
                cout << "Exiting..." << endl;
                return 0;
            default:
                cout << "Invalid choice. Please try again." << endl;
        }
    }
}

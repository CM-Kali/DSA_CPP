#include <iostream>
using namespace std;

class SimpleQueue {
private:
    int arr[100];
    int front, rear;
    
public:
    SimpleQueue() {
        front = -1;
        rear = -1;
    }
    
    // Check if queue is empty
    bool isEmpty() {
        return front == -1;
    }
    
    // Check if queue is full
    bool isFull() {
        return rear == 99;
    }
    
    // Add element to queue
    void enqueue(int value) {
        if (isFull()) {
            cout << "Queue Overflow! Cannot enqueue " << value << endl;
            return;
        }
        
        if (isEmpty()) {
            front = 0;
        }
        rear++;
        arr[rear] = value;
        cout << "Enqueued: " << value << endl;
    }
    
    // Remove element from queue
    int dequeue() {
        if (isEmpty()) {
            cout << "Queue Underflow! Cannot dequeue" << endl;
            return -1;
        }
        
        int value = arr[front];
        
        // If only one element was present
        if (front == rear) {
            front = -1;
            rear = -1;
        } else {
            front++;
        }
        
        cout << "Dequeued: " << value << endl;
        return value;
    }
    
    // Get front element
    int getFront() {
        if (isEmpty()) {
            cout << "Queue is empty!" << endl;
            return -1;
        }
        return arr[front];
    }
    
    // Get rear element
    int getRear() {
        if (isEmpty()) {
            cout << "Queue is empty!" << endl;
            return -1;
        }
        return arr[rear];
    }
    
    // Display queue
    void display() {
        if (isEmpty()) {
            cout << "Queue is empty!" << endl;
            return;
        }
        
        cout << "Queue: ";
        for (int i = front; i <= rear; i++) {
            cout << arr[i] << " ";
        }
        cout << endl;
    }
};

int main() {
    SimpleQueue q;
    int choice, value;
    
    cout << "=== SIMPLE QUEUE OPERATIONS ===" << endl;
    
    do {
        cout << "\n1. Enqueue\n2. Dequeue\n3. Front\n4. Rear\n5. Display\n6. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;
        
        switch(choice) {
            case 1:
                cout << "Enter value to enqueue: ";
                cin >> value;
                q.enqueue(value);
                break;
                
            case 2:
                q.dequeue();
                break;
                
            case 3:
                cout << "Front element: " << q.getFront() << endl;
                break;
                
            case 4:
                cout << "Rear element: " << q.getRear() << endl;
                break;
                
            case 5:
                q.display();
                break;
                
            case 6:
                cout << "Exiting program. Goodbye!" << endl;
                break;
                
            default:
                cout << "Invalid choice! Please try again." << endl;
        }
    } while(choice != 6);
    
    return 0;
}

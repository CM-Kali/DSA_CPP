#include <iostream>
using namespace std;

class Deque {
private:
    int arr[100];
    int front, rear;
    
public:
    Deque() {
        front = -1;
        rear = -1;
    }
    
    // Check if deque is empty
    bool isEmpty() {
        return front == -1;
    }
    
    // Check if deque is full
    bool isFull() {
        return (front == 0 && rear == 99) || (front == rear + 1);
    }
    
    // Add to front
    void addFront(int value) {
        if (isFull()) {
            cout << "Deque Overflow! Cannot add " << value << " at front" << endl;
            return;
        }
        
        if (isEmpty()) {
            front = 0;
            rear = 0;
        } else if (front == 0) {
            front = 99;
        } else {
            front--;
        }
        
        arr[front] = value;
        cout << "Added to front: " << value << endl;
    }
    
    // Add to rear
    void addRear(int value) {
        if (isFull()) {
            cout << "Deque Overflow! Cannot add " << value << " at rear" << endl;
            return;
        }
        
        if (isEmpty()) {
            front = 0;
            rear = 0;
        } else if (rear == 99) {
            rear = 0;
        } else {
            rear++;
        }
        
        arr[rear] = value;
        cout << "Added to rear: " << value << endl;
    }
    
    // Remove from front
    int deleteFront() {
        if (isEmpty()) {
            cout << "Deque Underflow! Cannot delete from front" << endl;
            return -1;
        }
        
        int value = arr[front];
        
        if (front == rear) {
            front = -1;
            rear = -1;
        } else if (front == 99) {
            front = 0;
        } else {
            front++;
        }
        
        cout << "Deleted from front: " << value << endl;
        return value;
    }
    
    // Remove from rear
    int deleteRear() {
        if (isEmpty()) {
            cout << "Deque Underflow! Cannot delete from rear" << endl;
            return -1;
        }
        
        int value = arr[rear];
        
        if (front == rear) {
            front = -1;
            rear = -1;
        } else if (rear == 0) {
            rear = 99;
        } else {
            rear--;
        }
        
        cout << "Deleted from rear: " << value << endl;
        return value;
    }
    
    // Get front element
    int getFront() {
        if (isEmpty()) {
            cout << "Deque is empty!" << endl;
            return -1;
        }
        return arr[front];
    }
    
    // Get rear element
    int getRear() {
        if (isEmpty()) {
            cout << "Deque is empty!" << endl;
            return -1;
        }
        return arr[rear];
    }
    
    // Display deque
    void display() {
        if (isEmpty()) {
            cout << "Deque is empty!" << endl;
            return;
        }
        
        cout << "Deque: ";
        int i = front;
        while (true) {
            cout << arr[i] << " ";
            if (i == rear) break;
            
            if (i == 99) i = 0;
            else i++;
        }
        cout << endl;
    }
};

int main() {
    Deque dq;
    int choice, value;
    
    cout << "=== DOUBLE ENDED QUEUE OPERATIONS ===" << endl;
    
    do {
        cout << "\n1. Add to Front\n2. Add to Rear\n3. Delete from Front\n";
        cout << "4. Delete from Rear\n5. Get Front\n6. Get Rear\n7. Display\n8. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;
        
        switch(choice) {
            case 1:
                cout << "Enter value to add at front: ";
                cin >> value;
                dq.addFront(value);
                break;
                
            case 2:
                cout << "Enter value to add at rear: ";
                cin >> value;
                dq.addRear(value);
                break;
                
            case 3:
                dq.deleteFront();
                break;
                
            case 4:
                dq.deleteRear();
                break;
                
            case 5:
                cout << "Front element: " << dq.getFront() << endl;
                break;
                
            case 6:
                cout << "Rear element: " << dq.getRear() << endl;
                break;
                
            case 7:
                dq.display();
                break;
                
            case 8:
                cout << "Exiting program. Goodbye!" << endl;
                break;
                
            default:
                cout << "Invalid choice! Please try again." << endl;
        }
    } while(choice != 8);
    
    return 0;
}

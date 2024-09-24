#include <iostream>
using namespace std;

struct QueueNode {
    int data;
    QueueNode* next;
    
};

class Queue {
private:
    QueueNode* backPtr; 

public:
    Queue() : backPtr(NULL) {
        
    }
   
    void enqueue(int newItem) {
        QueueNode* node = new QueueNode();
        node->data = newItem;

        if (backPtr == NULL) {
            node->next = node;
            backPtr = node;
        } else {
            
            node->next = backPtr->next;  
            backPtr->next = node;        
            backPtr = node;         
        }
    }

    bool dequeue(int &queueFront) {
        if (backPtr == NULL) {
            return false;
        }
        QueueNode* frontPtr = backPtr->next;
        queueFront = frontPtr->data;

        if (backPtr == frontPtr) {
            delete frontPtr;
            backPtr = NULL;
        } else {
            backPtr->next = frontPtr->next;
            delete frontPtr;
        }
        return true;
    }

    bool getFront(int &queueFront) {
        if (backPtr == NULL) {
            return false;
        }
        QueueNode* frontPtr = backPtr->next; 
        queueFront = frontPtr->data;
        return true;
    }

};

int main() {
    
    Queue queue;
    int frontItem; 
    
    cout << "Enqueueing 20,30,40,50:" << endl;
    queue.enqueue(20);
    queue.enqueue(30);
    queue.enqueue(40);
    queue.enqueue(50);

    if (queue.getFront(frontItem)) {
        cout << "Front item after enqueue is: " << frontItem << endl;
    } else {
        cout << "Queue is empty!" << endl;
    }

    cout << "Dequeueing elements: " << endl;
    while (queue.dequeue(frontItem)) {
        cout << "Dequeued: " << frontItem << endl;
    }

    if (queue.getFront(frontItem)) {
        cout << "Front item is: " << frontItem << endl;
    } else {
        cout << "Queue is empty after dequeueing all elements!" << endl;
    }

    return 0;
}

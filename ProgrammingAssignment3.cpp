#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
    
    Node(int value) : data(value), next(NULL) {
        
    }
};

class Stack {
private:
    Node* head; 

public:
    Stack() : head(NULL) {
        
    }
    void Push(int value) {
        Node* node = new Node(value); 
        node->next = head;
        head = node;                 
        cout<< "Pushed " << value << " onto the stack." <<endl;
    }

    int TopandPop() {
        if (head == NULL) {
            cout<< "Stack is empty!" <<endl;
            return -1;
        }
        Node* tmp = head;  
        int value = head->data; 
        head = head->next;   
        delete tmp;
        cout<< "Popped " << value << " from the stack." <<endl;
        return value;  
    }

    bool isEmpty() const {
        return head == NULL;
    }
};

int main() {
    Stack stack;

    stack.Push(11);
    stack.Push(22);
    stack.Push(33);
    stack.Push(44);
    stack.Push(55);
    
    while (!stack.isEmpty()) {
        stack.TopandPop();
    }
    
    stack.TopandPop();
    
    return 0;
}

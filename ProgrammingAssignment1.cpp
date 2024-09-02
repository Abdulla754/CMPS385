#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
    
    Node(int value) : data(value), next(NULL) {
        
    }
};

class LinkedList {
private:
    Node* head;
    
public:
    LinkedList() : head(NULL) {
        
    }

    
    int insertNode(int data, int index) {
        Node* node = new Node(data);
        if (index == 0) {
            node->next = head;
            head = node;
            return 0;
        }
        
        Node* curr = head;
        for (int i = 0; i < index - 1; i++) {
            if (curr == NULL) 
            return -1; 
            curr = curr->next;
        }

        if (curr == NULL)
            return -1; 

        node->next = curr->next;
        curr->next = node;
        return 0;
    }



    int deleteNode(int index) {
        if (head == NULL) 
        return -1;

        if (index == 0) {
            Node* temp = head;
            head = head->next;
            delete temp;
            return 0;
        }

        Node* curr = head;
        for (int i = 0; i < index - 1; i++) {
            if (curr == NULL || curr->next == NULL) 
            return -1;
            curr = curr->next;
        }

        Node* temp = curr->next;
        if (temp == NULL) 
        return -1;

        curr->next = temp->next;
        delete temp;
        return 0;
    }
    


    void printList() {
        Node* curr = head;
        while (curr != NULL) {
            cout << curr->data << " -> ";
            curr = curr->next;
        }
        cout << "NULL" << endl;
    }
};

int main() {
    LinkedList linkedlist;

    linkedlist.insertNode(7, 0);
    linkedlist.insertNode(12, 1); 
    linkedlist.insertNode(3, 2); 
   
    
    cout << "The linked list after insertions: ";
    linkedlist.printList();
    
    linkedlist.deleteNode(0);
    linkedlist.deleteNode(0); 

    
    cout << "The linked list after deletions: ";
    linkedlist.printList();
    
    return 0;
}

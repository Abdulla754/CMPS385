#include <iostream>

using namespace std;

struct Node {
    int data;
    Node* next;
    Node* prev;
    
    Node(int value) : data(value), next(NULL), prev(NULL) {
        
    }
};

class DoublyLinkedList {
private:
    Node* head;
    
public:
    DoublyLinkedList() : head(NULL) {
        
    }

    int DoublyInsert(int data, int index, Node** Ptr) {
        Node* node = new Node(data);
        Node* head = *Ptr;
        if (index == 0) {
            node->next = head;
            if (head != NULL) {
                head->prev = node;
            }
            *Ptr = node;
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
        node->prev = curr;
        if (curr->next != NULL) {
            curr->next->prev = node;
        }
        curr->next = node;
        return 0;
    }

    int DoublyDelete(int index, Node** Ptr) {
        Node* head = *Ptr;
        if (head == NULL) 
        return -1; 
        Node* curr = head;

        if (index == 0) {
            Node* temp = head;
            head = head->next;
            if (head != NULL) {
                head->prev = NULL;
            }
            *Ptr = head;
            delete temp;
            return 0;
        }

        for (int i = 0; i < index; i++) {
            if (curr == NULL) 
            return -1;
            curr = curr->next;
        }
        if (curr->prev != NULL) {
            curr->prev->next = curr->next;
        }
        if (curr->next != NULL) {
            curr->next->prev = curr->prev;
        }
        delete curr;
        return 0;
    }

    void printList(Node* head) {
        Node* curr = head;
        while (curr != NULL) {
            cout << curr->data << " <-> ";
            curr = curr->next;
        }
        cout << "NULL" <<endl;
    }
};

int main() {
    DoublyLinkedList linkedlist;
    Node* head = NULL;
    
    linkedlist.DoublyInsert(7, 0,&head); 
    linkedlist.DoublyInsert(12, 1,&head); 
    linkedlist.DoublyInsert(3, 2,&head); 
    
    
    cout << "The linked list after insertions: ";
    linkedlist.printList(head);
    
    linkedlist.DoublyDelete(0,&head); 
    linkedlist.DoublyDelete(0,&head);
    
    cout << "The linked list after deletions: ";
    linkedlist.printList(head);
    
    return 0;
}

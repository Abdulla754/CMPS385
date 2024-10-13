#include <iostream>

using namespace std;

struct NodeStru {
    int data;
    NodeStru *left;
    NodeStru *right;
    
    NodeStru(int value) : data(value), left(NULL), right(NULL){
        
    }
};

NodeStru* findMinimum(NodeStru* root) {
    while (root && root->left != NULL) {
        root = root->left;
    }
    return root;
    
}

void inorderTraversal(NodeStru* root) {
    if (root != NULL) {
        inorderTraversal(root->left);
        cout << root->data << " ";
        inorderTraversal(root->right);
    }
}

NodeStru* BSTInsertion(NodeStru* newNode, NodeStru* rootNode) {
    if (rootNode == NULL) {
        return newNode;
    }
     if (newNode->data < rootNode->data) {
        rootNode->left = BSTInsertion(newNode, rootNode->left);
    } else if (newNode->data > rootNode->data) {
        rootNode->right = BSTInsertion(newNode, rootNode->right);
    }
     return rootNode;
}

NodeStru* BSTDeletion(NodeStru* newNode, NodeStru* rootNode) {
    if (rootNode == NULL || newNode == NULL) {
        return rootNode;
    }
    if (newNode->data < rootNode->data) {
        rootNode->left = BSTDeletion(newNode, rootNode->left);
    } else if (newNode->data > rootNode->data) {
        rootNode->right = BSTDeletion(newNode, rootNode->right);
    } else {
        if (rootNode->left == NULL) {
            NodeStru* temp = rootNode->right;
            delete rootNode;
            return temp;
            
        } else if (rootNode->right == NULL) {
            NodeStru* temp = rootNode->left;
            delete rootNode;
            return temp;
        }
    NodeStru* temp = findMinimum(rootNode->right);
        rootNode->data = temp->data;
        rootNode->right = BSTDeletion(temp, rootNode->right);
    }

    return rootNode;
}

int main() {
    NodeStru* root = NULL;
    
    root = BSTInsertion(new NodeStru(40), root);
    root = BSTInsertion(new NodeStru(20), root);
    root = BSTInsertion(new NodeStru(10), root);
    root = BSTInsertion(new NodeStru(30), root);
    root = BSTInsertion(new NodeStru(60), root);
    root = BSTInsertion(new NodeStru(50), root);
    root = BSTInsertion(new NodeStru(70), root);

    cout << "Inorder traversal of the BST before deletion: ";
    inorderTraversal(root);
    cout << endl;

    NodeStru* nodeToDelete = new NodeStru(60);
    root = BSTDeletion(nodeToDelete, root);
    delete nodeToDelete; 
    
    cout << "Inorder traversal of the BST after deletion of 60: ";
    inorderTraversal(root);
    cout << endl;

    return 0;
}

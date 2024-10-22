#include <iostream>
#include <algorithm>

using namespace std;

struct AVLNode {
    int key;
    AVLNode* left;
    AVLNode* right;
    int height;
};

int height(AVLNode* node) {
    if (node == NULL)
        return 0;
    return node->height;
}

AVLNode* createNode(int key) {
    AVLNode* node = new AVLNode();
    node->key = key;
    node->left = node->right = NULL;
    node->height = 1; 
    return node;
}

AVLNode* rotateRight(AVLNode* y) {
    AVLNode* x = y->left;
    AVLNode* T2 = x->right;
    x->right = y;
    y->left = T2;
    y->height = max(height(y->left), height(y->right)) + 1;
    x->height = max(height(x->left), height(x->right)) + 1;

    return x;
}

AVLNode* rotateLeft(AVLNode* x) {
    AVLNode* y = x->right;
    AVLNode* T2 = y->left;
    y->left = x;
    x->right = T2;
    x->height = max(height(x->left), height(x->right)) + 1;
    y->height = max(height(y->left), height(y->right)) + 1;

    return y;
}

int getBalance(AVLNode* node) {
    if (node == NULL)
        return 0;
    return height(node->left) - height(node->right);
}

int InsertAVL(AVLNode*& T, int info) {
    if (T == NULL) {
        T = createNode(info);
        return 1;
    }
    if (info < T->key)
        InsertAVL(T->left, info);
    else if (info > T->key)
        InsertAVL(T->right, info);
    else
        return 0; 

    T->height = 1 + max(height(T->left), height(T->right));
    int balance = getBalance(T);

    if (balance > 1 && info < T->left->key)
        T = rotateRight(T);

    if (balance < -1 && info > T->right->key)
        T = rotateLeft(T);

    if (balance > 1 && info > T->left->key) {
        T->left = rotateLeft(T->left);
        T = rotateRight(T);
    }

    if (balance < -1 && info < T->right->key) {
        T->right = rotateRight(T->right);
        T = rotateLeft(T);
    }

    return 1;
}

AVLNode* minimumValueNode(AVLNode* node) {
    AVLNode* curr = node;

    while (curr->left != NULL)
        curr = curr->left;

    return curr;
}

int DeleteAVL(AVLNode*& T, int info) {
    if (T == NULL)
        return 0; 

    if (info < T->key)
        DeleteAVL(T->left, info);
    else if (info > T->key)
        DeleteAVL(T->right, info);
    else {
        if ((T->left == NULL) || (T->right == NULL)) {
            AVLNode* temp = T->left ? T->left : T->right;

            if (temp == NULL) {
                temp = T;
                T = NULL;
            } else
                *T = *temp;
            delete temp;
        } else {
            AVLNode* temp = minimumValueNode(T->right);

            T->key = temp->key;

            DeleteAVL(T->right, temp->key);
        }
    }

    if (T == NULL)
        return 1;

    T->height = 1 + max(height(T->left), height(T->right));

    int balance = getBalance(T);

    if (balance > 1 && getBalance(T->left) >= 0)
        T = rotateRight(T);

    if (balance > 1 && getBalance(T->left) < 0) {
        T->left = rotateLeft(T->left);
        T = rotateRight(T);
    }

    if (balance < -1 && getBalance(T->right) <= 0)
        T = rotateLeft(T);

    if (balance < -1 && getBalance(T->right) > 0) {
        T->right = rotateRight(T->right);
        T = rotateLeft(T);
    }

    return 1;
}

int createAVL(AVLNode*& T) {
    int array[] = {16, 18, 12, 17, 9, 14, 19, 15, 11, 5, 3};
    int n = sizeof(array) / sizeof(array[0]);

    for (int i = 0; i < n; i++) {
        if (InsertAVL(T, array[i]) == 0) {
            cout << "Insertion failed for: " << array[i] << endl;
            return 0;
        }
    }
    return 1;
}

void inOrder(AVLNode* root) {
    if (root != NULL) {
        inOrder(root->left);
        cout << root->key << " ";
        inOrder(root->right);
    }
}

int main() {
    AVLNode* root = NULL;

    if (createAVL(root)) {
        cout << "AVL tree created successfully!\n";
        cout << "In-order traversal of the AVL tree: ";
        inOrder(root);
        cout << endl;
    }

    if (InsertAVL(root, 13)) {
        cout << "Inserted 13 into the AVL tree.\n";
        cout << "In-order traversal after insertion: ";
        inOrder(root);
        cout << endl;
    }

    if (DeleteAVL(root, 9)) {
        cout << "Deleted 9 from the AVL tree.\n";
        cout << "In-order traversal after deletion: ";
        inOrder(root);
        cout << endl;
    }

    return 0;
}

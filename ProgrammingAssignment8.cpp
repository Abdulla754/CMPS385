#include <iostream>

using namespace std;

const int ORDER = 3; 

class BTreeNode {
public:
    int keys[ORDER-1];
    BTreeNode* children[ORDER]={NULL};
    int keysCount=0;
    bool isLeaf=true;

    BTreeNode(bool isLeaf);
    void traverse();
    void insertNonFull(int key);
    void splitChild(int index);
};

class BTree {
public:
    BTreeNode* root=NULL;

    BTree() {
        root=new BTreeNode(true);
    }

    void insert(int key);
    void traverse();
};

BTreeNode::BTreeNode(bool isLeaf) {
    this->isLeaf = isLeaf;
    keysCount=0;
}

void BTreeNode::insertNonFull(int key) {
    int i=keysCount-1;

    for (int j =0; j<keysCount;j++) {
        if (keys[j] ==key) {
            throw runtime_error("Key " + to_string(key) + " already exists in the B-tree.");
        }
    }
    if (isLeaf) {
        while (i>=0 && keys[i]>key) {
            keys[i+1] = keys[i];
            i--;
        }
        keys[i+1] =key;
        keysCount++;
    } else {
        while (i>=0 && keys[i]>key) {
            i--;
        }
        i++;

        if (children[i]->keysCount==ORDER -1) {
            splitChild(i);
            if (keys[i] < key) {
                i++;
            }
        }
        children[i]->insertNonFull(key);
    }
}

void BTreeNode::splitChild(int index) {
    BTreeNode* y=children[index];
    BTreeNode* z=new BTreeNode(y->isLeaf);
    int midIndex = (ORDER-1)/2;
    for (int j=0; j< ORDER-1 -midIndex-1;j++) {
        z->keys[j] = y->keys[j+midIndex+1];
    }

    if (!y->isLeaf) {
        for (int j=0; j<ORDER-midIndex-1;j++) {
            z->children[j] = y->children[j + midIndex + 1];
        }
    }

    z->keysCount = ORDER-1-midIndex-1;
    y->keysCount = midIndex;

    for (int j=keysCount; j>=index+1; j--) {
        children[j+1] =children[j];
    }
    children[index+1]=z;

    for (int j=keysCount-1; j>=index; j--) {
        keys[j+1] = keys[j];
    }
    keys[index]=y->keys[midIndex];
    keysCount++;
}

void BTree::insert(int key) {
    if (root->keysCount==ORDER-1) {
        BTreeNode* newRoot=new BTreeNode(false);
        newRoot->children[0]=root;
        newRoot->splitChild(0);
        int i=0;
        if (newRoot->keys[0]<key) {
            i++;
        }
        newRoot->children[i]->insertNonFull(key);
        root=newRoot;
    } else {
        root->insertNonFull(key);
    }
}

void BTree::traverse() {
    if (root != NULL) {
        root->traverse();
    }
    cout<<endl;
}

void BTreeNode::traverse() {
    int i;
    for (i =0; i<keysCount;i++) {
        if (!isLeaf) {
            children[i]->traverse();
        }
        cout<< keys[i]<< " ";
    }
    if (!isLeaf) {
        children[i]->traverse();
    }
}

int main() {
    BTree tree;

    int keys[] = {15,6,9,13,25,100,54,32};
    for (int key : keys) {
            cout << "Inserting " << key << "..." << endl;
            tree.insert(key);
        }

    cout << "The traversal of B-tree of order " << ORDER << " after inserts: ";
    tree.traverse();

    return 0;
}

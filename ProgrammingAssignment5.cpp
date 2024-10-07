#include <iostream>

using namespace std;

class TreeNode {
public:
    string name;
    bool dir;
    int size;
    TreeNode* firstChild;
    TreeNode* nextSibling;

    TreeNode(string n, bool isDirectory, int s = 0) 
        : name(n), dir(isDirectory), size(s), firstChild(NULL), nextSibling(NULL) {}

    bool isDirectory() const {
        return dir;
    }

    int sizeOf() const {
        return size;
    }

    void addChild(TreeNode* child) {
        if (dir) {
            if (!firstChild) {
                firstChild = child;
            } else {
                TreeNode* curr = firstChild;
                while (curr->nextSibling) {
                    curr = curr->nextSibling;
                }
                curr->nextSibling = child;
            }
        }
    }
};

void printName(TreeNode* t, int depth) {
    for (int i=0; i<depth;i++) {
        cout<< "  ";
    }
    cout<< t->name<<endl;
}

void listAll(TreeNode* t, int depth) {
    if (!t) {
    return;
    }
    printName(t, depth);
    if (t->isDirectory()) {
        for (TreeNode* child = t->firstChild; child; child = child->nextSibling) {
            listAll(child, depth + 1);
        }
    }
}

class FileSystem {
public:
    int size(TreeNode* t) const {
        if (!t) {
        return 0;
        }
        int totalSize = t->sizeOf(); 
        if (t->isDirectory()) {
            for (TreeNode* child = t->firstChild; child; child = child->nextSibling) {
                totalSize += size(child);
            }
        }

        return totalSize;
    }
};

int main() {
    
    TreeNode* root = new TreeNode("root", true);
    TreeNode* file = new TreeNode("file.txt", false, 100);
    TreeNode* file1 = new TreeNode("file1.txt", false, 200);
    TreeNode* dir = new TreeNode("dir", true);
    TreeNode* dir1 = new TreeNode("dir1", true);

    root->addChild(file);
    root->addChild(dir);

    dir->addChild(file1);
    dir->addChild(dir1);

    TreeNode* file2 = new TreeNode("file2.txt", false, 300);
    dir1->addChild(file2);
    
    FileSystem fs;

    cout<< "Directory Listing:"<<endl;
    listAll(root, 0);
     
    cout<<endl;
    cout<< "The total size of the root directory is: " << fs.size(root) << " bytes" <<endl;


    return 0;
}

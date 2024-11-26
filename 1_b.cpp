#include <iostream>
#include <queue>
using namespace std;

class node {
    public:
        int data;
        node* left;
        node* right;

    node(int val) {
        data = val;
        left = NULL;
        right = NULL;
    }
};

node* insert(node* root, int val) {
    if (root == NULL) {
        root = new node(val);
        return root;
    }

    if (val < root->data) {
        root->left = insert(root->left, val);
    } else {
        root->right = insert(root->right, val);
    }
    return root;
}

void traversal(node* root) {
    if (root == NULL) return;

    queue<node*> q;
    q.push(root);
    q.push(NULL);

    while (!q.empty()) {
        node* temp = q.front();
        q.pop();

        if (temp == NULL) {
            cout << endl;
            if (!q.empty()) {
                q.push(NULL);
            }
        } else {
            cout << temp->data << " ";
            if (temp->left) {
                q.push(temp->left);
            }
            if (temp->right) {
                q.push(temp->right);
            }
        }
    }
}

node* minVal(node* root) {
    node* temp = root;
    while (temp->left != NULL) {
        temp = temp->left;
    }
    return temp;
}

bool search(node* root, int val) {
    if (root == NULL) return false;

    if (root->data == val) {
        return true;
    } else if (val < root->data) {
        return search(root->left, val);
    } else {
        return search(root->right, val);
    }
}

node* deleteNode(node* root, int val) {
    if (root == NULL) {
        return NULL;
    }

    if (root->data == val) {
        if (root->left == NULL && root->right == NULL) {
            delete root;
            return NULL;
        }
        if (root->left != NULL && root->right == NULL) {
            node* temp = root->left;
            delete root;
            return temp;
        }
        if (root->left == NULL && root->right != NULL) {
            node* temp = root->right;
            delete root;
            return temp;
        }
        if (root->left != NULL && root->right != NULL) {
            int mini = minVal(root->right)->data;
            root->data = mini;
            root->right = deleteNode(root->right, mini);
            return root;
        }
    } else if (val < root->data) {
        root->left = deleteNode(root->left, val);
    } else {
        root->right = deleteNode(root->right, val);
    }
    return root;
}

int main() {
    node* root = NULL;
    int choice, val;

    while (true) {
        cout << "\nBinary Search Tree Operations:\n";
        cout << "1. Insert\n";
        cout << "2. Delete\n";
        cout << "3. Search\n";
        cout << "4. Level-Order Traversal\n";
        cout << "5. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter value to insert: ";
                cin >> val;
                root = insert(root, val);
                break;
            case 2:
                cout << "Enter value to delete: ";
                cin >> val;
                root = deleteNode(root, val);
                break;
            case 3:
                cout << "Enter value to search: ";
                cin >> val;
                if (search(root, val)) {
                    cout << "Value found in the tree.\n";
                } else {
                    cout << "Value not found in the tree.\n";
                }
                break;
            case 4:
                cout << "Level-Order Traversal:\n";
                traversal(root);
                break;
            case 5:
                cout << "Exiting program.\n";
                return 0;
            default:
                cout << "Invalid choice! Please try again.\n";
        }
    }
}

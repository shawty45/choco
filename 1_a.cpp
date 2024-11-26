#include<iostream>
#include<queue>
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

node* build(node* root) {
    cout << "Enter the data : ";
    int data;
    cin >> data;

    if (data == -1) {  // Termination condition
        return NULL;
    }

    root = new node(data);

    cout << "Enter the data for the left of " << data << ": ";
    root->left = build(root->left);
    cout << "Enter the data for the right of " << data << ": ";
    root->right = build(root->right);

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

int depth(node* root) {
    if (root == NULL) return 0;

    int leftDepth = depth(root->left);
    int rightDepth = depth(root->right);

    return max(leftDepth, rightDepth) + 1;
}

void displayLeaves(node* root) {
    if (root != NULL) {
        if (root->left == NULL && root->right == NULL) {
            cout << root->data << " ";
        }
        displayLeaves(root->left);
        displayLeaves(root->right);
    }
}

node* copyTree(node* root) {
    if (root == NULL) {
        return NULL;
    }

    node* newRoot = new node(root->data);
    newRoot->left = copyTree(root->left);
    newRoot->right = copyTree(root->right);
    return newRoot;
}

int main() {
    node* root = NULL;

    // Build the tree
    root = build(root);

    // Display the tree in level order traversal
    cout << "\nLevel Order Traversal:" << endl;
    traversal(root);

    // Calculate and display the depth of the tree
    int treeDepth = depth(root);
    cout << "\nDepth of the tree: " << treeDepth << endl;

    // Display leaf nodes
    cout << "Leaf nodes: ";
    displayLeaves(root);
    cout << endl;

    // Create and display a copy of the tree
    node* copiedRoot = copyTree(root);
    cout << "\nLevel Order Traversal of Copied Tree:" << endl;
    traversal(copiedRoot);

    return 0;
}

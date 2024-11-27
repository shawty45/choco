#include <iostream>
#include <algorithm>
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

// Insert a node into the binary tree
node* InsertNode(node* &root, int val) {
    if (root == NULL) {
        node* new_node = new node(val);
        return new_node;
    }

    if (val < root->data) {
        root->left = InsertNode(root->left, val);
    } else if (val > root->data) {
        root->right = InsertNode(root->right, val);
    }
    return root;
}

// Inorder traversal (L-R-R)
void InorderDisplay(node* root) {
    if (root == NULL) {
        return;
    }
    InorderDisplay(root->left);
    cout << root->data << " ";
    InorderDisplay(root->right);
}

// Preorder traversal (R-L-R)
void PreorderDisplay(node* root) {
    if (root == NULL) {
        return;
    }
    cout << root->data << " ";
    PreorderDisplay(root->left);
    PreorderDisplay(root->right);
}

// Postorder traversal (R-R-L)
void PostorderDisplay(node* root) {
    if (root == NULL) {
        return;
    }
    PostorderDisplay(root->left);
    PostorderDisplay(root->right);
    cout << root->data << " ";
}

// Find depth of the tree
int findDepth(node* root) {
    if (root == NULL) {
        return 0;
    }
    int leftDepth = findDepth(root->left);
    int rightDepth = findDepth(root->right);
    return max(leftDepth, rightDepth) + 1;
}

// Display leaf nodes
void displayLN(node* root) {
    if (root == NULL) {
        return;
    }
    if (root->left == NULL && root->right == NULL) {
        cout << root->data << " ";
    }
    displayLN(root->left);
    displayLN(root->right);
}

// Copy the tree
node* copyTree(node* originalRoot) {
    if (originalRoot == NULL) {
        return NULL;
    }
    node* newNode = new node(originalRoot->data);
    newNode->left = copyTree(originalRoot->left);
    newNode->right = copyTree(originalRoot->right);
    return newNode;
}

int main() {
    node* root = NULL;
    int choice, nodeData;
    bool continueInput = true;

    while (true) {
        // Display menu
        cout << "\nMenu: \n";
        cout << "1. Insert a node\n";
        cout << "2. Inorder Display\n";
        cout << "3. Preorder Display\n";
        cout << "4. Postorder Display\n";
        cout << "5. Find Depth of Tree\n";
        cout << "6. Display Leaf Nodes\n";
        cout << "7. Copy the Tree\n";
        cout << "8. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                // Insert a node
                cout << "Enter the value of the node to insert: ";
                cin >> nodeData;
                root = InsertNode(root, nodeData);
                cout << "Node inserted successfully.\n";
                break;

            case 2:
                // Inorder Display
                cout << "Inorder Display: ";
                InorderDisplay(root);
                cout << endl;
                break;

            case 3:
                // Preorder Display
                cout << "Preorder Display: ";
                PreorderDisplay(root);
                cout << endl;
                break;

            case 4:
                // Postorder Display
                cout << "Postorder Display: ";
                PostorderDisplay(root);
                cout << endl;
                break;

            case 5:
                // Find Depth of Tree
                cout << "Depth of the Tree: " << findDepth(root) << endl;
                break;

            case 6:
                // Display Leaf Nodes
                cout << "Leaf Nodes: ";
                displayLN(root);
                cout << endl;
                break;

            case 7:
                // Copy the Tree
                node* copiedTreeRoot = copyTree(root);
                cout << "Inorder Display of the Copied Tree: ";
                InorderDisplay(copiedTreeRoot);
                cout << endl;
                break;

            case 8:
                // Exit
                cout << "Exiting the program...\n";
                return 0;

            default:
                cout << "Invalid choice! Please enter a valid option.\n";
        }
    }

    return 0;
}
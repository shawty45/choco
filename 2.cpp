#include <iostream>
#include <stack>
#include <vector>
#include <algorithm>
using namespace std;

class Node {
public:
    char data;
    Node* left;
    Node* right;

    Node(char val) {
        data = val;
        left = NULL;
        right = NULL;
    }
};

// Function to check if a character is an operator
int isOperator(char element) {
    if (element == '+' || element == '-' || element == '/' || element == '*') {
        return 1;
    }
    return 0;
}

// Function to return precedence of operators
int precedence(char op) {
    if (op == '+' || op == '-') {
        return 1;
    }
    if (op == '*' || op == '/') {
        return 2;
    }
    return 0;
}

// Function to convert Infix to Postfix
string infixToPostfix(string infix) {
    stack<char> operators;
    string postfix = "";

    for (char& c : infix) {
        // If it's an operand, append to the postfix string
        if (isalnum(c)) {
            postfix += c;
        }
        // If it's an opening parenthesis, push to the stack
        else if (c == '(') {
            operators.push(c);
        }
        // If it's a closing parenthesis, pop from the stack until '(' is found
        else if (c == ')') {
            while (!operators.empty() && operators.top() != '(') {
                postfix += operators.top();
                operators.pop();
            }
            operators.pop();  // Pop '('
        }
        // If it's an operator, pop higher precedence operators from the stack
        else if (isOperator(c)) {
            while (!operators.empty() && precedence(operators.top()) >= precedence(c)) {
                postfix += operators.top();
                operators.pop();
            }
            operators.push(c);
        }
    }

    // Pop remaining operators from the stack
    while (!operators.empty()) {
        postfix += operators.top();
        operators.pop();
    }

    return postfix;
}

// Function to build an expression tree from a postfix expression
Node* ExpTree(const char expArr[], int size) {
    Node* stack[50];
    int top = 0;

    for (int i = 0; i < size; i++) {
        if (!isOperator(expArr[i])) {
            // Operand, create a new node and push it to the stack
            Node* operand = new Node(expArr[i]);
            stack[top++] = operand;
        } else {
            // Operator, pop two operands, create a new operator node, and push it to the stack
            Node* operatorNode = new Node(expArr[i]);
            operatorNode->right = stack[--top];
            operatorNode->left = stack[--top];
            stack[top++] = operatorNode;
        }
    }
    return stack[0];  // Root of the expression tree
}

// Non-recursive inorder display
void inorderDisplayNR(Node* root) {
    if (root == NULL) return;

    stack<Node*> s;
    Node* current = root;

    while (current != NULL || !s.empty()) {
        while (current != NULL) {
            s.push(current);
            current = current->left;
        }
        current = s.top();
        s.pop();
        cout << current->data << " ";
        current = current->right;
    }
}

// Non-recursive preorder display
void preorderDisplayNR(Node* root) {
    if (root == NULL) return;

    stack<Node*> s;
    Node* current = root;

    while (current != NULL || !s.empty()) {
        while (current != NULL) {
            cout << current->data << " ";
            s.push(current);
            current = current->left;
        }
        current = s.top();
        s.pop();
        current = current->right;
    }
}

// Non-recursive postorder display
void postorderDisplayNR(Node* root) {
    if (root == NULL) return;

    stack<Node*> s;
    Node* current = root;
    Node* lastVisited = NULL;

    while (current != NULL || !s.empty()) {
        while (current != NULL) {
            s.push(current);
            current = current->left;
        }

        current = s.top();
        if (current->right == NULL || current->right == lastVisited) {
            cout << current->data << " ";
            s.pop();
            lastVisited = current;
            current = NULL;
        } else {
            current = current->right;
        }
    }
}

int main() {
    int choice;
    string infix;
    string postfix;
    Node* root = NULL;

    while (true) {
        // Display menu options
        cout << "\nMenu: \n";
        cout << "1. Input postfix expression\n";
        cout << "2. Input infix expression\n";
        cout << "3. Display non-recursive Inorder traversal\n";
        cout << "4. Display non-recursive Preorder traversal\n";
        cout << "5. Display non-recursive Postorder traversal\n";
        cout << "6. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1: {
                // Input postfix expression
                int size;
                cout << "Enter size of the postfix expression: ";
                cin >> size;
                vector<char> expArr(size);
                cout << "Enter the postfix expression: ";
                for (int i = 0; i < size; i++) {
                    cin >> expArr[i];
                }

                root = ExpTree(expArr.data(), size);
                cout << "\nExpression tree created successfully.\n";
                break;
            }

            case 2: {
                // Input infix expression
                cout << "Enter infix expression: ";
                cin >> infix;
                postfix = infixToPostfix(infix);

                cout << "Infix expression: " << infix << endl;
                cout << "Converted Postfix expression: " << postfix << endl;

                // Create tree from postfix expression
                vector<char> expArrPostfix(postfix.begin(), postfix.end());
                root = ExpTree(expArrPostfix.data(), expArrPostfix.size());
                cout << "\nExpression tree created successfully.\n";
                break;
            }

            case 3:
                if (root == NULL) {
                    cout << "No expression tree exists. Please input an expression first.\n";
                } else {
                    // Display non-recursive Inorder traversal
                    cout << "\nNon-recursive Inorder display: ";
                    inorderDisplayNR(root);
                    cout << endl;
                }
                break;

            case 4:
                if (root == NULL) {
                    cout << "No expression tree exists. Please input an expression first.\n";
                } else {
                    // Display non-recursive Preorder traversal
                    cout << "\nNon-recursive Preorder display: ";
                    preorderDisplayNR(root);
                    cout << endl;
                }
                break;

            case 5:
                if (root == NULL) {
                    cout << "No expression tree exists. Please input an expression first.\n";
                } else {
                    // Display non-recursive Postorder traversal
                    cout << "\nNon-recursive Postorder display: ";
                    postorderDisplayNR(root);
                    cout << endl;
                }
                break;

            case 6:
                cout << "Exiting the program.\n";
                return 0;

            default:
                cout << "Invalid choice! Please try again.\n";
        }
    }

    return 0;
}

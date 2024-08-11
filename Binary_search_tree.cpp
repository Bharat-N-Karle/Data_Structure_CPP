#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;
    
    Node(int value) {
        data = value;
        left = right = nullptr;
    }
};

Node* root = nullptr;
Node* insertNode(Node* node, int value) {
    if (node == nullptr) {
        return new Node(value);
    }

    if (value < node->data) {
        node->left = insertNode(node->left, value);
    } else if (value > node->data) {
        node->right = insertNode(node->right, value);
    }

    return node;
}
void inOrderTraversal(Node* node) {
    if (node == nullptr)
        return;

    inOrderTraversal(node->left);
    cout << node->data << " ";
    inOrderTraversal(node->right);
}
void preOrderTraversal(Node* node) {
    if (node == nullptr)
        return;

    cout << node->data << " ";
    preOrderTraversal(node->left);
    preOrderTraversal(node->right);
}
void postOrderTraversal(Node* node) {
    if (node == nullptr)
        return;

    postOrderTraversal(node->left);
    postOrderTraversal(node->right);
    cout << node->data << " ";
}
bool searchNode(Node* node, int value) {
    if (node == nullptr) {
        return false;
    }

    if (node->data == value) {
        return true;
    }

    if (value < node->data) {
        return searchNode(node->left, value);
    }

    return searchNode(node->right, value);
}
Node* minValueNode(Node* node) {
    Node* current = node;

    // Loop down to find the leftmost leaf
    while (current && current->left != nullptr)
        current = current->left;

    return current;
}

Node* deleteNode(Node* root, int value) {
    if (root == nullptr) return root;

    if (value < root->data)
        root->left = deleteNode(root->left, value);
    else if (value > root->data)
        root->right = deleteNode(root->right, value);
    else {
        // Node with only one child or no child
        if (root->left == nullptr) {
            Node* temp = root->right;
            delete root;
            return temp;
        } else if (root->right == nullptr) {
            Node* temp = root->left;
            delete root;
            return temp;
        }

        // Node with two children: Get the inorder successor (smallest in the right subtree)
        Node* temp = minValueNode(root->right);

        // Copy the inorder successor's content to this node
        root->data = temp->data;

        // Delete the inorder successor
        root->right = deleteNode(root->right, temp->data);
    }
    return root;
}
int main() {
    int choice, value;

    do {
        cout << "\nMenu:\n";
        cout << "1. Insert Node\n";
        cout << "2. In-Order Traversal\n";
        cout << "3. Pre-Order Traversal\n";
        cout << "4. Post-Order Traversal\n";
        cout << "5. Search Node\n";
        cout << "6. Delete Node\n";
        cout << "7. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter the value to insert: ";
                cin >> value;
                root = insertNode(root, value);
                cout << "Node inserted successfully!" << endl;
                break;
            case 2:
                cout << "In-Order Traversal: ";
                inOrderTraversal(root);
                cout << endl;
                break;
            case 3:
                cout << "Pre-Order Traversal: ";
                preOrderTraversal(root);
                cout << endl;
                break;
            case 4:
                cout << "Post-Order Traversal: ";
                postOrderTraversal(root);
                cout << endl;
                break;
            case 5:
                cout << "Enter the value to search: ";
                cin >> value;
                if (searchNode(root, value)) {
                    cout << "Node found!" << endl;
                } else {
                    cout << "Node not found." << endl;
                }
                break;
            case 6:
                cout << "Enter the value to delete: ";
                cin >> value;
                root = deleteNode(root, value);
                cout << "Node deleted successfully!" << endl;
                break;
            case 7:
                cout << "Exiting..." << endl;
                break;
            default:
                cout << "Invalid choice. Please try again." << endl;
        }
    } while (choice != 7);

    return 0;
}

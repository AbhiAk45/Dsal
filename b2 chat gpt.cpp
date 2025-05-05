#include <iostream>
using namespace std;

struct Node {
    int data;
    Node *left, *right;
    Node(int val) : data(val), left(NULL), right(NULL) {}
};

Node* insert(Node* root, int val) {
    if (!root) return new Node(val);
    if (val < root->data) root->left = insert(root->left, val);
    else root->right = insert(root->right, val);
    return root;
}

void preorder(Node* root) {
    if (!root) return;
    cout << root->data << " ";
    preorder(root->left);
    preorder(root->right);
}

int height(Node* root) {
    if (!root) return 0;
    return max(height(root->left), height(root->right)) + 1;
}

int findMin(Node* root) {
    if (!root) return -1;
    while (root->left) root = root->left;
    return root->data;
}

void mirror(Node* root) {
    if (!root) return;
    swap(root->left, root->right);
    mirror(root->left);
    mirror(root->right);
}

bool search(Node* root, int key) {
    if (!root) return false;
    if (root->data == key) return true;
    return key < root->data ? search(root->left, key) : search(root->right, key);
}

int main() {
    Node* root = NULL;
    int n, val, key;
    cout << "Enter number of nodes: ";
    cin >> n;

    while (n--) {
        cout << "Enter value to insert: ";
        cin >> val;
        root = insert(root, val);
    }

    cout << "BST before swapping: ";
    preorder(root); cout << endl;

    cout << "Height: " << height(root) << endl;
    cout << "Minimum value: " << findMin(root) << endl;

    mirror(root);
    cout << "BST after swapping: ";
    preorder(root); cout << endl;

    cout << "Enter value to search: ";
    cin >> key;
    cout << (search(root, key) ? "Found!" : "Not found!") << endl;

    return 0;
}


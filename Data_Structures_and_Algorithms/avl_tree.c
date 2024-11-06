#include <stdio.h>
#include <stdlib.h>

// Node structure for AVL Tree
typedef struct Node {
    int key;                  // Key value of the node
    struct Node *left;        // Pointer to the left child
    struct Node *right;       // Pointer to the right child
    int height;               // Height of the node for balancing
} Node;

// Function prototypes
int main();
Node* createNode_avl(int key);              // Creates a new node
int height(Node *node);                 // Returns the height of a node
int max(int a, int b);                  // Utility to get the maximum of two integers
void insert_avl(Node **node, int key);      // insert_avls a node with the given key
void deleteNode(Node **root, int key);  // Deletes a node with the given key
Node* rightRotate(Node *y);             // Performs right rotation
Node* leftRotate(Node *x);              // Performs left rotation
int getBalance(Node *node);             // Returns balance factor of the node
Node* minValueNode(Node *node);         // Finds node with minimum key value in a subtree
void inorderTraversal(Node *root);      // Inorder traversal of the tree
void printMenu();                       // Prints menu for the user

// Main function to run the menu-driven program
int avl_tree() {
    printf("\n####### Welcome in AVL Tree Program #######\n");
    Node *root = NULL;       // Initialize root as NULL
    int choice, key;         // Variables for menu choice and key input

    while (1) {
        printMenu();         // Display menu
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter key to insert_avl: ");
                scanf("%d", &key);
                insert_avl(&root, key);  // insert_avl key by reference
                printf("insert_avled %d\n", key);
                break;
            case 2:
                printf("Enter key to delete: ");
                scanf("%d", &key);
                deleteNode(&root, key);  // Delete key by reference
                printf("Deleted %d\n", key);
                break;
            case 3:
                printf("Inorder traversal: ");
                inorderTraversal(root);  // Print inorder traversal
                printf("\n");
                break;
            case 4:
                printf("Exiting program.\n");
                return main();
                //exit(0);               // Exit program
            default:
                printf("Invalid choice, please try again.\n");
        }
    }
    return 0;
}

// Function to print the menu options
void printMenu() {
    printf("\n---  Menu ---\n");
    printf("1. insert_avl\n");
    printf("2. Delete\n");
    printf("3. Print Inorder Traversal\n");
    printf("4. Exit\n");
}

// Returns height of a node (or 0 if NULL)
int height(Node *node) {
    return node ? node->height : 0;
}

// Returns maximum of two integers
int max(int a, int b) {
    return (a > b) ? a : b;
}

// Creates a new node with the given key
Node* createNode_avl(int key) {
    Node *node = (Node *)malloc(sizeof(Node));
    node->key = key;
    node->left = node->right = NULL;
    node->height = 1;       // New nodes are initially at height 1
    return node;
}

// Right rotation to balance nodes
Node* rightRotate(Node *y) {
    Node *x = y->left;
    Node *T2 = x->right;

    // Perform rotation
    x->right = y;
    y->left = T2;

    // Update heights
    y->height = max(height(y->left), height(y->right)) + 1;
    x->height = max(height(x->left), height(x->right)) + 1;

    return x;   // New root after rotation
}

// Left rotation to balance nodes
Node* leftRotate(Node *x) {
    Node *y = x->right;
    Node *T2 = y->left;

    // Perform rotation
    y->left = x;
    x->right = T2;

    // Update heights
    x->height = max(height(x->left), height(x->right)) + 1;
    y->height = max(height(y->left), height(y->right)) + 1;

    return y;   // New root after rotation
}

// Get balance factor of a node
int getBalance(Node *node) {
    return node ? height(node->left) - height(node->right) : 0;
}

// insert_avl a node with given key into the AVL tree, maintaining balance
void insert_avl(Node **node, int key) {
    if (*node == NULL) {
        *node = createNode_avl(key);  // Create and assign node if NULL
        return;
    }

    if (key < (*node)->key)
        insert_avl(&(*node)->left, key);  // Recur on left subtree
    else if (key > (*node)->key)
        insert_avl(&(*node)->right, key); // Recur on right subtree
    else
        return;  // Duplicate keys are not allowed in BST

    // Update height of this node
    (*node)->height = max(height((*node)->left), height((*node)->right)) + 1;

    // Get balance factor and perform rotations if unbalanced
    int balance = getBalance(*node);

    // Left Left Case
    if (balance > 1 && key < (*node)->left->key)
        *node = rightRotate(*node);

    // Right Right Case
    else if (balance < -1 && key > (*node)->right->key)
        *node = leftRotate(*node);

    // Left Right Case
    else if (balance > 1 && key > (*node)->left->key) {
        (*node)->left = leftRotate((*node)->left);
        *node = rightRotate(*node);
    }

    // Right Left Case
    else if (balance < -1 && key < (*node)->right->key) {
        (*node)->right = rightRotate((*node)->right);
        *node = leftRotate(*node);
    }
}

// Finds node with the smallest key value in the subtree
Node* minValueNode(Node *node) {
    Node *current = node;
    while (current->left != NULL)
        current = current->left;
    return current;
}

// Deletes a node with given key, balancing the AVL tree
void deleteNode(Node **root, int key) {
    if (*root == NULL)
        return;

    if (key < (*root)->key)
        deleteNode(&(*root)->left, key);  // Key in left subtree
    else if (key > (*root)->key)
        deleteNode(&(*root)->right, key); // Key in right subtree
    else {
        if ((*root)->left == NULL || (*root)->right == NULL) {
            Node *temp = (*root)->left ? (*root)->left : (*root)->right;
            if (temp == NULL) {
                temp = *root;
                *root = NULL;
            } else {
                **root = *temp;
            }
            free(temp);
        } else {
            Node *temp = minValueNode((*root)->right);
            (*root)->key = temp->key;
            deleteNode(&(*root)->right, temp->key);
        }
    }

    if (*root == NULL)
        return;

    (*root)->height = max(height((*root)->left), height((*root)->right)) + 1;
    int balance = getBalance(*root);

    // Balance the node if unbalanced
    if (balance > 1 && getBalance((*root)->left) >= 0)
        *root = rightRotate(*root);
    else if (balance > 1 && getBalance((*root)->left) < 0) {
        (*root)->left = leftRotate((*root)->left);
        *root = rightRotate(*root);
    }
    else if (balance < -1 && getBalance((*root)->right) <= 0)
        *root = leftRotate(*root);
    else if (balance < -1 && getBalance((*root)->right) > 0) {
        (*root)->right = rightRotate((*root)->right);
        *root = leftRotate(*root);
    }
}

// Performs an inorder traversal of the AVL tree
void inorderTraversal(Node *root) {
    if (root != NULL) {
        inorderTraversal(root->left);
        printf("%d ", root->key);
        inorderTraversal(root->right);
    }
}

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include"dsa.h"

// Define a structure for a binary tree node
typedef struct tree {
  int data; // Data stored in the node
  struct tree *left; // Pointer to the left child
  struct tree *right; // Pointer to the right child
} tree;

// Function prototypes for tree operations
tree *newRoot(int element); // Create a new tree node
void insert_t(tree** root,int element); // insert_t an element into the tree
void inorder(tree* root); // Inorder traversal of the tree
void preorder(tree* root); // Preorder traversal of the tree
void postorder(tree* root); // Postorder traversal of the tree
void freeTree(tree* root); // Free the memory allocated for the tree

int Tree() {
    printf("\n####### Welcome in Tree Program #######\n");
    tree *root = NULL; // Initialize the root of the tree
    int choice, element; // Variables for user choice and element input
    
    while (1) { // Infinite loop for menu display and choice handling
        printf("\n*****Menu*****\n");
        printf("1. insert_t\n"); // Option to insert_t a new element
        printf("2. Inorder\n"); // Option for inorder traversal
        printf("3. Preorder\n"); // Option for preorder traversal
        printf("4. Postorder\n"); // Option for postorder traversal
        printf("5. Exit\n"); // Option to exit the program
        printf("Your choice -> ");
        scanf("%d", &choice); // Get user choice
        printf("\n");
        
        switch (choice) { // Handle user choice
            case 1: // insert_t operation
                printf("Enter element to insert_t: "); // Prompt for element to insert_t
                scanf("%d", &element);
                insert_t(&root, element); // Call insert_t function
                break;
            case 2: // Inorder traversal operation
                printf("Inorder traversal: "); // Display traversal method
                inorder(root); // Call inorder traversal function
                printf("|\n");
                break;
            case 3: // Preorder traversal operation
                printf("Preorder traversal: "); // Display traversal method
                preorder(root); // Call preorder traversal function
                printf("|\n");
                break;
            case 4: // Postorder traversal operation
                printf("Postorder traversal: "); // Display traversal method
                postorder(root); // Call postorder traversal function
                printf("|\n");
                break;
            case 5: // Exit operation
                freeTree(root); // Free allocated memory for the tree
                return main();
                //exit(0); // Exit program
            default: // Invalid choice
                printf("Wrong choice! Try again..\n");
        }
    }
    return 0; // Return success
}

// Function to create a new tree node
tree *newRoot(int element){
 tree *node=(tree *)malloc(sizeof(tree)); // Allocate memory for a new node
 if (!node) { // Check for memory allocation failure
    printf("Memory allocation failed\n"); // Notify if allocation fails
    exit(0); // Exit if memory allocation fails
}
 node->data=element; // Set the data for the new node
 node->left=NULL; // Initialize left child to NULL
 node->right=NULL; // Initialize right child to NULL
 return node; // Return the newly created node
}

// Function to insert_t an element into the tree
void insert_t(tree** root,int element){
  if(*root==NULL){ // If the current position is empty
    *root=newRoot(element); // Create a new node and set it as the root
    return; // Exit the function
  }
  if(element<(*root)->data) // If the element is less than the current node's data
  insert_t(&((*root)->left),element); // Recur on the left child
  else insert_t(&((*root)->right),element); // Otherwise, recur on the right child
}

// Function for inorder traversal of the tree
void inorder(tree* root){
  if(root!=NULL){ // If the current node is not NULL
    inorder(root->left); // Recur on the left child
    printf("| %d ",root->data); // Print the current node's data
    inorder(root->right); // Recur on the right child
  }
}

// Function for preorder traversal of the tree
void preorder(tree* root){
  if(root!=NULL){ // If the current node is not NULL
    printf("| %d ",root->data); // Print the current node's data
    preorder(root->left); // Recur on the left child
    preorder(root->right); // Recur on the right child
  }
}

// Function for postorder traversal of the tree
void postorder(tree* root){
  if(root!=NULL){ // If the current node is not NULL
    postorder(root->left); // Recur on the left child
    postorder(root->right); // Recur on the right child
    printf("| %d ",root->data); // Print the current node's data
  }
}

// Function to free the memory allocated for the tree
void freeTree(tree* root) {
    if (root != NULL) { // If the current node is not NULL
        freeTree(root->left); // Recur on the left child
        freeTree(root->right); // Recur on the right child
        free(root); // Free the current node
    }
}


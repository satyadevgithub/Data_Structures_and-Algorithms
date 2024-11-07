#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include"dsa.h"

// Define a structure to hold student data
typedef struct {
    char name[100]; 
    int prn; 
} data;

// Define a node structure for the linked list
typedef struct node {
    data *data; // Pointer to student data
    struct node *next; // Pointer to the next node
} node;

// Function prototypes
node* createNode_c(); // Create a new node
int checkDuplicate_c(node* head, node* newNode); // Check for duplicate PRN
void insertAtEnd_c(node** head); // Insert a node at the end of the list
void insertAtBeg_c(node** head); // Insert a node at the beginning of the list
void insertAtPos_c(node** head); // Insert a node at a specified position
void displayList_c(node* head); // Display the entire list
int listNodeCount_c(node* head); // Count the number of nodes in the list
void deleteFromEnd_c(node** head); // Delete a node from the end of the list
void deleteFromBeg_c(node** head); // Delete a node from the beginning of the list
void deleteFromPos_c(node** head); // Delete a node from a specified position
void deleteByElement_c(node** head); // Delete a node by its PRN
void reverseDisplay_c(node* head,node* current); // Display the list in reverse order
void freeAllNode_c(node** head); // Free all nodes in the list
void reverseList_c(node** head); // Reverse the linked list
void sortedList_c(node** head); // Sort the list based on PRN

int circular_sll() {
  printf("\n####### Welcome in Circular Single Linked List Program #######\n");
  node *head=NULL; // Initialize head of the list to NULL
  int choice;
  while(1) {
    // Display menu options
    printf("\n*****Menu*****\n");
    printf("1. insertAtEnd_c\n");
    printf("2. insertAtBeg_c\n");
    printf("3. insertAtPos_c\n");
    printf("4. displayList_c\n");
    printf("5. listNodeCount_c\n");
    printf("6. deleteFromEnd_c\n");
    printf("7. deleteFromBeg_c\n");
    printf("8. deleteFromPos_c\n");
    printf("9. deleteByElement_c\n");
    printf("10. reverseDisplay_c\n");
    printf("11. freeAllNode_c\n");
    printf("12. reverseList_c\n");
    printf("13. sortedList_c\n");
    printf("14. exit\n");
    printf("Your Choice-> ");
    scanf("%d",&choice); // Read user choice
    printf("\n");
  
    switch(choice) {
      case 1: insertAtEnd_c(&head); // Insert at end
              break;
      case 2: insertAtBeg_c(&head); // Insert at beginning
              break;
      case 3: insertAtPos_c(&head); // Insert at specified position
              break;
      case 4: displayList_c(head); // Display the list
              break;
      case 5: printf("Linked List has %d Nodes.\n",listNodeCount_c(head)); // Count nodes
              break;
      case 6: deleteFromEnd_c(&head); // Delete from end
              break;
      case 7: deleteFromBeg_c(&head); // Delete from beginning
              break;
      case 8: deleteFromPos_c(&head); // Delete from specified position
              break;
      case 9: deleteByElement_c(&head); // Delete by PRN
              break;
      case 10: reverseDisplay_c(head,head); // Display in reverse order
              break;
      case 11: freeAllNode_c(&head); // Free all nodes
              break;
      case 12: reverseList_c(&head); // Reverse the list
              break;
      case 13: sortedList_c(&head); // Sort the list
              break;
      case 14:
              freeAllNode_c(&head); // Free all nodes before exiting
              printf("Free all nodes...\nExiting Program...\n");
              return main();
              //exit(0); // Exit the program
              break;
      default:
              printf("Invalid Choice! Try Again...\n"); // Invalid choice
    }
  }

return 0;
}

// Create a new node and allocate memory for data
node* createNode_c() {
    node *newNode = (node*)malloc(sizeof(node)); // Allocate memory for the node
    if (!newNode) { // Check for memory allocation failure
        printf("Memory allocation failed for node!\n");
        exit(1);
    }

    newNode->data = (data*)malloc(sizeof(data)); // Allocate memory for student data
    if (!newNode->data) { // Check for memory allocation failure
        printf("Memory allocation failed for data!\n");
        free(newNode); // Free previously allocated memory
        exit(1);
    }

    // Input student details
    printf("Name-> ");
    getchar(); // Clear the newline from the input buffer
    scanf("%[^\n]s", newNode->data->name); // Read name
    
    printf("PRN-> ");
    scanf("%d", &(newNode->data->prn)); // Read PRN
    
    newNode->next = NULL; // Initialize next pointer to NULL
    return newNode; // Return the created node
}

// Check if the new node's PRN already exists in the list
int checkDuplicate_c(node* head, node* newNode) {
    if (head == NULL) {
        return 0; // If the list is empty, no duplicates
    }

    node* current = head; // Start traversal from the head
    do {
        if (current->data->prn == newNode->data->prn) { // Compare PRNs
            free(newNode->data); // Free memory for data
            free(newNode); // Free the node itself
            return 1; // Duplicate found
        }
        current = current->next; // Move to the next node
    } while (current != head); // Stop when we circle back to the head

    return 0; // No duplicate found
}


// Insert a node at the end of the list
void insertAtEnd_c(node** head) {
    node *newNode = createNode_c(); // Create a new node
    if (checkDuplicate_c(*head, newNode)) { // Check for duplicates
        printf("PRN is Duplicated! Insert failed..\n");
        return; // Exit if duplicate
    }
    if (*head == NULL) { // If the list is empty
        *head = newNode; // Set head to new node
        newNode->next = *head; // Point to itself
    } else {
        node *t1 = *head; // Traverse to the last node
        while (t1->next != *head)
            t1 = t1->next;
        t1->next = newNode; // Link the new node at the end
        newNode->next = *head; // Make it circular
    }
}

// Insert a node at the beginning of the list
void insertAtBeg_c(node** head) {
    node *newNode = createNode_c(); // Create a new node
    if (checkDuplicate_c(*head, newNode)) { // Check for duplicates
        printf("PRN is Duplicated! Insert failed..\n");
        return; // Exit if duplicate
    }

    if (*head == NULL) { // If the list is empty
        *head = newNode; // Set the new node as the head
        newNode->next = *head; // Point to itself to maintain circular structure
    } else {
        node *last = *head; // Find the last node
        while (last->next != *head) {
            last = last->next; // Traverse to the last node
        }
        newNode->next = *head; // Link new node to the current head
        last->next = newNode; // Update last node to point to new node
        *head = newNode; // Update head to new node
    }
}


// Insert a node at a specified position
void insertAtPos_c(node** head) {
    int pos, count = 1; // Position and counter for traversal
    int numberOfNodes = listNodeCount_c(*head); // Get current node count
    printf("Position-> ");
    scanf("%d", &pos); // Read desired position

    // Insert at the beginning
    if (pos == 1) { 
        insertAtBeg_c(head);
        return; // Exit after insertion
    }

    // Validate the position
    if (pos < 1 || pos > numberOfNodes + 1) {
        printf("Invalid Position! Try Again...\n");
        return; // Exit if position is invalid
    }

    // Insert at the end
    if (pos == numberOfNodes + 1) { 
        insertAtEnd_c(head);
        return; // Exit after insertion
    }

    // Create a new node
    node *newNode = createNode_c(); 
    if (checkDuplicate_c(*head, newNode)) { // Check for duplicates
        printf("PRN is Duplicated! Insert failed..\n");
        return; // Exit if duplicate
    }

    // Traverse to the desired position
    node *current = *head; 
    while (count < pos - 1) { 
        current = current->next;
        count++;
    }

    // Insert the new node
    newNode->next = current->next; // Link the new node to the next node
    current->next = newNode; // Update the current node's next to the new node
}


// Display the entire list
void displayList_c(node* head) {
    if (head == NULL) {
        printf("Linked List is empty!\n");
        return;
    }

    node *current = head; // Start from the head
    int i = 1; // Counter for display
    do {
        printf("***Student-%d***\n", i++);
        printf("Name-> %s\n", current->data->name);
        printf("PRN-> %d\n\n", current->data->prn);
        current = current->next; // Move to the next node
    } while (current != head); // Stop when we circle back to the head
}


// Count the number of nodes in the list
int listNodeCount_c(node* head) {
    if (head == NULL) { // Check if the list is empty
        return 0; // No nodes to count
    }

    int count = 0; // Initialize count
    node* current = head; // Start from the head

    do {
        count++; // Increment count
        current = current->next; // Move to the next node
    } while (current != head); // Stop when we circle back to the head

    return count; // Return total count
}


// Delete a node from the end of the list
void deleteFromEnd_c(node** head) {
    if (*head == NULL) { // Check if the list is empty
        printf("Linked List is empty!\n");
        return;
    }

    if ((*head)->next == *head) { // If there's only one node
        free((*head)->data); // Free the data
        free(*head); // Free the node
        *head = NULL; // Set head to NULL
        return;
    }

    node *current = *head; // Start from the head
    node *prev = NULL; // To track the previous node
    while (current->next != *head) { // Traverse to the last node
        prev = current;
        current = current->next;
    }
    free(current->data); // Free the data of the last node
    free(current); // Free the last node
    prev->next = *head; // Update the previous node's next pointer
}

// Delete a node from the beginning of the list
void deleteFromBeg_c(node** head) {
    if (*head == NULL) { // Check if the list is empty
        printf("Linked List is empty!\n");
        return;
    }

    node *temp = *head; // Temporary node to hold the head

    if (temp->next == *head) { // If there's only one node in the list
        free(temp->data); // Free the data
        free(temp); // Free the node
        *head = NULL; // Set head to NULL
    } else {
        // More than one node in the list
        node *last = *head; // Start from the head to find the last node
        while (last->next != *head) { // Traverse to the last node
            last = last->next;
        }
        *head = (*head)->next; // Move head to the next node
        last->next = *head; // Update the last node to point to the new head
        free(temp->data); // Free the data of the old head
        free(temp); // Free the old head node
    }
}


// Delete a node from a specified position
void deleteFromPos_c(node** head) {
    if (*head == NULL) { // Check if the list is empty
        printf("Linked List is empty!\n");
        return;
    }

    int pos, count = 1; // Position and counter for traversal
    int numberOfNodes = listNodeCount_c(*head); // Get current node count
    printf("Position-> ");
    scanf("%d", &pos); // Read desired position

    if (pos < 1 || pos > numberOfNodes) { // Check for valid position
        printf("Invalid Position! Try Again...\n");
        return;
    }

    if (pos == 1) { // If position is 1, delete from beginning
        deleteFromBeg_c(head);
    } else {
        node *current = *head; // Start from the head
        node *prev = NULL; // To track the previous node
        while (count < pos) { // Traverse to the desired position
            prev = current;
            current = current->next;
            count++;
        }

        // If deleting the last node
        if (current == *head) {
            // Find the last node
            node *last = *head;
            while (last->next != *head) {
                last = last->next;
            }
            last->next = current->next; // Update the last node to skip the current
        } else {
            prev->next = current->next; // Link previous node to next node
        }

        free(current->data); // Free the data of the node to be deleted
        free(current); // Free the node itself
    }
}


// Delete a node by its PRN
void deleteByElement_c(node** head) {
    if (*head == NULL) { // Check if the list is empty
        printf("The list is empty.\n");
        return;
    }

    int PRN; // Variable to hold the PRN to be deleted
    printf("PRN-> ");
    scanf("%d", &PRN); // Read PRN

    node *current = *head, *prev = NULL; // Pointers for traversal
    int found = 0; // Flag to check if PRN is found

    // Traverse the circular list to find the node with the specified PRN
    do {
        if (current->data->prn == PRN) {
            found = 1; // Mark as found
            break; // Exit the loop
        }
        prev = current; // Update previous node
        current = current->next; // Move to the next node
    } while (current != *head); // Continue until we circle back to the head

    if (!found) { // If PRN not found
        printf("PRN %d is not present in Linked List.\n", PRN);
        return;
    }

    // If the node to be deleted is the head
    if (current == *head) {
        // If there's only one node
        if (current->next == *head) {
            free(current->data); // Free the data
            free(current); // Free the node
            *head = NULL; // Set head to NULL
        } else {
            // If there are multiple nodes
            node *last = *head;
            while (last->next != *head) { // Find the last node
                last = last->next;
            }
            last->next = current->next; // Update last node to skip current
            *head = current->next; // Update head to the next node
            free(current->data); // Free the data
            free(current); // Free the node itself
        }
    } else {
        prev->next = current->next; // Link previous node to next node
        free(current->data); // Free the data of the node to be deleted
        free(current); // Free the node itself
    }
}


// Display the list in reverse order using recursion
void reverseDisplay_c(node* head,node* current) {
    if (current->next == head) {
        printf("***Student***\n");
        printf("Name-> %s\n", current->data->name); // Display name
        printf("PRN-> %d\n\n", current->data->prn); // Display PRN
        return; // Base case: we've looped back to the head
    }
    
    // Recursive call to reach the end of the list
    reverseDisplay_c(head, current->next);

    // Print the current node's data after returning from recursion
    printf("***Student***\n");
    printf("Name-> %s\n", current->data->name); // Display name
    printf("PRN-> %d\n\n", current->data->prn); // Display PRN
}

// Free all nodes in the list
void freeAllNode_c(node** head) {
    while (*head != NULL) { // Continue until the list is empty
        deleteFromBeg_c(head); // Delete from beginning
    }
}

// Reverse the circular linked list
void reverseList_c(node** head) {
    if (*head == NULL || (*head)->next == *head) { // Check if the list is empty or has one node
        return; // Nothing to reverse
    }

    node *current = *head; // Current node
    node *prev = NULL; // Previous node
    node *nextNode; // Temporary node for swapping

    do { // Traverse the list
        nextNode = current->next; // Store the next node
        current->next = prev; // Reverse the link
        prev = current; // Move prev to current
        current = nextNode; // Move to the next node
    } while (current != *head);

    // Final adjustment to link the last node back to the new head
    (*head)->next = prev; // Link the old head to the new head
    *head = prev; // Update head to the new front of the list
    printf("Linked List is Reversed.\n");
}


// Sort the circular linked list based on PRN using bubble sort
void sortedList_c(node** head) {
    if (*head == NULL || (*head)->next == *head) return; // Empty or single node list

    int swapped;
    node *current, *lastSorted = NULL;

    // Outer loop: keeps going until no swaps are made
    do {
        swapped = 0;
        current = *head;

        // Inner loop: traverse the circular linked list and perform swaps
        do {
            // Compare the PRNs of the current node and the next node
            if (current->data->prn > current->next->data->prn) {
                // Swap the data of the nodes instead of swapping nodes themselves
                data* temp = current->data;
                current->data = current->next->data;
                current->next->data = temp;

                swapped = 1; // Set swapped to 1 to indicate a swap was made
            }
            current = current->next; // Move to the next node
        } while (current->next != *head && current->next != lastSorted); // Avoid comparing the already sorted nodes

        // Update lastSorted: the node at the end of this pass is now sorted
        lastSorted = current;

    } while (swapped); // Repeat if any swaps were made

    printf("Circular Linked List is Sorted.\n");
}





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
node* createNode(); // Create a new node
int checkDuplicate(node* head, node* newNode); // Check for duplicate PRN
void insertAtEnd(node** head); // Insert a node at the end of the list
void insertAtBeg(node** head); // Insert a node at the beginning of the list
void insertAtPos(node** head); // Insert a node at a specified position
void displayList(node* head); // Display the entire list
int listNodeCount(node* head); // Count the number of nodes in the list
void deleteFromEnd(node** head); // Delete a node from the end of the list
void deleteFromBeg(node** head); // Delete a node from the beginning of the list
void deleteFromPos(node** head); // Delete a node from a specified position
void deleteByElement(node** head); // Delete a node by its PRN
void reverseDisplay(node* head); // Display the list in reverse order
void freeAllNode(node** head); // Free all nodes in the list
void reverseList(node** head); // Reverse the linked list
void sortedList(node** head); // Sort the list based on PRN

int single_linked_list() {
  printf("\n####### Welcome in Single Linked List Program #######\n");
  node *head=NULL; // Initialize head of the list to NULL
  int choice;
  while(1) {
    // Display menu options
    printf("\n*****Menu*****\n");
    printf("1. insertAtEnd\n");
    printf("2. insertAtBeg\n");
    printf("3. insertAtPos\n");
    printf("4. displayList\n");
    printf("5. listNodeCount\n");
    printf("6. deleteFromEnd\n");
    printf("7. deleteFromBeg\n");
    printf("8. deleteFromPos\n");
    printf("9. deleteByElement\n");
    printf("10. reverseDisplay\n");
    printf("11. freeAllNode\n");
    printf("12. reverseList\n");
    printf("13. sortedList\n");
    printf("14. exit\n");
    printf("Your Choice-> ");
    scanf("%d",&choice); // Read user choice
    printf("\n");
  
    switch(choice) {
      case 1: insertAtEnd(&head); // Insert at end
              break;
      case 2: insertAtBeg(&head); // Insert at beginning
              break;
      case 3: insertAtPos(&head); // Insert at specified position
              break;
      case 4: displayList(head); // Display the list
              break;
      case 5: printf("Linked List has %d Nodes.\n",listNodeCount(head)); // Count nodes
              break;
      case 6: deleteFromEnd(&head); // Delete from end
              break;
      case 7: deleteFromBeg(&head); // Delete from beginning
              break;
      case 8: deleteFromPos(&head); // Delete from specified position
              break;
      case 9: deleteByElement(&head); // Delete by PRN
              break;
      case 10: reverseDisplay(head); // Display in reverse order
              break;
      case 11: freeAllNode(&head); // Free all nodes
              break;
      case 12: reverseList(&head); // Reverse the list
              break;
      case 13: sortedList(&head); // Sort the list
              break;
      case 14:
              freeAllNode(&head); // Free all nodes before exiting
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
node* createNode() {
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
int checkDuplicate(node* head, node* newNode) {
    while (head != NULL) { // Traverse the list
        if (head->data->prn == newNode->data->prn) { // Compare PRNs
            free(newNode->data); // Free memory for data
            free(newNode); // Free the node itself
            return 1; // Duplicate found
        }
        head = head->next; // Move to the next node
    }
    return 0; // No duplicate found
}

// Insert a node at the end of the list
void insertAtEnd(node** head) {
    node *newNode = createNode(); // Create a new node
    if (checkDuplicate(*head, newNode)) { // Check for duplicates
        printf("PRN is Duplicated! Insert failed..\n");
        return; // Exit if duplicate
    }
    if (*head == NULL) { // If the list is empty
        *head = newNode; // Set head to new node
    } else {
        node *t1 = *head; // Traverse to the last node
        while (t1->next != NULL)
            t1 = t1->next;
        t1->next = newNode; // Link the new node at the end
    }
}

// Insert a node at the beginning of the list
void insertAtBeg(node** head) {
  node *newNode = createNode(); // Create a new node
  if (checkDuplicate(*head, newNode)) { // Check for duplicates
      printf("PRN is Duplicated! Insert failed..\n");
      return; // Exit if duplicate
  }
  newNode->next = *head; // Link new node to the old head
  *head = newNode; // Update head to new node
}

// Insert a node at a specified position
void insertAtPos(node** head) {
  int pos, count = 1; // Position and counter for traversal
  int numberOfNodes = listNodeCount(*head); // Get current node count
  printf("Position-> ");
  scanf("%d", &pos); // Read desired position

  if (pos == 1) { // If position is 1, insert at beginning
    insertAtBeg(head);
  } else if (pos < 1 || pos > numberOfNodes + 1) { // Check for valid position
    printf("Invalid Position! Try Again...\n");
  } else if (pos == numberOfNodes + 1) { // If position is at the end
    insertAtEnd(head);
  } else {
    node *newNode = createNode(); // Create a new node
    if (checkDuplicate(*head, newNode)) { // Check for duplicates
        printf("PRN is Duplicated! Insert failed..\n");
        return; // Exit if duplicate
    }
    node *current = *head; // Start from the head
    while (count < pos - 1) { // Traverse to the desired position
      current = current->next;
      count++;
    }
    newNode->next = current->next; // Link the new node
    current->next = newNode; // Insert the new node
  }
}

// Display the entire list
void displayList(node* head) {
    if (head == NULL) { // If the list is empty
        printf("Linked List is empty!\n");
        return;
    }

    int i = 1; // Counter for display
    while (head != NULL) { // Traverse the list
        printf("***Student-%d***\n", i++);
        printf("Name-> %s\n", head->data->name); // Display name
        printf("PRN-> %d\n\n", head->data->prn); // Display PRN
        head = head->next; // Move to the next node
    }
}

// Count the number of nodes in the list
int listNodeCount(node* head) {
 int count = 0; // Initialize count
 while (head != NULL) { // Traverse the list
 head = head->next; // Move to the next node
 count++; // Increment count
 }
 return count; // Return total count
}

// Delete a node from the end of the list
void deleteFromEnd(node** head) {
    if (*head == NULL) { // Check if the list is empty
        printf("Linked List is empty!\n");
        return;
    }

    if ((*head)->next == NULL) { // If there's only one node
        free((*head)->data); // Free the data
        free(*head); // Free the node
        *head = NULL; // Set head to NULL
        return;
    }

    node *current = *head; // Start from the head
    node *prev = NULL; // To track the previous node
    while (current->next != NULL) { // Traverse to the last node
        prev = current;
        current = current->next;
    }
    free(current->data); // Free the data of the last node
    free(current); // Free the last node
    prev->next = NULL; // Update the previous node's next pointer
}

// Delete a node from the beginning of the list
void deleteFromBeg(node** head) {
    if (*head == NULL) { // Check if the list is empty
        printf("Linked List is empty!\n");
        return;
    }

    node *temp = *head; // Temporary node to hold the head
    *head = (*head)->next; // Move head to the next node
    free(temp->data); // Free the data of the old head
    free(temp); // Free the old head node
}

// Delete a node from a specified position
void deleteFromPos(node** head) {
    if (*head == NULL) { // Check if the list is empty
        printf("Linked List is empty!\n");
        return;
    }

    int pos, count = 1; // Position and counter for traversal
    int numberOfNodes = listNodeCount(*head); // Get current node count
    printf("Position-> ");
    scanf("%d", &pos); // Read desired position

    if (pos < 1 || pos > numberOfNodes) { // Check for valid position
        printf("Invalid Position! Try Again...\n");
        return;
    }

    if (pos == 1) { // If position is 1, delete from beginning
        deleteFromBeg(head);
    } else {
        node *current = *head; // Start from the head
        node *prev = NULL; // To track the previous node
        while (count < pos) { // Traverse to the desired position
            prev = current;
            current = current->next;
            count++;
        }
        prev->next = current->next; // Link previous node to next node
        free(current->data); // Free the data of the node to be deleted
        free(current); // Free the node itself
    }
}

// Delete a node by its PRN
void deleteByElement(node** head) {
    if (*head == NULL) { // Check if the list is empty
        printf("The list is empty.\n");
        return;
    }

    int PRN; // Variable to hold the PRN to be deleted
    printf("PRN-> ");
    scanf("%d", &PRN); // Read PRN

    node *current = *head, *prev = NULL; // Pointers for traversal

    while (current != NULL && current->data->prn != PRN) { // Traverse to find the node
        prev = current;
        current = current->next;
    }

    if (current == NULL) { // If PRN not found
        printf("PRN %d is not present in Linked List.\n", PRN);
        return;
    }

    if (prev == NULL) { // If the node to be deleted is the head
        deleteFromBeg(head);
    } else {
        prev->next = current->next; // Link previous node to next node
        free(current->data); // Free the data of the node to be deleted
        free(current); // Free the node itself
    }
}

// Display the list in reverse order using recursion
void reverseDisplay(node* head) {
    if (head == NULL) { // If the list is empty
        printf("Linked List is empty!\n");
        return;
    }

    // Recursive call to reach the end of the list
    if (head->next != NULL) {
        reverseDisplay(head->next);
    }

    // Print the current node's data after returning from recursion
    printf("***Student***\n");
    printf("Name-> %s\n", head->data->name); // Display name
    printf("PRN-> %d\n\n", head->data->prn); // Display PRN
}

// Free all nodes in the list
void freeAllNode(node** head) {
    while (*head != NULL) { // Continue until the list is empty
        deleteFromBeg(head); // Delete from beginning
    }
}

// Reverse the linked list
void reverseList(node** head) {
    if ((*head == NULL) || ((*head)->next == NULL)) { // Check if the list is empty or has one node
      return; // Nothing to reverse
    }
    node *t1 = *head; // Current node
    node *t2 = NULL; // Previous node
    node *t3; // Temporary node for swapping

    while (t1 != NULL) { // Traverse the list
      t3 = t2; // Swap pointers
      t2 = t1;
      t1 = t1->next;
      t2->next = t3; // Reverse the link
    }
    *head = t2; // Update head to the new front of the list
    printf("Linked List is Reversed.\n");
}

// Sort the list based on PRN using bubble sort
void sortedList(node** head) {
    if (*head == NULL) { // Check if the list is empty
        printf("The list is empty.\n");
        return;
    }
    
    if ((*head)->next == NULL) { // No need to sort a single element
        return; 
    }
    
    int swapflag; // Flag to indicate if a swap occurred
    node *t1, *x = NULL; // t1 for traversal, x for last sorted node

    do {
        swapflag = 0; // Reset swap flag
        t1 = *head; // Start from the head

        while (t1->next != x) { // Traverse until the last sorted node
            if (t1->data->prn > t1->next->data->prn) { // Compare PRNs
                // Swap the data pointers, not the actual data
                data* temp = t1->data; // Temporary pointer for swap
                t1->data = t1->next->data; // Swap data
                t1->next->data = temp; 
                
                swapflag = 1; // A swap occurred
            }
            t1 = t1->next; // Move to the next node
        }
        x = t1; // Update last sorted node
    } while (swapflag); // Repeat until no swaps occur
    printf("Linked List is Sorted.\n");
}


#include <stdio.h>
#include <stdlib.h>

// Function prototypes for queue operations
int main();
void inqueue_q(int *queue, int *front, int *rear, int element, int size);
void dqueue_q(int *queue, int *front, int *rear);
void peep_q(int *queue, int front);
void display_q(int *queue, int front, int rear);

int queue() {
    printf("\n####### Welcome in Queue Program #######\n");
    int choice, size, front = -1, rear = -1, element; // Initialize queue variables
    printf("Give queue size-> "); // Prompt user for queue size
    scanf("%d", &size);
    int *queue = (int *)malloc(size * sizeof(int)); // Allocate memory for the queue
    if (queue == NULL) { // Check for memory allocation failure
        printf("Memory allocation failed.\n");
        return 1; // Exit if memory allocation fails
    }
    
    while (1) { // Infinite loop for menu display_q and choice handling
        printf("\n*****Menu*****\n");
        printf("1. inqueue_q\n");
        printf("2. dqueue_q\n");
        printf("3. peep_q\n");
        printf("4. display_q\n");
        printf("5. exit\n");
        printf("Your Choice-> ");
        scanf("%d", &choice); // Get user choice
        
        switch (choice) { // Handle user choice
            case 1: // Insertion operation
                printf("Give element to inqueue_q in queue-> "); // Prompt for element to enqueue
                scanf("%d", &element);
                inqueue_q(queue, &front, &rear, element, size); // Call enqueue function
                break;
            case 2: // Deletion operation
                dqueue_q(queue, &front, &rear); // Call dequeue function
                break;
            case 3: // Peeking operation
                peep_q(queue, front); // Call peep_q function
                break;
            case 4: // display_q operation
                display_q(queue, front, rear); // Call display_q function
                break;
            case 5: // Exit operation
                free(queue); // Free allocated memory
                return main();
                //return 0; // Exit program
            default: // Invalid choice
                printf("Wrong Choice! Try again..\n");
        }
    }
}

// Function to insert an element into the queue
void inqueue_q(int *queue, int *front, int *rear, int element, int size) {
    if (*rear == size - 1) { // Check if queue is full
        printf("Queue is full.\n");
        return; // Exit if queue is full
    }
    queue[++(*rear)] = element; // Add the element to the queue
    if (*front == -1) *front = 0; // Set front if it's the first element
}

// Function to remove an element from the queue
void dqueue_q(int *queue, int *front, int *rear) {
    if (*front == -1) { // Check if queue is empty
        printf("Queue is empty.\n");
        return; // Exit if queue is empty
    }
    int dequeuedElement = queue[*front]; // Store the element to be dequeued
    printf("Dequeued element is: %d\n", dequeuedElement); // Output the dequeued element
    if (*front == *rear) { // Check if the queue is now empty after dequeue
        *front = -1; // Reset front and rear
        *rear = -1;
    } else {
        (*front)++; // Move front pointer forward
    }
}

// Function to peek at the front element of the queue
void peep_q(int *queue, int front) {
    if (front == -1) { // Check if queue is empty
        printf("Queue is empty.\n");
        return; // Exit if queue is empty
    }
    printf("Queue peep_q is %d.\n", queue[front]); // Output the front element
}

// Function to display_q the contents of the queue
void display_q(int *queue, int front, int rear) {
    if (front == -1) { // Check if queue is empty
        printf("Queue is empty.\n");
        return; // Exit if queue is empty
    }
    printf("Your Queue is-> "); // Prompt for queue contents
    for (int i = front; i <= rear; i++) { // Loop through queue elements
        printf("| %d ", queue[i]); // Print each element
    }
    printf("|\n"); // End the queue display_q
}


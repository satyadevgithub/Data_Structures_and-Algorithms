#include <stdio.h>
#include <stdlib.h>

// Function prototypes for queue operations
int main();
void inqueue(int *queue, int *front, int *rear, int element, int size);
void dqueue(int *queue, int *front, int *rear,int size);
void peep_cq(int *queue, int front);
void display_cq(int *queue, int front, int rear,int size);

int circular_queue() {
    printf("\n####### Welcome in Circular Queue Program #######\n");
    int choice, size, front = -1, rear = -1, element; // Initialize variables for queue
    printf("Give queue size-> "); // Prompt user for size of the queue
    scanf("%d", &size);
    int *queue = (int *)malloc(size * sizeof(int)); // Allocate memory for the queue
    for(int i=0;i<size;i++){ // Initialize all elements to -1
      queue[i]=-1;
    }
    if (queue == NULL) { // Check for memory allocation failure
        printf("Memory allocation failed.\n");
        return 1; // Exit if allocation fails
    }
    
    while (1) { // Infinite loop for menu display_cq and choice handling
        printf("\n*****Menu*****\n");
        printf("1. inqueue\n");
        printf("2. dqueue\n");
        printf("3. peep_cq\n");
        printf("4. display_cq\n");
        printf("5. exit\n");
        printf("Your Choice-> ");
        scanf("%d", &choice); // Get user choice
        
        switch (choice) { // Handle user choice
            case 1: // Insertion operation
                printf("Give element to inqueue in queue-> "); // Prompt for element to enqueue
                scanf("%d", &element);
                inqueue(queue, &front, &rear, element, size); // Call enqueue function
                break;
            case 2: // Deletion operation
                dqueue(queue, &front, &rear,size); // Call dequeue function
                break;
            case 3: // Peeking operation
                peep_cq(queue, front); // Call peep_cq function
                break;
            case 4: // display_cq operation
                display_cq(queue, front, rear,size); // Call display_cq function
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
void inqueue(int *queue, int *front, int *rear, int element, int size) {
    // Check if the queue is full
    if ((*rear + 1) % size == *front) {
        printf("Queue is full.\n"); // Notify if the queue is full
        return; // Exit if queue is full
    }
    
    // If queue is empty, initialize front and rear
    if (*front == -1) {
        *front = 0; // Set front to the first position
        *rear = 0; // Set rear to the first position
    } else {
        // Move rear to the next position in a circular manner
        *rear = (*rear + 1) % size; // Update rear index
    }
    
    // Insert the element at the rear position
    queue[*rear] = element; 
}

// Function to remove an element from the queue
void dqueue(int *queue, int *front, int *rear,int size) {
    if (*front == -1) { // Check if queue is empty
        printf("Queue is empty.\n"); // Notify if the queue is empty
        return; // Exit if queue is empty
    }
    int dequeuedElement = queue[*front]; // Store the element to be dequeued
    queue[*front]=-1; // Mark the dequeued position as -1
    printf("Dequeued element is: %d\n", dequeuedElement); // Output the dequeued element
    if (*front == *rear) { // Check if the queue is now empty
        *front = -1; // Reset front and rear
        *rear = -1;
    } else {
        // Move front to the next position in a circular manner
        *front = (*front + 1) % size; // Update front index
    }
}

// Function to peek at the front element of the queue
void peep_cq(int *queue, int front) {
    if (front == -1) { // Check if queue is empty
        printf("Queue is empty.\n"); // Notify if the queue is empty
        return; // Exit if queue is empty
    }
    printf("Queue peep_cq is %d.\n", queue[front]); // Output the front element
}

// Function to display_cq the contents of the queue
void display_cq(int *queue, int front, int rear,int size) {
    if (front == -1) { // Check if queue is empty
        printf("Queue is empty.\n"); // Notify if the queue is empty
        return; // Exit if queue is empty
    }
    printf("Your Queue is-> "); // Prompt for queue contents
    for (int i = 0; i < size; i++) { // Loop through all elements in the queue
        printf("| %d ", queue[i]); // Print each element
    }
    printf("|\n"); // End the queue display_cq
    printf("'-1' is NULL element in above circular queue.\n"); // Indicate unused positions
}


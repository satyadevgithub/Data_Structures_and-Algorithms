#include<stdio.h>
#include<stdlib.h>
#include<string.h>

// Function prototypes for stack operations
int main();
void push_s(int *stack,int *top, int element,int size);
void pop_s(int *stack,int *top);
void peep_s(int *stack,int top);
void display_s(int *stack,int top);

int stack(){
  printf("\n####### Welcome in Stack Program #######\n");
  int choice,size,top=-1,element; // Initialize variables for stack
  printf("Give stack size-> "); // Prompt user for size of the stack
  scanf("%d",&size);
  int *stack=(int*)malloc(size*sizeof(int)); // Allocate memory for the stack
  while(1){ // Infinite loop for menu display_s and choice handling
    printf("\n*****Menu*****\n");
    printf("1. push_s\n"); // Option to push_s an element onto the stack
    printf("2. pop_s\n"); // Option to pop_s an element from the stack
    printf("3. peep_s\n"); // Option to peek at the top element of the stack
    printf("4. display_s\n"); // Option to display_s all elements in the stack
    printf("5. exit\n"); // Option to exit the program
    printf("Your Choice-> ");
    scanf("%d",&choice); // Get user choice
    printf("\n");
    switch(choice){ // Handle user choice
      case 1: // push_s operation
        printf("Give element to push_s in stack-> "); // Prompt for element to push_s
        scanf("%d",&element);
        push_s(stack,&top,element,size); // Call push_s function
        break;
      case 2: // pop_s operation
        pop_s(stack,&top); // Call pop_s function
        break;
      case 3: // peep_s operation
        peep_s(stack,top); // Call peep_s function
        break;
      case 4: // display_s operation
        display_s(stack,top); // Call display_s function
        break;
      case 5: // Exit operation
        free(stack); // Free allocated memory for the stack
        return main();
        //exit(0); // Exit program
      default : // Invalid choice
        printf("Wrong Choice! Try again..\n");
    }
  }
}

// Function to push_s an element onto the stack
void push_s(int *stack,int *top, int element,int size){
  if(*top==size-1) { // Check if the stack is full
    printf("Stack is full.\n"); // Notify if the stack is full
    return; // Exit if stack is full
  }
  *top+=1; // Increment top index
  stack[*top]=element; // Insert the element at the top of the stack
}

// Function to pop_s an element from the stack
void pop_s(int *stack,int *top){
  if(*top==-1){ // Check if the stack is empty
    printf("Stack is empty.\n"); // Notify if the stack is empty
    return; // Exit if stack is empty
  }
  stack[*top]=0; // Optionally reset the pop_sped position (not strictly necessary)
  *top-=1; // Decrement top index
}

// Function to peek at the top element of the stack
void peep_s(int *stack,int top){
  if(top==-1){ // Check if the stack is empty
    printf("Stack is empty.\n"); // Notify if the stack is empty
    return; // Exit if stack is empty
  }
  printf("Stack peep_s is %d.\n",stack[top]); // Output the top element
}

// Function to display_s all elements in the stack
void display_s(int *stack,int top){
  if(top==-1){ // Check if the stack is empty
    printf("Stack is empty.\n"); // Notify if the stack is empty
    return; // Exit if stack is empty
  }
  int i=0; // Initialize index for display_sing stack elements
  while(i<=top){ // Loop through elements from bottom to top
    printf("| %d ",stack[i++]); // Print each element
  }
  printf("|\n"); // End the stack display_s
}


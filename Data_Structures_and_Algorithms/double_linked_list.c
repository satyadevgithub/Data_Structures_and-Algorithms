//library include
#include <stdio.h>
#include<stdlib.h>
#include<string.h>

 //structure define
typedef  struct student_record_management_system {
    struct student_record_management_system *pre;
    char name[50];
    int rollNumber;
    int marks;
    char contact[50];
    struct student_record_management_system *next;
} node;

//function prototype
int main();
node* create_node_dll(node *head); //create new node
void add_student_info(node **head);
void display_all_student_info(node *head);
void search_student_info(node *head);
void delete_student_info(node **head);
void update_student_info(node **head);
int check_unique_roll_num(node *head,int roll_num); //check roll-number is unique or not
void free_all_nodes_dll(node **head); //free all dma memory

//main function
int double_linked_list(){
    printf("\n####### Welcome in Double Linked List Program #######\n");
    node *head=NULL; //creat head for dll

    int choice;

    //make menu for student_record_management_system
    while(1){
        printf("\nStudent Record Management System\n");
        printf("*******Menu*******\n");
        printf("1. add a student\n");
        printf("2. search for a student\n");
        printf("3. update student information\n");
        printf("4. delete student information\n");
        printf("5. display all student information\n");
        printf("6. exit\n");
        printf("Your choice-> ");
        scanf("%d",&choice);
        printf("\n");

        //function call based on user choice
        switch(choice){
            case 1: add_student_info(&head);
                    break;
            case 2: search_student_info(head);
                    break;
            case 3: update_student_info(&head);
                    break;
            case 4: delete_student_info(&head);
                    break;
            case 5: display_all_student_info(head);
                    break;
            case 6: //before exiting program first free all memory
                    free_all_nodes_dll(&head);
                    printf("all dynamic allocated memory is free..\nexiting....\n*****thanku*****\n");
                    return main();
                    //exit(0);

            default: printf("wrong choice! try again..\n");
        }

    }
    return 0;
}

node* create_node_dll(node *head){
    node *new_node=(node *)malloc(sizeof(node)); //allocate memory
    if(!new_node){ //check memory allocation successful or not
        printf("memory not allocated\n");
        exit(1);
    }
    int rollNumber;
    //taking student data
    printf("student roll number-> ");
    scanf("%d",&rollNumber);
    if(check_unique_roll_num(head,rollNumber)){
        new_node->rollNumber=rollNumber;
    } else {
         printf("roll number is not unique!try again\n");
         free(new_node);
         return create_node_dll(head);
     }
    
    printf("student name-> ");
    getchar(); //prevent error in taking student name input
    scanf("%[^\n]s",new_node->name);

    printf("student marks-> ");
    scanf("%d",&(new_node->marks));

    printf("student contact-> ");
    getchar(); //prevent error in taking student name input
    scanf("%[^\n]s",new_node->contact);

    new_node->next=NULL;
    new_node->pre=NULL;

    return new_node;
}

void add_student_info(node **head) {
    // create a new student info
    node *new_node = create_node_dll(*head);
    
    // If list is empty add the node as the head
    if (*head == NULL) {
        *head = new_node;
        new_node->next = new_node; // point to itself 
        new_node->pre = new_node; // Point to itself 
        return;
    }

    // add the new node in sorted order
    node *current = *head;
    node *prev = NULL;

    // taverse the list to find the correct position
    do {
        prev = current;
        current = current->next;

        // if the new roll number is less than the current node's roll number
        // insert the new node before the current node
        if (new_node->rollNumber < current->rollNumber) {
            break;
        }
    } while (current != *head);

    // if inserting at the beginning
    if (current == *head) {
        // update the head to the new node
        new_node->next = *head;
        new_node->pre = prev;
        prev->next = new_node;
        current->pre = new_node;
        *head = new_node; // update head to new node
    } else {
        // insert between prev and current
        new_node->next = current;
        new_node->pre = prev;
        prev->next = new_node;
        current->pre = new_node;
    }
}

void display_all_student_info(node *head) {
    if (head == NULL) { //no data is available
        printf("No student records available.\n");
        return;
    }

    node *current = head;

    //print student records
    printf("***** Student Records *****\n");
    do {
        printf("\n");
        printf("Roll Number: %d\n", current->rollNumber);
        printf("Name: %s\n", current->name);
        printf("Marks: %d\n", current->marks);
        printf("Contact: %s\n", current->contact);
        printf("\n");
        current = current->next;
    } while (current != head);

    printf("***** End of Records *****\n");
}


void search_student_info(node *head) {
    if (head == NULL) {
        printf("No student records available to search.\n");
        return;
    }
    
    //user choice of search by roll number or name
    int choice;
    printf("Search by:\n");
    printf("1. Roll Number\n");
    printf("2. Name\n");
    printf("Your choice-> ");
    scanf("%d", &choice);
    getchar(); 
    //search by roll number
    if (choice == 1) {
        int rollNumber;
        printf("Enter the roll number to search: ");
        scanf("%d", &rollNumber);

        node *current = head;
        int found = 0;

        
        do {
            if (current->rollNumber == rollNumber) {
                found = 1;
                printf("Student found:\n");
                printf("Roll Number: %d\n", current->rollNumber);
                printf("Name: %s\n", current->name);
                printf("Marks: %d\n", current->marks);
                printf("Contact: %s\n", current->contact);
                break;
            }
            current = current->next;
        } while (current != head);

        if (!found) {
            printf("Student with Roll Number %d not found.\n", rollNumber);
        }
    } else if (choice == 2) { //search by name
        char name[50];
        printf("Enter the name to search: ");
        scanf("%[^\n]s", name);

        node *current = head;
        int found = 0;

        // traverse the list 
        do {
            if (strcmp(current->name, name) == 0) {
                found = 1;
                printf("Student found:\n");
                printf("Roll Number: %d\n", current->rollNumber);
                printf("Name: %s\n", current->name);
                printf("Marks: %d\n", current->marks);
                printf("Contact: %s\n", current->contact);
                break;
            }
            current = current->next;
        } while (current != head);

        if (!found) {
            printf("Student with Name '%s' not found.\n", name);
        }
    } else {
        printf("Invalid choice. Please try again.\n");
    }
}

void delete_student_info(node **head) {
    if (*head == NULL) {
        printf("No student records available to delete.\n");
        return;
    }

    int rollNumber;
    printf("Enter the roll number of the student you want to delete: ");
    scanf("%d", &rollNumber);

    node *current = *head;
    int found = 0;

    // traverse the list 
    do {
        if (current->rollNumber == rollNumber) {
            found = 1;
            printf("Deleting information for Roll Number: %d\n", current->rollNumber);

            //  the node  is the only node in the list
            if (current->next == current) {
                free(current);
                *head = NULL; 
            } else {
                
                current->pre->next = current->next;
                current->next->pre = current->pre;

                
                if (current == *head) {
                    *head = current->next; 
                }
                free(current); // Free the memory
            }
            printf("Student information deleted successfully.\n");
            break; 
        }
        current = current->next;
    } while (current != *head);

    if (!found) {
        printf("Student with Roll Number %d not found.\n", rollNumber);
    }
}

void update_student_info(node **head) {
    if (*head == NULL) {
        printf("No student records available to update.\n");
        return;
    }

    int rollNumber;
    printf("Enter the roll number of the student you want to update: ");
    scanf("%d", &rollNumber);

    node *current = *head;
    int found = 0;

    // traverse the list to find the student with the given roll number
    do {
        if (current->rollNumber == rollNumber) {
            found = 1;
            printf("Updating information for Roll Number: %d\n", current->rollNumber);

            // update marks
            printf("Enter new marks: ");
            scanf("%d", &(current->marks));

            // update contact
            printf("Enter new contact: ");
            getchar(); 
            scanf("%[^\n]s", current->contact);

            printf("student information updated successfully.\n");
            break; 
        }
        current = current->next;
    } while (current != *head);

    if (!found) {
        printf("student with Roll Number %d not found.\n", rollNumber);
    }
}

int check_unique_roll_num(node *head, int roll_num){
    node *current=head;
    if(current==NULL){
        return 1;
    }
    do{
        if(current->rollNumber==roll_num){
            return 0;
         }
         current=current->next;
    }while(current!=head);
    return 1;
}

void free_all_nodes_dll(node **head) {
    if (*head == NULL) {
        return; // head is null
    }

    node *current = *head;
    node *next_node;

    // traverse the list and free each node
    do {
        next_node = current->next; 
        free(current); // free the current node
        current = next_node; 
    } while (current != *head); 
    *head = NULL; //  head to NULL set
}

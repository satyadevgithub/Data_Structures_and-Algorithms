#include<stdio.h>
#include<stdio.h>
#include<stdlib.h>
#include"dsa.h"


int main(){
  printf("\n####### Welcome in Main Program #######\n");
  int choice;
  while(1) {
    // Display menu options
    printf("\n*****Menu*****\n");
    printf("1. Array\n");
    printf("2. Stack\n");
    printf("3. Queue\n");
    printf("4. Circular Queue\n");
    printf("5. Tree\n");
    printf("6. AVL Tree\n");
    printf("7. Single Linked List\n");
    printf("8. Circular Single Linked List\n");
    printf("9. Double Linked List\n");
    /*printf("10. \n");
    printf("11. \n");
    printf("12. \n");
    printf("13. \n");*/
    printf("10. exit\n");
    printf("Your Choice-> ");
    scanf("%d",&choice); // Read user choice
    printf("\n");
  
    switch(choice) {
      case 1: array(); 
              break;
      case 2: stack(); 
              break;
      case 3: queue(); 
              break;
      case 4: circular_queue(); 
              break;
      case 5: Tree(); 
              break;
      case 6: avl_tree();
              break;
      case 7: single_linked_list(); 
              break;
      case 8: circular_sll(); 
              break;
      case 9: double_linked_list();
              break;
      
      /*case 10: reverseDisplay(head); // Display in reverse order
              break;
      case 11: freeAllNode(&head); // Free all nodes
              break;
      case 12: reverseList(&head); // Reverse the list
              break;
      case 13: sortedList(&head); // Sort the list
              break;*/
      case 10: printf("####### Thanku #######\n\n");
              exit(0); // Exit the program
              break;
      default:
              printf("Invalid Choice! Try Again...\n"); // Invalid choice
    }
  }
  
return 0;
}

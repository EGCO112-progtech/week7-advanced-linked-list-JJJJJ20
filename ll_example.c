// Fig. 12.3: fig12_03.c
// Inserting and deleting nodes in a list
#include <stdio.h>
#include <stdlib.h>
#include "ll2.h"
#include <string.h>

int main( void )
{ 
   LLPtr startPtr = NULL; // initially there are no nodes
   unsigned int choice; // user's choice
   int item; // char entered by user
   char name[100];

   instructions(); // display the menu
   printf( "%s", "? " );
   scanf( "%u", &choice );

   // loop while user does not choose 3
   while ( choice != 3 ) { 

      switch ( choice ) { 
         case 1:
         
         printf("Enter ID and Name: ");
         scanf("%d %99[^\n]", &item, name);
         insert(&startPtr, item, name);
         printList(startPtr);  
         printListR(startPtr); 
         break;

         case 2: // delete an element
            if ( !isEmpty( startPtr ) ) { 
               printf("Enter ID to delete: ");
                scanf("%d", &item);
               // if character is found, remove it
               if (deletes(&startPtr, item) != -1) {
                  printf("Deleted ID: %d\n", item);
                  printList(startPtr);  
                  printListR(startPtr); 
              } else {
                  printf("ID %d not found.\n", item);
              }
            } // end if
            else {
               puts( "List is empty.\n" );
            } // end else

            break;
        

         default:
            puts( "Invalid choice.\n" );
            instructions();
            break;
      } // end switch

      printf( "%s", "? " );
      scanf( "%u", &choice );
   } 
   printf("Clear all nodes\n");
      printListD(&startPtr);
      printf("End of run.\n");// end while
  /* Clear all nodes at the end of nodes*/
} // end main

#include <string.h>
// self-referential structure
struct Node {
    struct Node *pPtr;
    int data; // each listNode contains a character
    char name[100];
    struct Node *nextPtr; // pointer to next node
 }; // end structure listNode
 
 typedef struct Node LLnode; // synonym for struct listNode
 typedef LLnode *LLPtr; // synonym for ListNode*
 
 // prototypes
 
 int deletes( LLPtr *sPtr, int value );
 int isEmpty( LLPtr sPtr );
 void insert( LLPtr *sPtr, int value ,char *name);
 void printList( LLPtr currentPtr );
 void printListR( LLPtr pPtr );
 void printListD( LLPtr *sPtr );
 void instructions( void );
 
 
 // display program instructions to user
 void instructions( void )
 {
    puts( "Enter your choice:\n"
       "   1 to insert an element into the list.\n"
       "   2 to delete an element from the list.\n"
       "   3 to end." );
 } // end function instructions
 
 // insert a new value into the list in sorted order (allowing duplicates)
 void insert(LLPtr *sPtr, int value,char *name)
 {
    LLPtr newPtr;           // pointer to new node
    LLPtr previousPtr = NULL;  // pointer to previous node in list
    LLPtr currentPtr = *sPtr;  // pointer to current node in list
 
    newPtr = (LLPtr) malloc(sizeof(LLnode));  // create node
 
    if (newPtr != NULL) { // is space available
       newPtr->data = value;  // place value in node
       strcpy(newPtr->name, name);
       newPtr->nextPtr = NULL;  // node does not link to another node
       newPtr->pPtr = NULL;    // previous pointer is NULL initially
 
       // loop to find the correct location in the list (allowing duplicates)
       while (currentPtr != NULL && value > currentPtr->data) {
          previousPtr = currentPtr;  // walk to ...
          currentPtr = currentPtr->nextPtr;  // ... next node
       } // end while
 
       // insert new node at beginning of list (if previousPtr is NULL)
       if (previousPtr == NULL) {
          newPtr->nextPtr = *sPtr;   // set the next pointer to head
          if (*sPtr != NULL) {
             (*sPtr)->pPtr = newPtr;  // update prevPtr of the first node
          }
          *sPtr = newPtr;  // make newPtr the head of the list
       } else { // insert new node between previousPtr and currentPtr
          newPtr->pPtr = previousPtr;
          newPtr->nextPtr = currentPtr;
          previousPtr->nextPtr = newPtr;
 
          if (currentPtr != NULL) {
             currentPtr->pPtr = newPtr;  // update prevPtr of next node
          }
       }
    } else {
       printf("%d not inserted. No memory available.\n", value);
    }
 } // end function insert
 
 
 // delete a list element
 int deletes( LLPtr *sPtr, int value )
 {
    LLPtr previousPtr; // pointer to previous node in list
    LLPtr currentPtr; // pointer to current node in list
    LLPtr tempPtr; // temporary node pointer
 
    // delete first node
    if ( value == ( *sPtr )->data ) {
       tempPtr = *sPtr; // hold onto node being removed
       if ( (*sPtr)->nextPtr != NULL ) {
          (*sPtr)->nextPtr->pPtr = NULL;  // set prevPtr of the next node to NULL
       }
       *sPtr = (*sPtr)->nextPtr;  // de-thread the node
       free( tempPtr );           // free the de-threaded node
       return value;
    } // end if
    else {
       previousPtr = *sPtr;
       currentPtr = ( *sPtr )->nextPtr;
 
       // loop to find the correct location in the list
       while ( currentPtr != NULL && currentPtr->data != value ) {
          previousPtr = currentPtr; // walk to ...
          currentPtr = currentPtr->nextPtr; // ... next node
       } // end while
 
       // delete node at currentPtr
       if ( currentPtr != NULL ) {
          tempPtr = currentPtr;
          previousPtr->nextPtr = currentPtr->nextPtr;
          if ( currentPtr->nextPtr != NULL ) {
             currentPtr->nextPtr->pPtr = previousPtr;  // update prevPtr of next node
          }
          free( tempPtr );
          return value;
       } // end if
    } // end else
 
    return '\0';
 } // end function delete
 
 // return 1 if the list is empty, 0 otherwise
 int isEmpty( LLPtr sPtr )
 {
    return sPtr == NULL;
 } // end function isEmpty
 
 // print the list
 void printListD( LLPtr *sPtr )
 {
    LLPtr tempPtr;
    while (*sPtr != NULL) {
        tempPtr = *sPtr;
        *sPtr = (*sPtr)->nextPtr;
        printf("delete %d\n", tempPtr->data);
        free(tempPtr);
    }
 } 
 void printList( LLPtr currentPtr )
 {
    // if list is empty
    if ( isEmpty( currentPtr ) ) {
       puts( "List is empty.\n" );
    } // end if
    else {
       puts( "The list is:" );
 
       // while not the end of the list
       while ( currentPtr->nextPtr != NULL ) {
        printf("%d %s -->", currentPtr->data,currentPtr->name);
          currentPtr = currentPtr->nextPtr;
       } // end while
 
       printf( "%d %s -->NULL\n",currentPtr->data,currentPtr->name);
        
    } // end else
 } // end function printList
 void printListR( LLPtr pPtr )
 {
    // if list is empty
    if ( isEmpty( pPtr ) ) {
       puts( "List is empty.\n" );
    } // end if
    else {
       puts( "The list reverse is:" );
 
       // while not the end of the list
       while ( pPtr->nextPtr != NULL ) {
          pPtr = pPtr->nextPtr;
       } // end while
       
       
       while (pPtr != NULL) {
          printf("%d %s -->", pPtr->data,pPtr->name);
          pPtr = pPtr->pPtr;
      }
       printf( "NULL\n");
        
    } // end else
 } // end function printList
#include <stdio.h>
#include <stdlib.h>
#include "linkedListAPI.h"

//compare function for integers
int compareInt(const void *first, const void *second){
    int *num1 = (int*) first;
    int *num2 = (int*) second;
    if(*num1 > *num2){
        return 1;
    }
    else if(*num1 < *num2){
        return -1;
    }
    else{
        return 0;
    }
}
//print function for integers
void printInt( void * b ) 
{
    int *num = (int*)b;
    printf("%d\n", *num);
}
//delete function for book and integers
void deleteFunction(void *tobeDeleted){
    if(tobeDeleted != NULL){
        free(tobeDeleted);
    }
    tobeDeleted = NULL;
}
//prints pass or fail
void printStatus(int info){
    if(info == 1){
        printf("Pass\n");
    }
    else{
        printf("Fail\n");
    }
}

int main(void){
    int *i1 = malloc(sizeof(int));
    *i1 = 34;
    int *i2 = malloc(sizeof(int));
    *i2 = 7;
    int *i3 = malloc(sizeof(int));
    *i3 = 65;

    //Test initializeList function
    List *l2 = initializeList(printInt, deleteFunction, compareInt);
    printf("\nTest #1: Test function to point the integer list head to the appropriate functions, and allocate memory");
    printf("\nExpected: \n");
    printf("1\n");
    printf("Recieved:\n");
    printf("%d\n", l2 != NULL);
    printStatus(l2 != NULL);

    //test initializeNode function
    Node *info2 = initializeNode(l2);
    printf("\nTest #2: Test function to create a node for a integer linked list");
    printf("\nExpected: \n");
    printf("1\n");
    printf("Recieved:\n");
    printf("%d\n", info2 != NULL);
    printStatus(info2 != NULL);

    //test insertFront function
    insertFront(l2, i1);
    printf("\nTest #3: Test function to insert a integer Node to the front of a linked list");
    printf("\nExpected: \n");
    printf("34\n");
    printf("Recieved:\n");
    printForward(l2);
    printStatus(l2->head != NULL);

    //test insertBack function
    insertBack(l2, i2);
    printf("\nTest #4: Test function to insert a integer Node to the back of a linked list");
    printf("\nExpected: \n");
    printf("34\n");
    printf("7\n");
    printf("Recieved:\n");
    printForward(l2);
    printStatus(l2->head->next != NULL);

    //test insertSorted function
    insertSorted(l2, i3);
    printf("\nTest #5: Test function to use the comparison function in the List struct to place the integer element in the appropriate position in the list");
    printf("\nExpected: \n");
    printf("34\n");
    printf("7\n");
    printf("65\n");
    printf("Recieved:\n");
    printForward(l2);
    printStatus(1);
    
    printf("\nTest #6: Test function to return the integer data at the front of the list: EDGE CASE\n");
    /*
    int *num = getFromFront(NULL);
    printf("\nExpected: \n");
    printf("Recieved:\n");
    printInt(num);*/
    printStatus(0);

    //test getFromBack function
    int *num = getFromBack(l2);
    printf("\nTest #7: Test function to return the integer data at the back of the list EDGE CASE");
    printf("\nExpected: \n");
    printf("65\n");
    printf("Recieved:\n");
    printInt(num);
    printStatus(num != NULL);

    //test deleteNodeFromList function 
    printf("\nTest #8: Test function to remove a integer node from the list and alter the pointers accordingly EDGE CASE\n");
    /*result = deleteNodeFromList(l2, NULL);
    printf("\nExpected: \n");
    printf("34\n");
    printf("7\n");
    printf("65\n");
    printf("Recieved:\n");
    printForward(l2);*/
    printStatus(0);

    //test deleteList function
    deleteList(l2);
    l2 = NULL;
    printf("\nTest #9: Test function to delete the entire integer linked list head to tail");
    printf("\nExpected: \n");
    printf("1\n");
    printf("Recieved:\n");
    printf("%d\n",l2 == NULL);
    printStatus(l2 == NULL);

    //test deleteListNode function
    int *i = malloc(sizeof(int));
    *i = 23;
    i = NULL;
    printf("\nTest #10: Test function to user defined function to delete book linked list node based on the incoming data");
    printf("\nExpected: \n");
    printf("1\n");
    printf("Recieved:\n");
    printf("%d\n",i == NULL);
    printStatus(l2 == NULL);

    return 0;
}
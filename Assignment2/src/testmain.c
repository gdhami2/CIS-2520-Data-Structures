#include <stdio.h>
#include <stdlib.h>
#include "linkedListAPI.h"
#include "queue.h"
#include"patient.h"

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
 //Test createQueue function
 Queue *q2 = createQueue(printPatient, deletePatient, compareFunction);
 printf("\nTest #1:Create the queue  ");
 printf("\nExpected: \n");
 printf("1\n");
 printf("\nRecieved:\n");
 printf("%d\n", q2 != NULL);
 printStatus(q2 != NULL);   

 //Test pop function
 Patient *pat1 = createPatient("Sasuke66", 3, "HN");
 push(q2, pat1);
 pop(q2);
 printf("\nTest #2:remove a patient from the queue");
 printf("\nExpected: \n");
 printf("\n");
 printf("\nRecieved:\n");
 printForward(q2->list);
 printStatus(q2->list->head == NULL);

 //Test top function
 Patient *pat2 = createPatient("Naruto77", 2, "SK");
 push(q2, pat2);
 printf("\nTest #3:return a patient from the top of the queue");
 printf("\nExpected: \n");
 printf("Naruto77 2 SK 0\n");
 printf("\nRecieved:\n");
 printPatient(top(q2));
 printStatus(q2->list->head != NULL);

 //Test count function
 printf("\nTest #4:count the number of items in the queue");
 printf("\nExpected: \n");
 printf("1\n");
 printf("\nRecieved:\n");
 printf("%d\n",count(q2));
 printStatus(q2->list->head != NULL);

//Test push function
printf("\nTest #5:add new pateints to the queue");
Patient *pat3 = createPatient("Kkas56i", 3, "TR");
push(q2, pat3);
Patient *pat4 = createPatient("Sa2i", 4, "RC");
push(q2, pat4);
printf("\nExpected: \n");
printf("Naruto77 2 SK 0\nKkas56i 3 TR 0\nsa2i 4 RC 0\n");
printf("\nRecieved:\n");
printForward(q2->list);
printStatus(q2->list->head != NULL);
}
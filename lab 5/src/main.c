#include<stdio.h>
#include<stdlib.h>
#include"stack.h"
#include "linkedListAPI.h"

int compareInt(const void *first, const void *second);
void printInt( void * b );
void deleteFunction(void *tobeDeleted);

int main(void){
    Stack *st = createStack(printInt, deleteFunction, compareInt);
    int input = 0;
    do{
        
        printf("Please enter an integer: ");
        scanf("%d", &input);
        if(top(st) == NULL){
            push(st, &input);
        }
        else{
            int result = compareInt(&input, top(st));
            if(result >= 0){
                printInt(&input);
                printf("Squash: \n");
                printInt(top(st));
                pop(st);//something wrong here
            }
            push(st, &input);
        }
        printf("Remaining: \n");
        printInt(top(st));
    }while(&input >= 0);
}

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

void printInt( void * b ) 
{
    int *num = (int*)b;
    printf("%d\n", *num);
}

void deleteFunction(void *tobeDeleted){
    if(tobeDeleted != NULL){
        free(tobeDeleted);
    }
    tobeDeleted = NULL;
}
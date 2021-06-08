#include <stdio.h>
#include <stdlib.h>
#include"stack.h"
#include "linkedListAPI.h"

Stack* createStack( void (*printFunction)(void *toBePrinted),

void (*deleteFunction)(void *toBeDeleted),

int (*compareFunction)(const void *first,const void *second)){
    Stack *s = malloc(sizeof(Stack));
    s->list = initializeList(printFunction,deleteFunction, compareFunction );
    s->count = 0;
    return s;
}

void pop(Stack *stack){
// check the stack exists
if( stack ){
    // Get the data at the top of the stack
    void* data = top(stack);
    // Use the data to delete the node from the list
    int result = deleteNodeFromList(stack->list, data );
    // If successful, we can lower our count
    if(result == EXIT_SUCCESS){
    stack->count--;
    }
    }
}

void* top(Stack* s){
    return getFromFront(s->list);
}

int count(Stack * s){
    return s->count;
}

void push( Stack * s, void * data){
    insertFront(s->list, data);
    s->count++;
}
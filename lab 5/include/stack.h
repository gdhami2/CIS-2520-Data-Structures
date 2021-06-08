#include <stdio.h>
#include <stdlib.h>
#include"linkedListAPI.h"

typedef struct stack{
    int count; 
    List *list;
}Stack;

Stack* createStack( void (*printFunction)(void *toBePrinted),

void (*deleteFunction)(void *toBeDeleted),

int (*compareFunction)(const void *first,const void *second));

void pop(Stack *stack);

void* top(Stack* s);

int count(Stack * s);

void push(Stack * s, void * data);
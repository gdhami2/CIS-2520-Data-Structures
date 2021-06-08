#include<stdio.h>
#include<stdlib.h>
#include"linkedListAPI.h"

typedef struct queue{
    List *list;
    int count;
}Queue;

Queue* createQueue( void (*printFunction)(void *toBePrinted),

void (*deleteFunction)(void *toBeDeleted),

int (*compareFunction)(const void *first,const void *second));

void pop(Queue *q);

void* top(Queue* q);

int count(Queue* q);

void push(Queue* q, void * data);
#include <stdio.h>
#include <stdlib.h>
#include "store.h"

store *createStore(void *datas, void(*prPtr)(void* info)){
    store *ptr = malloc(sizeof(store));
    ptr->printPtr = prPtr;
    ptr->data = datas;
    return ptr;
}

void displayStore( store* s ){
    s->printPtr(s->data);
}
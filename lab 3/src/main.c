#include <stdio.h>
#include <stdlib.h>
#include "book.h"
#include "linkedListAPI.h"

void deleteFunction(void *tobeDeleted){
    if(tobeDeleted != NULL){
        free(tobeDeleted);
    }
    tobeDeleted = NULL;
}
int compareFunction(const void *first, const void *second){
    Book *book1 = (Book*) first;
    Book *book2 = (Book*) second;
    if(book1->price > book2->price){
        return 1;
    }
    else if(book1->price < book2->price){
        return -1;
    }
    else{
        return 0;
    }
}

int main(void){
    List *list = initializeList(printBook, deleteFunction, compareFunction);
    Book *book1 = createBook("Sasuke's Friends Shippuden", 7.77); 
    Book *book2 = createBook("Itachi's Brothers Friends Shippuden", 6.64);
    Book *book3 = createBook("Hinata's Husband's Shippuden", 9.54);
    insertFront(list, book1);
    insertFront(list, book2);
    insertFront(list, book3);
    
    printForward(list);
    printBackwards(list);
    return 0;
}
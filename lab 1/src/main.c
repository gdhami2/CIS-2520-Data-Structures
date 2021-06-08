#include <stdio.h>
#include <stdlib.h>
#include "store.h"
#include "book.h"
#include "boardgame.h"

int main(void){
    Book *crBook = createBook("Harry Potter and the Cursed Child", 19.99);
    Book *crBook2 = createBook("Naruto Shippuden", 24.99);
    boardgame *crBoardgame = create("Clue", 12.99, "Hasbro");
    boardgame *crBoardgame2 = create("The Game of Life", 16.99, "Hasbro");
    store *ptr = createStore(crBook, printBook);
    displayStore(ptr);
    ptr->data = crBook2;
    displayStore(ptr);
    ptr->data = crBoardgame;
    ptr->printPtr = printBg;
    displayStore(ptr);
    ptr->data = crBoardgame2;
    displayStore(ptr);

    free(crBook);
    free(crBook2);
    free(crBoardgame);
    free(crBoardgame2);
    free(ptr);
    return 0;
}
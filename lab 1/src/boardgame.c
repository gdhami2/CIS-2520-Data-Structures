#include <stdio.h>
#include <stdlib.h>
#include "boardgame.h"

boardgame *create(char *Name, float price, char *brand){
    boardgame *ptr = malloc(sizeof(boardgame));
    ptr->name = Name;
    ptr->price = price;
    ptr-> brandName = brand;
    return ptr; 
}

char *getbgName(boardgame*bg){
    return bg->name;
}

float getbgPrice(boardgame*bg){
    return bg->price;
}

char *getbgBrand(boardgame*bg){
    return bg->brandName;
}

void printBg(void *bg){
    bg = (boardgame *)bg;
    printf("%s %f %s\n", getbgName(bg), getbgPrice(bg), getbgBrand(bg));
}
#include<stdio.h>
#include<stdlib.h>
#include "car.h"

Car *createCar(char posn, char direction, int time){
    Car *c = malloc(sizeof(Car));
    c->posn = posn;
    c->direction = direction;
    c->time = time;
    return c; 
}

char getPosn(Car *c){
    return c->posn;
}

char getDirection(Car *c){
    return c->direction;
}

int getTime(Car *c){
    return c->time;
}
void deleteCar(void *tobeDeleted){
    if(tobeDeleted != NULL){
        free(tobeDeleted);
    }
    tobeDeleted = NULL;
}

int compareFunction(const void *first, const void *second){
    Car *car1 = (Car*) first;
    Car *car2 = (Car*) second;
    if(car1->time > car2->time){
        return 1;
    }
    else if(car1->time < car2->time){
        return -1;
    }
    else{
        return 0;
    }
}

void printCar(void * c) 
{
    Car *newCar = (Car *) c;
    printf("%c  %c  %d  %d", newCar->posn, newCar->direction, newCar->time,newCar->time  );
}
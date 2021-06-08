#include <stdio.h>
#include <stdlib.h>

typedef struct car {
    char posn;
    char direction;
    int time;
} Car;

Car *createCar(char posn, char direction, int time);

char getPosn(Car *c);

char getDirection(Car *c);

int getTime(Car *c);

int compareFunction(const void *first, const void *second);

void deleteCar(void *tobeDeleted);

void printCar(void * c);
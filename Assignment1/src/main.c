#include<stdio.h>
#include<stdlib.h>
#include"linkedListAPI.h"
#include"car.h"

int main(int argc, char **argv){
    int curTime = 0;
    char direc = 0;
    char posn = 0;
    List *list1 = initializeList(printCar, deleteCar, compareFunction);
    List *list2 = initializeList(printCar, deleteCar, compareFunction);
    List *list3 = initializeList(printCar, deleteCar, compareFunction);
    List *list4 = initializeList(printCar, deleteCar, compareFunction);

    FILE *fp = fopen(argv[1],"r");

    if( fp == NULL )
    {
       printf("Error while opening the file.\n");
       exit(EXIT_FAILURE);
    }
    while(fscanf(fp, "%c %c %d\n", &posn, &direc, &curTime)== 3){
        Car *car1 = createCar(posn, direc, curTime);
        if(posn == 'N'){
            insertSorted(list1, car1);
        }
        else if(posn == 'E'){
            insertSorted(list2, car1);
        }
        else if(posn == 'S'){
            insertSorted(list3, car1);
        }
        else if(posn == 'W'){
            insertSorted(list4, car1);
        }
        else{
            break;
        }
    }

    int hold1 = 1;
    char holDirec = 'N';
    char holdnewDir = '?';
    char holdTime = 0;

    while(1){
        if(list1->head == NULL && list2->head == NULL && list3->head == NULL && list4->head == NULL){
            break;
        }
        if(hold1 % 14 == 0){
            if(holDirec == 'N'){
                holDirec = 'E';
            }
            else if(holDirec == 'E'){
                holDirec = 'S';
            }
            else if(holDirec == 'S'){
                holDirec = 'W';
            }
            else if(holDirec == 'W'){
                holDirec = 'N';
            }
        }
        
        Car *car2 = NULL;
        List *list = NULL;

        if(holDirec == 'N'){
            list = list1;
            car2 = (Car *) getFromFront(list1);
        }
        else if(holDirec == 'E'){
            
            list = list2;
            car2 = (Car *) getFromFront(list2);
        }
        else if(holDirec == 'S'){
            list = list3;
            car2 = (Car *) getFromFront(list3);
        }
        else if(holDirec == 'W'){
            list = list4;
            car2 = (Car *) getFromFront(list4);
        }

        if(car2 != NULL){
            holdnewDir = getDirection(car2);
            holdTime = getTime(car2);
        }
        

       if(car2 != NULL && holdTime <= hold1){
            if(holdnewDir == 'F'){
                printCar(car2);
                printf("  %g\n", (float)(hold1 + 2));
                hold1++;
                deleteNodeFromList(list, car2);
            }
            else if(holdnewDir == 'R'){
                printCar(car2);
                printf("  %g\n", (float)(hold1 + 1));
                deleteNodeFromList(list, car2);
            }
            else if(holdnewDir == 'L'){
                printCar(car2);
                printf("  %g\n", hold1 + 2.5);
                hold1++;
                hold1++;
                deleteNodeFromList(list, car2);
            }

            }
            hold1++;
        } 
    fclose(fp);
    return 0;
}
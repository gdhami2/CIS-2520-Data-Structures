#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include"linkedListAPI.h"
#include"patient.h"
#include"queue.h"

void removeNewLineChar(char *c);

int main(int argc, char **argv){
    Queue *q = createQueue(printPatient, deletePatient, compareFunction);
    Queue *q2 = createQueue(printPatient, deletePatient, compareFunction);
    char curId[100];
    int curPriority = 0;
    char curSymptom[100];
    int curTime = 0;
    int docTime = 0;

    FILE *fp = fopen(argv[1],"r");

    if( fp == NULL )
    {
       printf("Error while opening the file.\n");
       exit(EXIT_FAILURE);
    }
    while(fscanf(fp, "%s %d %s\n", curId, &curPriority, curSymptom)== 3){
        Patient *pat1 = createPatient(curId, curPriority, curSymptom);
        push(q, pat1);
        insertBack(q2->list, pat1);
        
    }
    int userInput = 0;
    while(userInput != 2){
        printf("What would you like to do?\n");
        scanf("%d", &userInput);
        getchar();
        if(userInput == 1){
            printf("ID: ");
            fgets(curId, 100, stdin);
            removeNewLineChar(curId);
            printf("Priority: ");
            scanf("%d", &curPriority);
            getchar();
            printf("Symptom: ");
            fgets(curSymptom, 100, stdin);
            removeNewLineChar(curSymptom);
            Patient *newP = createPatient(curId, curPriority, curSymptom);
            push(q, newP);
            insertBack(q2->list, newP);
        }
        else if(userInput == 3){
            return 0;
        }
    }

    while(q->count != 0){
        Patient *p = (Patient *)top(q);
        if(strcmp(p->symptom, "CV") == 0){
            docTime = 5;
        }
        else if(strcmp(p->symptom, "HN") == 0){
            docTime = 3;
        }
        else if(strcmp(p->symptom, "EV") == 0){
            docTime = 10;
        }
        else if(strcmp(p->symptom, "GI") == 0){
            docTime = 2;
        }
        else if(strcmp(p->symptom, "MH") == 0){
            docTime = 5;
        }
        else if(strcmp(p->symptom, "NC") == 0){
            docTime = 5;
        }
        else if(strcmp(p->symptom, "EC") == 0){
            docTime = 1;
        }
        else if(strcmp(p->symptom, "RC") == 0){
            docTime = 1;
        }
        else if(strcmp(p->symptom, "SK") == 0){
            docTime = 2;
        }
        else if(strcmp(p->symptom, "SA") == 0){
            docTime = 7;
        }
        else if(strcmp(p->symptom, "TR") == 0){
            docTime = 4;
        }
        else{
            printf("This symptom does not exist");
        }
        curTime += docTime;
        p->time = curTime;
        q->list->head = q->list->head->next;
        q->count--;
        curTime++;
    } 
    fclose(fp);
    printForward(q2->list);
    return 0;
}

void removeNewLineChar(char *c){
    c[strlen(c) - 1] = 0;
}
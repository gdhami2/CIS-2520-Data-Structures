#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include "patient.h"

Patient *createPatient(char *id, int priority, char *symptom){
    Patient *p = malloc(sizeof(Patient));
    strcpy(p->id, id);
    p->priority = priority;
    strcpy(p->symptom, symptom);
    return p; 
}

char *getId(Patient *p){
    return p->id;
}

int getpriority(Patient *p){
    return p->priority;
}

char *getSymptom(Patient *p){
    return p->symptom;
}

int getTime(Patient *p){
    return p->time;
}
void deletePatient(void *tobeDeleted){
    if(tobeDeleted != NULL){
        free(tobeDeleted);
    }
    tobeDeleted = NULL;
}

int compareFunction(const void *first, const void *second){
    Patient *pat1 = (Patient*) first;
    Patient *pat2 = (Patient*) second;
    if(pat1->priority > pat2->priority){
        return 1;
    }
    else if(pat1->priority < pat2->priority){
        return -1;
    }
    else{
        return 0;
    }
}

void printPatient(void * p) 
{
    Patient *newPatient = (Patient *) p;
    printf("%s  %d  %s %d\n", newPatient->id, newPatient->priority, newPatient->symptom, newPatient->time);
}
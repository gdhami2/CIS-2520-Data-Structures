#include <stdio.h>
#include <stdlib.h>

typedef struct patient {
    char id[100];
    int priority;
    char symptom[100];
    int time;
} Patient;

/**Function creates a patient.
*@return the dynamically allocated patient.
*@param char *id the identification for a patient.
*@param int priority the level of importance of a patients case.
*@param char *symptom the symptom associated with the patient.
**/
Patient *createPatient(char *id, int priority, char *symptom);

/**Function returns id of patient.
*@return the id associated with a patient of type char *.
*@param Patient *p the information for patient p.
**/
char *getId(Patient *p);

/**Function returns priority of patient.
*@return the priority associated with a patient of type int.
*@param Patient *p the information for patient p.
**/
int getpriority(Patient *p);

/**Function returns symptom of patient.
*@return the symptom associated with a patient of type char *.
*@param Patient *p the information for patient p.
**/
char *getSymptom(Patient *p);

/**Function returns time spent by docter on a patient depending on case.
*@return the time associated with a patient of type int.
*@param Patient *p the information for patient p.
**/
int getTime(Patient *p);

/**Function to differentiate between two inputs.
*@return either 1, 0 or -1 depending on if they're equal, and which of the two are greater when type casted to (int *).
*@param const void *first first value to compare.
*@param const void *second second value to compare.
**/
int compareFunction(const void *first, const void *second);

/**Function to delete patient from the queue.
*@param void *tobeDeleted what is to be deleted from the queue.
**/
void deletePatient(void *tobeDeleted);

/**Function to print out the patients infromation.
*@param void * p the sepecific pateint that is to be printed.
**/
void printPatient(void * p);
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include"HashTableAPI.h"

int countChar(char str[]);
int hashF(size_t size, int a);
void removeNewLine(char *c);
void destroyData(void *d);
void printFunction(void *s);

int main(int argc, char **argv){
    HTable *hash = createTable(500, hashF, destroyData, printFunction);
    char word[50];

    FILE *fp = fopen(argv[1],"r");
    
        if( fp == NULL )
        {
           printf("Error while opening the file.\n");
           exit(EXIT_FAILURE);
        }
        while(fgets(word, 50, fp)){
            char *word1 = malloc(strlen(word) + 1);
            strcpy(word1, word);
            int num = countChar(word);
            insertData(hash, num, word1);
        }
        int userchoice = 0;
        do{
            printf("***********************************************\n");
            printf("Enter 1: Add a word to Dictionary\n");
            printf("Enter 2: Remove a word from Dictionary\n");
            printf("Enter 3: Spell Check a file\n");
            printf("Enter 4: Show Dictionary Words\n");
            printf("Enter 5: Quit\n");
            printf("What would you like to do? \n");
            scanf("%d", &userchoice);
            getchar();

            if(userchoice == 1){
                char usrStr[50];
                printf("Please enter a string\n");
                fgets(usrStr, 50, stdin);
                removeNewLine(usrStr);
                char *word1 = malloc(strlen(usrStr) + 1);
                strcpy(word1, usrStr);
                int num = countChar(usrStr);
                insertData(hash, num, word1);
            }
            else if(userchoice == 2){
                char strToBeRemoved[50];
                printf("Which string would you like to remove\n");
                fgets(strToBeRemoved, 50, stdin);
                removeNewLine(strToBeRemoved);
                removeData(hash,countChar(strToBeRemoved));
            }
            else if(userchoice == 3){
                char usrFile[50];
                printf("Please enter a file name\n");
                fgets(usrFile, 50, stdin);
                removeNewLine(usrFile);
                FILE *f = fopen(usrFile, "r");
                while(fgets(word, 50, f)){
                    int num = countChar(word);
                    if(lookupData(hash, num) == NULL){
                        printf("Word not found: %s\n", word);
                    }
                }
            }
            else if(userchoice == 4){
                int i = 0;
                for(i = 0; i < hash->size; i++){
                    if(hash->table[i] != NULL){
                        printf("%d:%d", i, hash->table[i]->key);
                        hash->printNode(hash->table[i]->data);
                    }
                }
            }
            else if(userchoice == 5){
                printf("Goodbye!\n");
            }
            else{
                printf("Please enter a valid choice\n");
            }
        }while(userchoice != 5);
        
    fclose(fp);
    return 0;
}

int countChar(char str[]){
    int i = 0;
    int count = 0;
    for(i = 0; i< strlen(str); i++){
        count+= str[i];
    }
    return count;
}
int hashF(size_t size, int a){
    return a * 11 % size;
}

void removeNewLine(char *c){
    c[strlen(c) - 1] = 0;
}

void destroyData(void *d){
    free(d);
}
void printFunction(void *s){
    char *d = (char *) s;
    printf("%s\n", d);
}
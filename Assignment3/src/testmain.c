#include<stdio.h>
#include<stdlib.h>
#include"HashTableAPI.h"

//prints pass or fail
void printStatus(int info){
    if(info == 1){
        printf("Pass\n");
    }
    else{
        printf("Fail\n");
    }
}
//returns an index for your table
int hashF(size_t size, int a){
    return a*11%size;
}
void destroyData(void *d){
    free(d);
}
void printFunction(void *s){
    char *d = (char *) s;
    printf("%s", d);
}

int main(void){
    //test create table function
    HTable *hash = createTable(500, hashF, destroyData, printFunction);
    printf("\nTest #1:Create the table  ");
    printf("\nExpected: \n");
    printf("1\n");
    printf("\nRecieved:\n");
    printf("%d\n", hash != NULL);
    printStatus(hash != NULL);

    //test create node function
    Node *n = createNode(32, NULL);
    printf("\nTest #2:Create the node  ");
    printf("\nExpected: \n");
    printf("1\n");
    printf("\nRecieved:\n");
    printf("%d\n", n != NULL);
    printStatus(n != NULL);

    //test insert data function
    insertData(hash, 0, NULL);
    printf("\nTest #3:Insert data  ");
    printf("\nExpected: \n");
    printf("1\n");
    printf("\nRecieved:\n");
    printf("%d\n", hash->table[0] != NULL);
    printStatus(hash->table[0] != NULL);

    //test remove data function
    removeData(hash, 0);
    printf("\nTest #4:Remove data  ");
    printf("\nExpected: \n");
    printf("1\n");
    printf("\nRecieved:\n");
    printf("%d\n", hash->table[0] == NULL);
    printStatus(hash->table[0] == NULL);

    //test look up function
    lookupData(hash, 5);
    printf("\nTest #5:Look up  ");
    printf("\nExpected: \n");
    printf("1\n");
    printf("\nRecieved:\n");
    printf("%d\n", lookupData(hash, 5) == NULL);
    printStatus(lookupData(hash, 5) == NULL);
}
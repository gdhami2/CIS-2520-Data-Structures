#include<stdio.h>
#include<stdlib.h>
#include"HashTableAPI.h"

HTable *createTable(size_t size, int (*hashFunction)(size_t tableSize, int key),void (*destroyData)(void *data),void (*printNode)(void *toBePrinted)){
    HTable *hash = malloc(sizeof(HTable));
    hash->size = size;
    hash->hashFunction = hashFunction;
    hash->destroyData = destroyData;
    hash->printNode = printNode;
    hash->table = malloc(sizeof(Node*)*size);
    return hash;
}

Node *createNode(int key, void *data){
    Node *n = malloc(sizeof(Node));
    n->key = key;
    n->data = data;
    return n;
}
void destroyTable(HTable *hashTable){
    int i = 0;
    for(i = 0; i < hashTable->size; i++){
        if(hashTable->table[i] != NULL){
            hashTable->destroyData(hashTable->table[i]->data);
            free(hashTable->table[i]);
        }
    }
}

void insertData(HTable *hashTable, int key, void *data){
    int j = hashTable->hashFunction(hashTable->size, key);
    hashTable->table[j] = createNode(key, data);
}

void removeData(HTable *hashTable, int key){
    int i = hashTable->hashFunction(hashTable->size, key);
    if(hashTable->table[i] != NULL){
        hashTable->destroyData(hashTable->table[i]->data);
        free(hashTable->table[i]);
        hashTable->table[i] = NULL;
    }
}

void *lookupData(HTable *hashTable, int key){
    int i = hashTable->hashFunction(hashTable->size, key);
    if(hashTable->table[i] != NULL){
        return hashTable->table[i]->data;
    }
    else{
        return NULL;
    }
}
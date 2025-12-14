#include <stdio.h>
#include <stdlib.h>

#define SIZE 10  

struct Node {
    int key;
    struct Node* next;
};

struct Node* hashTable[SIZE];

int hash(int key) {
    return key % SIZE;
}

void insert(int key) {
    int index = hash(key);

    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->key = key;
    newNode->next = hashTable[index];

    hashTable[index] = newNode;
}

int search(int key) {
    int index = hash(key);
    struct Node* temp = hashTable[index];

    while (temp != NULL) {
        if (temp->key == key)
            return 1;  
        temp = temp->next;
    }
    return 0;     
}

void delete(int key) {
    int index = hash(key);
    struct Node* temp = hashTable[index];
    struct Node* prev = NULL;

    while (temp != NULL) {
        if (temp->key == key) {
            if (prev == NULL)
                hashTable[index] = temp->next;  
            else
                prev->next = temp->next;

            free(temp);
            return;
        }
        prev = temp;
        temp = temp->next;
    }
}

void printTable() {
    for (int i = 0; i < SIZE; i++) {
        printf("[%d] -> ", i);
        struct Node* temp = hashTable[i];
        
        while (temp != NULL) {
            printf("%d -> ", temp->key);
            temp = temp->next;
        }
        printf("NULL\n");
    }
}

int main() {
    insert(10);
    insert(20);
    insert(15);
    insert(25);
    insert(7);

    printTable();

    printf("Search 15: %s\n", search(15) ? "Found" : "Not Found");
    printf("Search 99: %s\n", search(99) ? "Found" : "Not Found");

    delete(15);
    delete(7);

    printTable();
}

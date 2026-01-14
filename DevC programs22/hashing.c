#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define SIZE 10

struct DataItem {
    char key[20];
    int value;
};

struct DataItem* hashTable[SIZE];
struct DataItem* dummyItem;

int hashCode(char* key) {
    int sum = 0;
    int j = 0;
    while (key[j] != '\0') {
        sum += key[j];
        j++;
    }
    return sum % SIZE;
}

void insert(char* key, int value) {
    struct DataItem* item = (struct DataItem*) malloc(sizeof(struct DataItem));
    strcpy(item->key, key);
    item->value = value;

    int hashIndex = hashCode(key);

    while (hashTable[hashIndex] != NULL && strcmp(hashTable[hashIndex]->key, "## DELETED ##") != 0) {
        if (strcmp(hashTable[hashIndex]->key, key) == 0) {
            hashTable[hashIndex]->value = value;
            free(item);
            return;
        }
        hashIndex = (hashIndex + 1) % SIZE;
    }

    hashTable[hashIndex] = item;
}

struct DataItem* search(char* key) {
    int hashIndex = hashCode(key);
    while (hashTable[hashIndex] != NULL) {
        if (strcmp(hashTable[hashIndex]->key, key) == 0)
            return hashTable[hashIndex];
        hashIndex = (hashIndex + 1) % SIZE;
    }
    return NULL;
}

void deleteItem(char* key) {
    int hashIndex = hashCode(key);
    while (hashTable[hashIndex] != NULL) {
        if (strcmp(hashTable[hashIndex]->key, key) == 0) {
            hashTable[hashIndex] = dummyItem;
            printf("Deleted key : %s\n", key);
            return;
        }
        hashIndex = (hashIndex + 1) % SIZE;
    }
    printf("Key : %s not found\n", key);
}

void display() {
    int i = 0;
    printf("In Hash Table : \n");
    while (i < SIZE) {
        if (hashTable[i] != NULL && strcmp(hashTable[i]->key, "## DELETED ##") != 0)
            printf("[%d] -> (%s, %d)\n", i, hashTable[i]->key, hashTable[i]->value);
        else
            printf("[%d] -> ~~\n", i);
        i++;
    }
    printf("\n");
}

int main() {
    dummyItem = (struct DataItem*) malloc(sizeof(struct DataItem));
    strcpy(dummyItem->key, "## DELETED ##");
    dummyItem->value = -1;

    insert("apple", 10);
    insert("banana", 20);
    insert("grape", 30);
    insert("orange", 40);

    printf("After insertion:\n");
    display();

    struct DataItem* item = search("banana");
    if (item != NULL)
        printf("Search Result: (%s, %d)\n", item->key, item->value);
    else
        printf("Key not found!\n");

    deleteItem("grape");
    printf("\nAfter deletion:\n");
    display();

    return 0;
}


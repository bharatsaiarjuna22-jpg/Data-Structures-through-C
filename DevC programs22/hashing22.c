#include <stdio.h>
#include <string.h>

#define SIZE 10

char keys[SIZE][20];
int values[SIZE];

int hash(char key[]) {
	int i;
    int s = 0;
    for ( i = 0; key[i]; i++)
        s += key[i];
    return s % SIZE;
}

void insert(char key[], int val) {
    int idx = hash(key);

    while (values[idx] != -1 && strcmp(keys[idx], key) != 0)
        idx = (idx + 1) % SIZE;

    strcpy(keys[idx], key);
    values[idx] = val;
}

int search(char key[]) {
    int idx = hash(key);

    while (values[idx] != -1) {
        if (strcmp(keys[idx], key) == 0)
            return values[idx];
        idx = (idx + 1) % SIZE;
    }
    return -1;
}

void display() {
	int i;
    for ( i = 0; i < SIZE; i++) {
        if (values[i] != -1)
            printf("[%d] -> (%s, %d)\n", i, keys[i], values[i]);
        else
            printf("[%d] -> ~~\n", i);
    }
}

int main() {
	int i;
    for ( i = 0; i < SIZE; i++)
        values[i] = -1;

    insert("apple", 10);
    insert("banana", 20);
    insert("grape", 30);

    display();

    printf("Search banana: %d\n", search("banana"));
}

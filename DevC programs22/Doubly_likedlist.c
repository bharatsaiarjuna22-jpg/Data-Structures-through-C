#include <stdio.h>
#include <stdlib.h>
// Node structure for doubly linked list
struct Node {
    int data;
    struct Node* prev;
    struct Node* next;
};
// Function to create a new node
struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->prev = NULL;
    newNode->next = NULL;
    return newNode;
}
// Function to insert node in sorted order
void insertSorted(struct Node** head, int data) {
    struct Node* newNode = createNode(data);
    // Case 1: Empty list
    if (*head == NULL) {
        *head = newNode;
        return;
    }
    struct Node* temp = *head;
    // Case 2: Insert before the head
    if (data < temp->data) {
        newNode->next = temp;
        temp->prev = newNode;
        *head = newNode;
        return;
    }
    // Case 3: Find position to insert
    while (temp->next != NULL && temp->next->data < data) {
        temp = temp->next;
    }
    newNode->next = temp->next;
    newNode->prev = temp;
    if (temp->next != NULL) {
        temp->next->prev = newNode;
    }
    temp->next = newNode;
}
// Function to delete a node with given key
void deleteNode(struct Node** head, int key) {
    if (*head == NULL) {
        printf("List is empty.\n");
        return;
    }
    struct Node* temp = *head;
    // Search for the node to be deleted
    while (temp != NULL && temp->data != key) {
        temp = temp->next;
    }
    // Key not found
    if (temp == NULL) {
        printf("Element %d not found in the list.\n", key);
        return;
    }
    // If node to be deleted is head node
    if (temp->prev == NULL) {
        *head = temp->next;
        if (*head != NULL)
            (*head)->prev = NULL;
    } 
    else {
        temp->prev->next = temp->next;
    }
    if (temp->next != NULL) {
        temp->next->prev = temp->prev;
    }
    free(temp);
    printf("Element %d deleted successfully.\n", key);
}
// Function to display the doubly linked list
void displayList(struct Node* head) {
    if (head == NULL) {
        printf("List is empty.\n");
        return;
    }

    struct Node* temp = head;
    printf("Doubly Linked List: ");
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}
// Main function
int main() {
    struct Node* head = NULL;
    int n, i, val, key;

   printf("Enter number of elements to insert: ");
    scanf("%d", &n);
    printf("Enter %d elements:\n", n);
    for (i = 0; i < n; i++) {
        scanf("%d", &val);
        insertSorted(&head, val);}

    printf("\nList in sorted order:\n");
    displayList(head);

    printf("\nEnter element to delete: ");
    scanf("%d", &key);

    deleteNode(&head, key);

    printf("\nList after deletion:\n");
    displayList(head);

    return 0;
}


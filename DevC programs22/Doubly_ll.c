//doubly linked list
#include <stdio.h>
#include <stdlib.h>
struct Node {
    int data;
    struct Node* prev;
    struct Node* next;
};
struct Node* createNode(int data) {// Function to create a new node
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->prev = NULL;
    newNode->next = NULL;
    return newNode;
}
void insertSorted(struct Node** head, int data) {// Function to insert node in sorted order
    struct Node* newNode = createNode(data);
    if (*head == NULL) {// Case 1: Empty list
        *head = newNode;
        return;
    }
    struct Node* temp = *head;
    if (data < temp->data) { // Case 2: Insert before the head
        newNode->next = temp;
        temp->prev = newNode;
        *head = newNode;
        return;
    }
    while (temp->next != NULL && temp->next->data < data) {// Case 3: Find position to insert
        temp = temp->next;
    }
    newNode->next = temp->next;
    newNode->prev = temp;
    if (temp->next != NULL) {
        temp->next->prev = newNode;
    }
    temp->next = newNode;
}
void deleteNode(struct Node** head, int key) {// Function to delete a node with given key
    if (*head == NULL) {
        printf("List is empty.\n");
        return;
    }
    struct Node* temp = *head;
    while (temp != NULL && temp->data != key) {// Search for the node to be deleted
        temp = temp->next;
    }
    if (temp == NULL) {// Key not found
        printf("Element %d not found in the list.\n", key);
        return;
    }
    if (temp->prev == NULL) {// If node to be deleted is head node
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
void displayList(struct Node* head) {// Function to display the doubly linked list
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

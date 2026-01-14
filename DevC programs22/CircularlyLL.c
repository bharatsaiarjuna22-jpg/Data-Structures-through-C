//circularlylinked list
#include <stdio.h>
#include <stdlib.h>
struct Node {
    int data;
    struct Node* next;
};
struct Node* last = NULL;   // global pointer to last node (useful for circular list)
// Function to create a new node
struct Node* createNode(int val) {
    struct Node* nn = (struct Node*)malloc(sizeof(struct Node));
    nn->data = val;
    nn->next = nn; // initially points to itself
    return nn;
}
// Insert at end
void insert(int val) {
    struct Node* nn = createNode(val);

    if (last == NULL) { // empty list
        last = nn;
    } else {
        nn->next = last->next;
        last->next = nn;
        last = nn;  // update last to new node
    }
}
// Delete a given integer
void deleteNode(int key) {
    if (last == NULL) {
        printf("List is empty.\n");
        return;
    }
    struct Node* curr = last->next;
    struct Node* prev = last;
    // Search for node to delete
    do {
        if (curr->data == key) {
            if (curr == last && curr == last->next) {
                // Only one node in list
                free(curr);
                last = NULL;
            } 
            else {
                prev->next = curr->next;
                if (curr == last)  // deleting last node
                    last = prev;
                if (curr == last->next) // deleting first node
                    last->next = curr->next;
                free(curr);
            }
            printf("Deleted %d from list.\n", key);
            return;
        }
        prev = curr;
        curr = curr->next;
    } while (curr != last->next);

    printf("Element %d not found.\n", key);
}
// Display the circular list
void display() {
    if (last == NULL) {
        printf("List is empty.\n");
        return;
    }
    struct Node* temp = last->next; // start from first node
    printf("Circular Linked List: ");
    do {
        printf("%d ", temp->data);
        temp = temp->next;
    } while (temp != last->next);
    printf("\n");
}
void main() {
    insert(10);
    insert(20);
    insert(30);
    insert(40);
    display();
    deleteNode(20);
    display();
    deleteNode(10);
    display();
    deleteNode(40);
    display();
    deleteNode(30);
    display();
}

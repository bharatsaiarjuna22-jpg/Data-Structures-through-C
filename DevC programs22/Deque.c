#include <stdio.h>
#include <stdlib.h>
struct node {
    int data;
    struct node* next;
};
struct node* front = NULL;
struct node* rear = NULL;
int isEmpty() {
    return front == NULL && rear == NULL;
}
void insert_front(int x) {
    struct node* nn = (struct node*)malloc(sizeof(struct node));
    nn->data = x;
    nn->next = NULL;
    if (isEmpty()) {
        front = rear = nn;
    } else {
        nn->next = front;
        front = nn;
    }
    printf("%d is inserted at front\n", x);
}
void insert_rear(int x) {
    struct node* nn = (struct node*)malloc(sizeof(struct node));
    nn->data = x;
    nn->next = NULL;
    if (isEmpty()) {
        front = rear = nn;
    } else {
        rear->next = nn;
        rear = nn;
    }
    printf("%d is inserted at rear\n", x);
}
void delete_front() {
    if (!isEmpty()) {
        struct node* temp = front;
        printf("%d is deleted from front\n", temp->data);
        front = front->next;
        if (front == NULL)
            rear = NULL;
        free(temp);
    } else {
        printf("Deque is empty. Cannot delete from front.\n");
    }
}
void delete_rear() {
    if (!isEmpty()) {
        if (rear == front) {
            printf("%d is deleted from rear\n", rear->data);
            free(rear);
            front = rear = NULL;
        } else {
            struct node* a = front;
            while (a->next != rear) {
                a = a->next;
            }
            printf("%d is deleted from rear\n", rear->data);
            free(rear);
            rear = a;
            rear->next = NULL;
        }
    } else {
        printf("Deque is empty. Cannot delete from rear.\n");
    }
}
void peek_front() {
    if (!isEmpty())
        printf("Front element: %d\n", front->data);
    else
        printf("Deque is empty. No front element.\n");
}
void peek_rear() {
    if (!isEmpty())
        printf("Rear element: %d\n", rear->data);
    else
        printf("Deque is empty. No rear element.\n");
}
void display() {
    if (isEmpty()) {
        printf("Deque is empty.\n");
        return;
    }
    struct node* temp = front;
    printf("Deque elements: ");
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}
int main() {
    insert_front(10);
    insert_front(20);
    insert_front(30);
    insert_rear(40);
    insert_rear(50);
    insert_rear(60);
    peek_front();
    peek_rear();
    display();
    delete_front();
    delete_rear();
    display();
    return 0;
}


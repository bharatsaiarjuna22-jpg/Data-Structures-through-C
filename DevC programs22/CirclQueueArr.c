#include <stdio.h>
#define SIZE 5   // maximum size of queue

int queue[SIZE];
int front = -1, rear = -1;

int isEmpty() {
    return front == -1;
}

int isFull() {
    return (front == (rear + 1) % SIZE);
}

void enqueue(int val) {
    if (isFull()) {
        printf("Queue is Full!\n");
        return;
    }
    if (isEmpty()) {
        front = rear = 0;
    } else {
        rear = (rear + 1) % SIZE;
    }
    queue[rear] = val;
}

void dequeue() {
    if (isEmpty()) {
        printf("Queue is Empty!\n");
        return;
    }
    if (front == rear) {
        // only one element
        front = rear = -1;
    } else {
        front = (front + 1) % SIZE;
    }
}

int peek() {
    if (isEmpty()) {
        printf("Queue is Empty!\n");
        return -1;
    }
    return queue[front];
}

void display() {
    if (isEmpty()) {
        printf("Queue is Empty!\n");
        return;
    }
    printf("Queue elements: ");
    int i = front;
    while (1) {
        printf("%d ", queue[i]);
        if (i == rear) break;
        i = (i + 1) % SIZE;
    }
    printf("\n");
}

int main() {
    enqueue(12);
    enqueue(45);
    enqueue(89);

    display();

    printf("Peek: %d\n", peek());

    dequeue();
    display();

    enqueue(77);
    enqueue(33);
    enqueue(99);  // This should show "Queue is Full"

    display();

    while (!isEmpty()) {
        printf("Dequeued: %d\n", peek());
        dequeue();
    }

    return 0;
}


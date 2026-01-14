#include<stdio.h>
#define SIZE 7
int queue[SIZE];
int front =-1,rear=-1;
int isEmpty(){
	return front==-1;
}
int isFull(){
	return front==(rear+1)%SIZE;
}
void enqueue(int val){
	if(isFull()){
		printf("\nQUEUE IS FULL\n");
		return;
	}
	if(isEmpty()){
		front= rear=0;
	}
	else{
		rear=(rear+1)%SIZE;
	}
	queue[rear]=val;
}
int peek(){
	return queue[front];
}
void dequeue(){
	if(isEmpty()){
		printf("\nQueue is Empty\n");
		return;
	}
	if(front==rear){
		front= rear=-1;
	}
	else{
		front=(front+1)%SIZE;
	}
	printf("\nelement deleted\n");
}
void display(){
	if(isEmpty()){
		printf("Q\nueue is Empty\n");
	}
	else{
		printf("\nQueue elements are:\n");
		int i = front;
		while(1){
			printf("%d\t",queue[i]);
			if(i==rear){
				break;
			}
			i=(i+1)%SIZE;
		}
	}
}
void main(){
	enqueue(10);
	enqueue(20);
	enqueue(30);
	display();
	printf("\n peek :\n",peek());
	dequeue();
	dequeue();
	dequeue();
	enqueue(40);
	display();
}

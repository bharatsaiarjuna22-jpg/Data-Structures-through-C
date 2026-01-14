#include<stdio.h>
#include<stdlib.h>
struct node{
	int data;
	struct node* next;
};
struct node*front=NULL,*rear=NULL;
int isEmpty(){
	return rear==NULL;
}
void enqueue(int val){
	struct node*temp= (struct node*)malloc(sizeof(struct node));
	temp->data=val;
	temp->next=NULL;
	if(isEmpty()){
		front = rear= temp;
	}
	else{
		rear->next= temp;
		rear= temp;
	}
}
void dequeue(){
	if(!isEmpty()){
		struct node*temp=front;
		front= front->next;
		free(temp);
	}
	else{
		printf("\n not possible\n");
	}
}
int peek(){
	if(!isEmpty()){
		return front->data;
	}
}
int main(){
	enqueue(10);
	enqueue(20);
	enqueue(30);
	struct node*temp;
	while(front!=NULL){
		printf("%d\t",peek());
		dequeue();
	}
}

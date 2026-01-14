#include<stdio.h>
#include<stdlib.h>
struct node{
	int data;
	struct node* next;
};
struct node* front=NULL,*rear= NULL;
void insert_front(int val){
	struct node*nn= (struct node*)malloc(sizeof(struct node));
	nn->data=val;
	nn->next=NULL;
	if(isEmpty()){
		front = rear= nn;
	}
	else{
		nn->next= front;
		front=nn;
	}
	printf("\n %d is inserted at front\n",val);
}
int isEmpty(){
	return front==NULL&&rear==NULL;
}
int insert_rear(int val){
	struct node*nn= (struct node*)malloc(sizeof(struct node));
	nn->data=val;
	nn->next=NULL;
	if(isEmpty()){
		front = rear= nn;
	}
	else{
		rear->next=nn;
		rear=nn;
	}
	printf("\n %d is inserted at rear\n",val);
}
int remove_front(){
	if(isEmpty()){
		printf("\nQueue is empty\n");
		return;
	}
	else{
		struct node*temp= front;
		if(front==NULL){
			rear=NULL;
		}
		free(temp);
	}
	printf("\ndeleted from rear\n");
}
int remove_rear(){
	if(isEmpty()){
		printf("\n Queue is Empty\n");
		return;
	}
	if(front==rear){
		free(rear);
		front=rear=NULL;
	}
	else{
		struct node*a=front;
	while(a->next!=NULL){
		a=a->next;
	}
	printf("\n%d element is removed from rear\n",rear->data);
	free(rear);
	rear=a;
	rear->next=NULL;
	}
}
void peek_front(){
	if(isEmpty()){
		printf("\nEmpty\n");
	}
	else{
		printf("Front element:%d \n",front->data);
	}
}
void peek_rear(){
	if(isEmpty()){
		printf("\n Empty\n");
	}
	else{
		printf("\nRear element:%d\n",rear->data);
	}
}
void display(){
	if(isEmpty()){
		printf("\nDeque is Empty\n");
		return;
	}
	struct node*temp=front;
	printf("Deque:");
	while(temp!=NULL){
		printf("%d\t",temp->data);
		temp=temp->next;
	}
	printf("\n");
}
void main(){
	insert_rear(10);
	insert_front(10);
	insert_rear(20);
	insert_front(20);
	insert_front(30);
	insert_rear(30);
	display();
	peek_rear();
	peek_front();
	remove_rear();
	display();
}

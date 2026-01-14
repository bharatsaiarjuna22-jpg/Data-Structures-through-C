#include<stdio.h>
#include<stdlib.h>
struct node {
	int data;
	struct node*next;
};
struct node*top=NULL;
int isEmpty(){
	return top== NULL;
}
void push(int val){
	struct node*temp= (struct node*)malloc(sizeof(struct node));
	temp->data=val;
	temp->next=top;
	top=temp;
}
void pop(){
	if(!isEmpty()){
		struct node* temp= top;
		top=top->next;
		free(temp);
	}
}
int peek(){
	if(!isEmpty()){
		return top->data;
	}

}
int main(){
	push(10);
	push(20);
	push(30);
	push(40);
	while(!isEmpty()){
		printf("%d\t",peek());
		pop();
	}
	return 0;
}


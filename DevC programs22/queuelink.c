#include<stdio.h>
#include<stdlib.h>
struct node {
	int num;
	struct node *next;
};
struct node *rear=NULL,*front =NULL;
void enqueue(int val)
{
	struct node *temp= (struct node*)malloc(sizeof(struct node));
	temp->num= val;
	temp->next=NULL;
	if(isEmpty())
	{
		rear=front=temp;
	}
	else{
	rear->next = temp;
	rear = temp;
	}
	
}
void dequeue()
{
	if(!isEmpty()){
	struct node *temp=front;
	front=front->next;
	free(temp);
	}
}

int isEmpty(){
	return rear==NULL;
}
int peek(){
	return front->num;
}
int main()
{
	enqueue(10);
	enqueue(30);
	enqueue(14);
	
/*	while(front!=NULL)
	{
		printf("%d\t",peek());
		dequeue();
	}
*/

	while(front!=NULL)
	{
		printf("%d\t",peek());
		printf("address of front=%u\n",front);
		dequeue();
	}
	printf("Front address=%u",front);
}


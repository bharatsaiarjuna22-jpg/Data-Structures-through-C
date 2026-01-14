#include<stdio.h>
#include<stdlib.h>
struct frame{
	int n,stage;
	char from,to,aux;
	struct frame*next;
};
struct frame *top = NULL;
void push(int x,char f,char t,char a,int y){
	struct frame *temp = (struct frame*)malloc(sizeof(struct frame));
	temp->n=x;
	temp->from=f;
	temp->to=t;
	temp->aux=a;
	temp->stage=y;
	temp->next=NULL;
	temp->next=top;
	top=temp;
}
int isEmpty(){
	return top ==NULL;
}
struct frame pop(){
	struct frame *temp=top,val=*temp;
	top=top->next;
	free(temp);
	return val;
}
void main(){
	int n;
	struct frame current;
	printf("Enter number of discs:");
	scanf("%d",&n);
	printf("steps are:");
	push(n,'x','y','z',0);
	while(!isEmpty()){
		current =pop();
		if(current.n==1){
			printf("\n Move disc%d from %c to %c",current.n,current.from,current.to);
		}
		else if(current.stage==0){
			current.stage=1;
			push(current.n,current.from,current.to,current.aux,current.stage);
			push(current.n-1,current.from,current.aux,current.to,0);
		}
		else if(current.stage==1){
			printf("\n Move disc %d from %c to %c",current.n,current.from,current.to );
			push(current.n-1,current.aux,current.to,current.from,0);
		}
	}
}

#include<stdio.h>
#include<stdlib.h>
struct node{
	int data;
	struct node*next;
};
struct node *last=NULL;
struct node*createNode(int val){
	struct node*newnode= (struct node*)malloc(sizeof(struct node));
	newnode->data=val;
	newnode->next=NULL;
	return newnode;
}
void insert(int val){
    struct node*nn= createNode(val);
    if(last==NULL){
        last=nn;
        last->next = last;   
    }
    else{
        nn->next=last->next;
        last->next=nn;
        last=nn;
    }
    printf("\n%d inserted\n",val);   
}

void deleteNode(int key){
	if(last==NULL){
		printf("\nList is Empty\n");
		return;
	}
	struct node*curr=last->next;
	struct node*prev=last;
	do{
		if(curr->data==key){
			if(curr==last&&curr==last->next)
			{
				free(curr);
				last=NULL;
			}
			else{
				prev->next=curr->next;
				if(curr==last)
					last= prev;
				if(curr==last->next)
					last->next=curr->next;
				free(curr);
			}
				printf("%d element deleted\n",key);
				return;
			
			prev=curr;
			curr=curr->next;
		}
	}while(curr!=last->next);
	printf("Element %d not found in list",key);
}
void display(){
	if(last!=NULL){
		struct node*temp=last->next;
		printf("Your list:\n");
		do{
			printf("%d\t",temp->data);
			temp=temp->next;
		}while(temp!=last->next);
		printf("\n");
	}	
}
void main(){
	insert(10);
	insert(20);
	insert(30);
	display();
	
}

#include<stdio.h>
#include<stdlib.h>
struct node{
	int data;
	struct node* prev;
	struct node*next;
};
struct node* createNode(int val){
	struct node* newnode= (struct node*)malloc(sizeof(struct node));
	newnode->data= val;
	newnode->prev= NULL;
	newnode->next= NULL;
	return newnode;
}
void insertsorted(struct node **head,int data){
	struct node* newnode= createNode(data);
	if(*head==NULL){
		*head=newnode;
		return;
	}
	struct node *temp= *head;
	if(data<temp->data){
		newnode->next=temp;
		temp->prev=newnode;
		newnode->prev=NULL;
		*head=newnode;
		return;
	}
	while(temp->next!=NULL&& temp->next->data<data)
	{
		temp=temp->next;
	}
	newnode->next=temp->next;
	newnode->prev=temp;
	if(temp->next!=NULL){
		temp->next->prev=newnode;
	}
	temp->next=newnode;
}
void deleteNode(struct node **head, int key) {
    if (*head == NULL) {
        printf("List empty\n");
        return;
    }

    struct node* temp = *head;

    // search for the key
    while (temp != NULL && temp->data != key) {
        temp = temp->next;
    }

    if (temp == NULL) {
        printf("\n%d not found\n", key);
        return;
    }

    // Case 1: deleting head
    if (temp->prev == NULL) {
        *head = temp->next;
        if (*head != NULL)
            (*head)->prev = NULL;
    }
    // Case 2: deleting last node
    else if (temp->next == NULL) {
        temp->prev->next = NULL;
    }
    // Case 3: deleting middle node
    else {
        temp->prev->next = temp->next;
        temp->next->prev = temp->prev;
    }

    printf("\n%d deleted\n", key);
    free(temp);
}
int display(struct node *head){
	if(head ==NULL){
		printf("\nempty\n");
		return;
	}
	struct node *temp=head;
	printf("\nDoubly linked list\n");
	while(temp!=NULL){
		printf("%d\t",temp->data);
		temp=temp->next;
	}
	printf("\n");
}
void main(){
	int n,key,i,val;
	struct node *head=NULL;
	printf("N value:");
	scanf("%d",&n);
	printf("Enter %d values:",n);
	for(i=0;i<n;i++){
		scanf("%d",&val);
		insertsorted(&head,val);
	}
	printf("List in sorted order:\n");
	display(head);
	printf("key:");
	scanf("%d",&key);
	deleteNode(&head,key);
	printf("List of deletion:\n");
	display(head);
	
	
}

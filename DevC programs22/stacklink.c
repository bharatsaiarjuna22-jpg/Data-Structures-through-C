//Stack

#include <stdio.h>
#include <stdlib.h>
struct node
{
    int data;
    struct node *next;
};
struct node *top=NULL;
void push(int val)
{
    struct node *nn=(struct node*)malloc(sizeof(struct node));
    nn->data=val;
    nn->next=NULL;
    nn->next=top;
    top=nn;
}
int isEmpty()
{
    return top==NULL;
}
void pop()
{
    if(!isEmpty())
    {
        struct node *temp=top;
        top=top->next;
        free(temp);
    }
}
int peek()
{
    return top->data;
}
int main()
{
    push(10);
    push(20);
    push(30);
    while(!isEmpty())
    {
        printf("%d\t",peek());
        pop();
    }
    return 0;
}

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
    struct node *nn =(struct node*)malloc(sizeof(struct node));
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
int main()
{
    char input[50];
    int i=0;
    printf("Enter a string consisting of '{' and '}': ");
    scanf("%s",input);
    while(input [i]!='\0')
    {
        if(input[i]=='{')
            push(input[i]);
        else
        {
            if(!isEmpty())
                pop();
            else
                break;
        }
        i++;
    }
    if(input[i]=='\0' && isEmpty())
        printf("Parenthesis Matched");
    else if(input[i]=='\0' && !isEmpty())
        printf("Right Missing");
    else
        printf("Left Missing");

    return 0;
}

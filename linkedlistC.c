#include<stdio.h>
#include<stdlib.h>
struct node
{
    int data;
    struct node* next;
};
void insert(struct node **head,int key)
{
    struct node*temp;
    if(*head==NULL)
    {
        *head=malloc(sizeof(struct node));
        (*head)->data=key;
        (*head)->next=NULL;
    }
    else
    {
        temp=*head;
        while(temp->next!=NULL)
            temp=temp->next;

        temp->next=(struct node *)malloc(sizeof(struct node));
        temp=temp->next;
        temp->data=key;
        temp->next=NULL;
    }
}
void display(struct node*head)
{
    struct node*curr=head;
    while(curr!=NULL)
    {
        printf("%2d ",curr->data);
        curr=curr->next;
    }
    printf("\n");
}

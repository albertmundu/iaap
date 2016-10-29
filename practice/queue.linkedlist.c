#include <stdio.h>
#include <stdlib.h>


struct node {
    int data;
    struct node*next;
};

struct node * createnode(int data){
    struct node*tmp=(struct node*)malloc(sizeof(struct node));
    tmp->data=data;
    tmp->next=NULL;
    return tmp;
}

void enqueue(struct node**head,struct node**tail,int data){
    if(*head==NULL)
        *head=*tail=createnode(data);
    else {
        (*tail)->next=createnode(data);
        *tail=(*tail->next);
    }
}
void dequeue(struct node**head,struct node**tail){
    if(*head==NULL || *tail==NULL)
        return;
    else
    {
        struct node * tmp=*head;
        *head=(*head)->next;
        free(tmp);
    }
}
struct node* front(struct node*head){
    return head;
}

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
        *tail=(*tail)->next;
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
int isempty(struct node*head){
    if(head==NULL)
        return 1;
    return 0;
}
void prt_queue(struct node*head){
    for(;head!=NULL;head=head->next)
    {
        printf("%d ",head->data);
    }
    printf("\n");
}

int main(){
    struct node*head=NULL,*tail=NULL;
    enqueue(&head,&tail,89);
    enqueue(&head,&tail,89);
    enqueue(&head,&tail,89);
    enqueue(&head,&tail,89);
    enqueue(&head,&tail,89);
    enqueue(&head,&tail,89);
    prt_queue(head);
    dequeue(&head,&tail);
    dequeue(&head,&tail);
    dequeue(&head,&tail);
    dequeue(&head,&tail);
    dequeue(&head,&tail);
    prt_queue(head);
    dequeue(&head,&tail);
    prt_queue(head);
    enqueue(&head,&tail,89);
    enqueue(&head,&tail,89);
    enqueue(&head,&tail,89);
    prt_queue(head);
}

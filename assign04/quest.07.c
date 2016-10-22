#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node*next;
    struct node*prev;
};

struct node* createnode(int data);
void insert(struct node**head,struct node**tail,int data);
void displaylist(struct node*head);

struct node* createnode(int data){
    struct node*tmp=(struct node*)malloc(sizeof(struct node));
    tmp->data=data;
    tmp->next=NULL;
    tmp->prev=NULL;
    return tmp;
}

void insert(struct node**head,struct node**tail,int data){
    struct node*new_node=createnode(data);
    if(*head==NULL){
        *head=new_node;
        *tail=new_node;
    }
    else{
        (*tail)->next=new_node;
        new_node->prev=*tail;
        new_node->next=*head;
        *tail=new_node;
        (*head)->prev=*tail;
    }
}

void displaylist(struct node*head){
    struct node*tmp=head;
    do {
        printf("%d -> ",tmp->data);
        tmp=tmp->next;
    }while(tmp!=head);
    printf("head\n");
}
void displayreverse(struct node*tail){
    struct node*tmp=tail;
    do {
        printf("%d -> ",tmp->data);
        tmp=tmp->prev;
    }while(tmp!=tail);
    printf("tail\n");
}

int main(){
    struct node*head=NULL,*tail=NULL;
    int n,data;
    scanf("%d",&n);

    for(int i=0;i<n;i++){
        scanf("%d",&data);
        insert(&head,&tail,data);
    }
    displaylist(head);
    displayreverse(tail);
    return 0;
}

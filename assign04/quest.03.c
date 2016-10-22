#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node*next;
};

struct node*createnode(int data);
void insert(struct node**head,int data);
void sort(struct node**head);
void displaylist(struct node*head);

int main(){
    struct node*head=NULL;
    int n,data;
    scanf("%d",&n);
    for(int i=0;i<n;i++){
        scanf("%d",&data);
        insert(&head,data);
    }
    displaylist(head);
    sort(&head);
    displaylist(head);
    return 0;
}

struct node*createnode(int data){
    struct node*tmp=(struct node*)malloc(sizeof(struct node));
    tmp->data=data;
    tmp->next=NULL;
    return tmp;
}

void insert(struct node**head,int data){
    struct node*new_node=createnode(data);
    if(*head==NULL){
        *head=new_node;
    }
    else{
        struct node*tmp=*head;
        for(;tmp->next!=NULL;tmp=tmp->next);
        tmp->next=new_node;
    }
}

void sort(struct node**head){
    int key,exit_loop=0;
    struct node*prev=*head;
    for(struct node*tmp=(*head)->next;tmp!=NULL;prev=tmp,tmp=tmp->next){
        key=tmp->data;
        while(key<prev->data && exit_loop!=1){
            prev->next->data=prev->data;
            if(prev!=*head){
                struct node*tp=*head;
                for(;tp->next!=prev;tp=tp->next);
                prev=tp;
            }
            else{
                exit_loop=1;
            }
        }
        if(key<prev->data)
            prev->data=key;
        else
            prev->next->data=key;
        displaylist(*head);
        exit_loop=0;
    }
}

void displaylist(struct node*head){
    printf("\n");
    for(struct node*tmp=head;tmp!=NULL;tmp=tmp->next){
        printf("%d --> ",tmp->data);
    }
    printf("NULL\n");
}

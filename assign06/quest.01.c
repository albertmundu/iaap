#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    int fi;
    struct node*friend;
    struct node*next;
};

struct node*createnode(int data,int fi){
    struct node*tmp=(struct node*)malloc(sizeof(struct node));
    tmp->data=data;
    tmp->fi=fi;
    tmp->friend=NULL;
    tmp->next=NULL;
    return tmp;
}

void insert(struct node**head,struct node**tail,int data,int fi){
    struct node*newnode=createnode(data,fi);
    if(*head==NULL){
        *head=newnode;
        *tail=newnode;
    }
    else {
        (*tail)->next=newnode;
        *tail=newnode;
    }
}

void ptr_list(struct node*head){
    struct node*tmp=head;
    for(;tmp!=NULL;tmp=tmp->next)
        printf("%d -> ",tmp->data);
    printf("NULL\n");
}

void copylist(struct node*source,struct node**destination,struct node**hash,int capacity){
    struct node*tmp=source;
    struct node*tail=NULL;
    for(;tmp!=NULL;tmp=tmp->next)
    {
        insert(destination,&tail,tmp->data,tmp->fi);
        tail->friend=hash[(tmp->fi)-1];
    }     
}


void display_friends(struct node*head){
    struct node*tmp=head;
    for(;tmp!=NULL;tmp=tmp->next){
        printf("%d_",tmp->friend->data);
    }
    printf("\n");
}


int main(){
    struct node*head=NULL,*tail=NULL;
    int capacity=100;
    struct node*hash[capacity];
    int n;
    int data,fi;
    scanf("%d",&n);
    for(int i=0;i<n;i++){
        scanf("%d%d",&data,&fi);
        insert(&head,&tail,data,fi);
        hash[i]=tail;
    }
    ptr_list(head);
    
    //second list
    struct node*second=NULL;
    copylist(head,&second,hash,capacity);
    ptr_list(second);

    display_friends(second);

    return 0;
}

#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node*next;
};

struct node*createnode(int data);
void insert(struct node**head,int data);
void reverse(struct node**head);
void reverse2(struct node**head);
struct node*recursion(struct node**head,struct node*tmp);
void displaylist(struct node*head);
int listlength(struct node*head);


int main(){
    struct node*head=NULL;
    int n,data;
    scanf("%d",&n);
    for(int i=0;i<n;i++){
        scanf("%d",&data);
        insert(&head,data);
    }
    displaylist(head);
    recursion(&head,head);
    //reverse_bhumil(&head);
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
    else {
        struct node*tmp=NULL;
        for(tmp=*head;tmp->next!=NULL;tmp=tmp->next);
        tmp->next=new_node;
    }
}

void reverse(struct node**head){
    struct node*tmp=NULL,*prev=NULL,*tail=NULL;
    int count=listlength(*head);

    for(tmp=*head;tmp->next!=NULL;tmp=tmp->next);
    tail=tmp;

    while(count--){
    for(tmp=*head;tmp->next!=NULL;prev=tmp,tmp=tmp->next);
        tmp->next=prev;
        prev->next=NULL;
    }
    *head=tail;
}

void reverse2(struct node**head){
    struct node*tmp=*head,*prev=NULL;
    struct node*tail=NULL;
    for(tail=*head;tail->next!=NULL;tail=tail->next);
    while((*head)->next!=NULL){
        if(tmp->next==NULL){
            tmp->next=prev;
            prev->next=NULL;
            tmp=*head;
        }
        prev=tmp;
        tmp=tmp->next;
    }
    *head=tail;
}

struct node* recursion(struct node**head,struct node*tmp){
    if(tmp->next==NULL){
        *head=tmp;
        return tmp;
    }
    else {
        struct node*t=recursion(head,tmp->next);
        t->next=tmp;
        tmp->next=NULL;
        return tmp;
    }
    
}

void reverse_bhumil(struct node **head){
    struct node *prev=NULL, *new=NULL;
    while((*head)!=NULL){
        if(prev==NULL){
            prev=createnode((*head)->data);
        }
        else{
            new=createnode((*head)->data);
            new->next=prev;
            prev=new;
        }
        (*head)=(*head)->next;
    }
        (*head)=prev;
}

int listlength(struct node*head){
    int count=0;
    for(struct node*tmp=head;tmp!=NULL;count++,tmp=tmp->next);
    return count;
}

void displaylist(struct node*head){
    printf("\n");
    for(struct node*tmp=head;tmp!=NULL;tmp=tmp->next)
        printf("%d --> ",tmp->data);
    printf("NULL\n");
}


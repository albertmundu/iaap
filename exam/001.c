#include <stdio.h>
#include <stdlib.h>
#include <math.h>

struct node {
    int data;
    struct node*next;
};

struct node*createnode(int data){
    struct node*tmp=(struct node*)malloc(sizeof(struct node));
    tmp->data=data;
    tmp->next=NULL;
    return tmp;
}

void insert(struct node**head,int data){
    struct node*newnode=createnode(data);
    if(*head==NULL){
        *head=newnode;
    }
    else{
        newnode->next=*head;
        *head=newnode;
    }
}

void prt_list(struct node*head){
    for(struct node*tmp=head;tmp!=NULL;tmp=tmp->next)
        printf("%d->",tmp->data);
    printf("NULL\n");
}

struct node* reverse(struct node**head,struct node*tmp){
    if(tmp->next==NULL){
        *head=tmp;
        return tmp;
    }
    struct node*t=reverse(head,tmp->next);
    t->next=tmp;
    tmp->next=NULL;
    return tmp;
}

void split2(struct node**head){
    struct node*tmp=*head,*head2=NULL,*pnode=NULL;
    int v1,v2;
    for(;tmp!=NULL;tmp=tmp->next,free(pnode)){
        pnode=tmp;
        if(tmp->data!=0 && tmp->data!=1 && tmp->data!=-1){
            v1=(tmp->data)/2;
            v2=(tmp->data)-v1;
            insert(&head2,v1);
            insert(&head2,v2);
        }
        else{
            insert(&head2,tmp->data);
        }
    }
    *head=head2;
}

void split(struct node**head){
    struct node*tmp=*head,*head2=NULL,*pnode=NULL;
    int v1,v2,mod;
    for(;tmp!=NULL;tmp=tmp->next,free(pnode)){
        pnode=tmp;
        if(tmp->data!=0 && tmp->data!=1 && tmp->data!=-1){
            mod=(tmp->data)%2;
            v1=((tmp->data)/2)+mod;
            v2=(tmp->data)/2;
            insert(&head2,v1);
            insert(&head2,v2);
        }
        else{
            insert(&head2,tmp->data);
        }
    }
    *head=head2;
}

int main(){
    struct node*head=NULL;
    int n,data;
    scanf("%d",&n);
    for(int i=0;i<n;i++)
    {
        scanf("%d",&data);
        insert(&head,data);
    }
    prt_list(head);
    reverse(&head,head);
    split(&head);
    prt_list(head);
    return 0;
}

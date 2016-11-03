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

int sum(struct node*head){
    struct node*tmp=head,*pnode=createnode(0);
    int s=0;
    for(;;tmp=tmp->next){
        if(tmp->next!=NULL){
            s+=(pnode->data + tmp->data)*tmp->next->data;
        }
        else{
            s+=(pnode->data + tmp->data)*1;
            break;
        }
        pnode=tmp;
    }
    return s;
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
   printf("%d\n",sum(head));
    //prt_list(head);
    return 0;
}

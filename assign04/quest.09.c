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
void displayreverse(struct node*tail);
int getmin(struct node*head);
void delmin(struct node**head);

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
        //new_node->next=*head;
        *tail=new_node;
    }
}

void displaylist(struct node*head){
    for(struct node*tmp=head;tmp!=NULL;tmp=tmp->next)
        printf("%d -> ",tmp->data);
    printf("NULL\n");
}
void displayreverse(struct node*tail){
    for(struct node*tmp=tail;tmp!=NULL;tmp=tmp->prev)
        printf("%d -> ",tmp->data);
    printf("NULL\n");
}

int getmin(struct node*head){
    struct node*tmp=head;
    int min=tmp->data;
    do {
        if(min>tmp->data)
            min=tmp->data;
        tmp=tmp->next;
    }while(tmp!=NULL);
    return min;
}

void delmin(struct node**head){
    int min=getmin(*head);
    struct node*tmp=NULL,*p=NULL;
    for(tmp=*head;tmp!=NULL && min!=tmp->data;p=tmp,tmp=tmp->next);
    if(tmp!=*head){
        if(tmp->next==NULL){
            p->next=NULL;
        }
        else {
            p->next=tmp->next;
            tmp->next->prev=p;
        }
        free(tmp);
    }
    else if(tmp==*head) {
        if(tmp->next==NULL){
            *head=NULL;
        }
        else{
            *head=(*head)->next;
            (*head)->prev=NULL;
            free(tmp);
        }
    }
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
    printf("min = %d\n",getmin(head));
    delmin(&head);
    displaylist(head);
    return 0;
}

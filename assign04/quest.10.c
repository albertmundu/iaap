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
//struct node* reverse(struct node**head,struct node**tail);

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



void reverse(struct node**head,struct node**tail){
    struct node*tmp=*head,*tmp_pp=NULL,*pp=NULL;
    for(;tmp!=NULL;){
        pp=tmp;
        if(tmp==*head){
            tmp->prev=tmp->next;
            tmp->next=NULL;
            *tail=tmp;
        }
        else{
            tmp_pp=tmp->prev;
            tmp->prev=tmp->next;
            tmp->next=tmp_pp;
        }
        tmp=tmp->prev;
    }
    *head=pp;
}

/*struct node*reverse(struct node**head,struct node**tail,struct node*tmp){
    if(tmp->next==NULL){
        *head=tmp;
    }
}*/

int main(){
    struct node*head=NULL,*tail=NULL;
    int n,data;
    scanf("%d",&n);

    for(int i=0;i<n;i++){
        scanf("%d",&data);
        insert(&head,&tail,data);
    }
    displaylist(head);
    reverse(&head,&tail);
    displaylist(head);
    return 0;
}

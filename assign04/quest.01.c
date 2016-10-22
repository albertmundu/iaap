#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node*next;
};


struct node*createnode(int data);
void insertatbeg(struct node**head,int data);
void insertatend(struct node**head,int data);
void insertatposition(struct node**head,int data,int position);
void displaylist(struct node*head);
void menu();

int main(){
    int choice,data,position;
    struct node*head=NULL;
    struct node*tail=NULL;

    while(1){
        menu();
        scanf("%d",&choice);
        switch(choice){
            case 1:
                printf("\nvalue: ");
                scanf("%d",&data);
                insertatbeg(&head,data);
                break;
            case 2:
                printf("\nvalue: ");
                scanf("%d",&data);
                insertatend(&head,data);
                break;
            case 3:
                printf("\nvalue: ");
                scanf("%d",&data);
                printf("position: ");
                scanf("%d",&position);
                insertatposition(&head,data,position);
                break;
            case 4:
                displaylist(head);
                break;
            case 5:
                exit(0);
                break;
            default:
                break;
        }
    }
    return 0;
}


struct node*createnode(int data){
    struct node*tmp=(struct node*)malloc(sizeof(struct node));
    tmp->data=data;
    tmp->next=NULL;
    return tmp;
}

void insertatbeg(struct node**head,int data){
    struct node*new_node=createnode(data);;
    if(*head==NULL){
        
        *head=new_node;
    }
    else{
        new_node->next=(*head);
        *head=new_node;
    }
}

void insertatend(struct node**head,int data){
    struct node*new_node=createnode(data);
    if(*head==NULL){
        *head=new_node;
    }
    else{
        struct node*tmp=NULL;
        for(tmp=*head;tmp->next!=NULL;tmp=tmp->next);
        tmp->next=new_node;
    }

}

void insertatposition(struct node**head,int data,int position){
    struct node*tmp=NULL,*prev=NULL;
    struct node*new_node=createnode(data);
    int count=1;
    if(position!=1){
        for(tmp=*head;tmp!=NULL && count!=position;prev=tmp,tmp=tmp->next,count++);
        new_node->next=tmp;
        prev->next=new_node;
    }
    else if(position<=1){
        new_node->next=*head;
        *head=new_node;
    }
}

void displaylist(struct node*head){
    printf("\n");
    for(struct node*tmp=head;tmp!=NULL;tmp=tmp->next)
        printf("%d -> ",tmp->data);
    printf("NULL\n");
}

void menu(){
    printf("\n");
    printf("1 --> insert at beginning\n");
    printf("2 --> insert at the end\n");
    printf("3 --> insert at the key value\n");
    printf("4 --> display the list\n");
    printf("5 --> quit the application\n");
    printf("$ --> ");
}

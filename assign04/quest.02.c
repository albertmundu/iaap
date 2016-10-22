#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node*next;
};

struct node*createnode(int data);
void insert(struct node**head,int data);
void displaylist(struct node*head);
void deleteatbeg(struct node**head);
void deleteatend(struct node**head);
void deleteatpos(struct node**head,int pos);
void menu();

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
        struct node*tmp=NULL;
        for(tmp=*head;tmp->next!=NULL;tmp=tmp->next);
        tmp->next=new_node;
    }
}

void displaylist(struct node*head){
    printf("\n");
    for(struct node*tmp=head;tmp!=NULL;tmp=tmp->next)
        printf("%d -> ",tmp->data);
    printf("NULL\n");
}

void deleteatbeg(struct node**head){
    if(*head!=NULL){
        struct node*tmp=*head;
        *head=(*head)->next;
        free(tmp);
    }
}

void deleteatend(struct node**head){
    if(*head!=NULL){
        struct node*tmp=*head,*prev=NULL;
        for(;tmp->next!=NULL;prev=tmp,tmp=tmp->next);
        if(tmp==*head){
            *head=NULL;
        }
        else{
            prev->next=NULL;
            free(tmp);
        }
    }
}

void deleteatpos(struct node**head,int pos){
    if(*head!=NULL){
        int count=1;
        if(pos<=1){
            struct node*tmp=*head;
            *head=(*head)->next;
            free(tmp);
        }
        else{
            struct node*tmp=*head,*prev=NULL;
            for(;tmp->next!=NULL && count!=pos;prev=tmp,count++,tmp=tmp->next);
            if(tmp==*head){
                *head=NULL;
            }
            else{
                prev->next=tmp->next;
                free(tmp);
            }
        }
    }
}

void menu(){
    printf("\n");
    printf("1 --> insert\n");
    printf("2 --> display\n");
    printf("3 --> delete at the beginning\n");
    printf("4 --> delete at the end\n");
    printf("5 --> delete at the specified position\n");
    printf("6 --> quit the application\n");
    printf("$ --> ");
}

int main(){
    struct node*head=NULL;
    int data,choice,pos;

    while(1){
        menu();
        scanf("%d",&choice);
        switch(choice){
            case 1:
                printf("\nvalue: ");
                scanf("%d",&data);
                insert(&head,data);
                break;
            case 2:
                displaylist(head);
                break;
            case 3:
                deleteatbeg(&head);
                break;
            case 4:
                deleteatend(&head);
                break;
            case 5:
                printf("\nposition: ");
                scanf("%d",&pos);
                deleteatpos(&head,pos);
                break;
            case 6:
                exit(0);
            default:
                break;
        }
    }
    return 0;
}


















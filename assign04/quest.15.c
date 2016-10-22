#include <stdio.h>
#include <stdlib.h>
#include <string.h>

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

void insert(struct node**head,struct node**tail,int data){
    struct node*new_node=createnode(data);
    if(*head==NULL){
        *head=new_node;
        *tail=new_node;
    }
    else{
        (*tail)->next=new_node;
        *tail=new_node;
    }
}

void displaylist(struct node*head){
    struct node*tmp=head;
    for(;tmp!=NULL;tmp=tmp->next)
        printf("%d -> ",tmp->data);
    puts("NULL");
}

void input(struct node**head,struct node**tail){ 
    char *p;
    int data;
    char buffer[100];
    fgets(buffer,100,stdin);
    p=strtok(buffer," ->NULL\n");
    while(p!=NULL){
        sscanf(p,"%d",&data);
        insert(head,tail,data);
        p=strtok(NULL," ->NULL\n");
    }
}
int main(){
    struct node*head=NULL,*tail=NULL;
    input(&head,&tail);
    displaylist(head);

    displaylist(head);
}


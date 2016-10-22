#include <stdio.h>
#include <stdlib.h>
#include <string.h>


struct node {
    int data;
    struct node *next;
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
    else {
        (*tail)->next=new_node;
        *tail=new_node;
        new_node->next=*head;
    }
}


void mulofk(struct node*head,int k){
    struct node*tmp=head,*h=NULL;
    int count=0;
    while(1){
        if(count%k == 0){
            if(h==head)
                break;
            printf("%d -> ",tmp->data);
        }
        count++;
        tmp=tmp->next;
        h=tmp;
    }
    puts("NULL");
}

void displaylist(struct node*head){
    struct node*tmp=head;
    do {
        printf("%d -> ",tmp->data);
        tmp=tmp->next;
    }while(tmp!=head);
    puts("NULL");
    
}

int main(){
    struct node*head=NULL,*tail=NULL;
    int k,data;
    char buffer[100];
    char *p;

    fgets(buffer,100,stdin);
    p=strtok(buffer," abcdefghijklmnopqrstuvwxyz=\n");
    sscanf(p,"%d",&k);

    fgets(buffer,100,stdin);
    p=strtok(buffer," ->NULL\n");
    while(p!=NULL){
        sscanf(p,"%d",&data);
        insert(&head,&tail,data);
        p=strtok(NULL," ->NULL\n");
    }
    //displaylist(head);
    mulofk(head,k);



}

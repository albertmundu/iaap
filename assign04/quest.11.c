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

void deletexofk(struct node**head,int k){
    int count=0;
    struct node*tmp=*head,*pn=*head;
    for(;tmp!=NULL;count++,tmp=tmp->next){
        if(tmp!=*head && (count%k)==0){
            pn->next=tmp;
            pn=tmp;
        }
    }
}
int main(){
    struct node*head=NULL,*tail=NULL;
    char *p;
    int data,k;
    char buffer[100];
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
    displaylist(head);

    deletexofk(&head,k);
    displaylist(head);
}


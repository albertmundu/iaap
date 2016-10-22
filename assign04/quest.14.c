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


struct node* recursion(struct node**head,struct node*tmp){
    if(tmp->next==NULL){
        *head=tmp;
        return tmp;
    }
    struct node*t=recursion(head,tmp->next);
    t->next=tmp;
    tmp->next=NULL;
    return tmp;
}

struct node*gethead(struct node*head){
    return head;
}

void reverse(struct node**head,int k){
    struct node*tmp=NULL,*nhead=*head,*t=NULL,*pn=NULL,*harr[10];
    int count=1;
    int i=0;
    while(1){
        harr[i++]=nhead;
        count=1;
        for(tmp=nhead;tmp!=NULL && count%k!=0;count++,tmp=tmp->next);
        if(tmp==NULL)
            break;
        nhead=tmp->next;
        tmp->next=NULL;
    }
    for(int j=0;j<i;j++){
        t=recursion(&harr[j],harr[j]);
            if(pn!=NULL)
                pn->next=*(&harr[j]);
        //displaylist(harr[0]);
        pn=t;
    }
    *head=harr[0];

}

int main(){
    struct node*head=NULL,*tail=NULL;
    char *p;
    int data;
    char buffer[100];
    fgets(buffer,100,stdin);
    p=strtok(buffer," ->NULL\n");
    while(p!=NULL){
        sscanf(p,"%d",&data);
        insert(&head,&tail,data);
        p=strtok(NULL," ->NULL\n");
    }
    displaylist(head);

    reverse(&head,4);
    displaylist(head);
}


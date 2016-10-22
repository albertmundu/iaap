#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node*next;
};

struct node*createnode(int data);
void insert(struct node**head,struct node**tail,int data);
void displaylist(struct node*head);
int getmax(struct node*head);
int getmin(struct node*head);

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
    printf("\n");
    for(struct node*tmp=head;tmp!=NULL;tmp=tmp->next)
        printf("%d --> ",tmp->data);
    printf("NULL\n");
}

int getmax(struct node*head){
    int max=0;
    for(struct node*tmp=head;tmp!=NULL;tmp=tmp->next){
        if(max<tmp->data)
            max=tmp->data;
    }
    return max;
}

int getmin(struct node*head){
    int min=999999;
    for(struct node*tmp=head;tmp!=NULL;tmp=tmp->next){
        if(min>tmp->data)
            min=tmp->data;
    }
    return min;
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
    printf("maximum: %d\n",getmax(head));
    printf("minimum: %d\n",getmin(head));
    printf("maximun-minimum: %d\n",getmax(head)-getmin(head));
}

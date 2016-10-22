#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node*next;
};

struct node*createnode(int data);
void insert(struct node**head,struct node**tail,int data);
void displaylist(struct node*head);
int sumofeven(struct node*head);

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
        new_node->next=*head;
        *tail=new_node;
    }
}

void displaylist(struct node*head){
    printf("\n");
    struct node*tmp=head;
    do{
        printf("%d -> ",tmp->data);
        tmp=tmp->next;
    }while(tmp!=head);
    printf("head\n");
}

int sumofeven(struct node*head){
    int sum=0;
    struct node*tmp=head;
    do{
        if(!(tmp->data & 1)){
            sum+=tmp->data;
        }
        tmp=tmp->next;
    }while(tmp!=head);
    return sum;
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
    printf("sum = %d\n",sumofeven(head));
        


return 0;
}

#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *next;
};

struct node * createnode(int data){
    struct node*tmp=malloc(sizeof(struct node));
    tmp->data=data;
    tmp->next=NULL;
    return tmp;
}

void insert(struct node**head,struct node**tail,int data){
    struct node*newnode=createnode(data);
    if(*head==NULL)
    {
        *head=newnode;
        *tail=newnode;
    }
    else {
        (*tail)->next=newnode;
        *tail=newnode;
    }
}

void prt_list(struct node*head){
    for(struct node*tmp=head;tmp!=NULL;tmp=tmp->next)
        printf("%d -> ",tmp->data);
    printf("NULL\n");
}

void merge(struct node**merge_head,struct node*head1,struct node*head2){
    struct node*tail=NULL;
    while(head1!=NULL || head2!=NULL){
        if(head1!=NULL && head2!=NULL){
            if(head1->data < head2->data){
                insert(merge_head,&tail,head1->data);
                head1=head1->next;
            }
            else {
                insert(merge_head,&tail,head2->data);
                head2=head2->next;
            }
        }
        else if(head1==NULL && head2!=NULL){
               insert(merge_head,&tail,head2->data);
               head2=head2->next;
        }
        else if(head1!=NULL && head2==NULL){
                insert(merge_head,&tail,head1->data);
                head1=head1->next;
        }
    }
}

int main(){
    struct node*head1=NULL,*tail1=NULL,*head2=NULL,*tail2=NULL;
    struct node*merge_head=NULL;
    int n,data;
    scanf("%d",&n);
    for(int i=0;i<n;i++){
        scanf("%d",&data);
        insert(&head1,&tail1,data);
    }
    prt_list(head1);
    scanf("%d",&n);
    for(int i=0;i<n;i++){
        scanf("%d",&data);
        insert(&head2,&tail2,data);
    }
    prt_list(head2);
    merge(&merge_head,head1,head2);
    prt_list(merge_head);
    
}


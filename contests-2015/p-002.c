#include <stdio.h>
#include <stdlib.h>

struct node {
    int index;
    int data;
    int friend_index;
    struct node*next;
    struct node*friend;
};


struct node* getnode(int data,int index,int friend_index){
    struct node*tmp=(struct node*)malloc(sizeof(struct node));
    tmp->data=data;
    tmp->index=index;
    tmp->friend_index=friend_index;
    tmp->next=NULL;
    tmp->friend=NULL;
    return tmp;
}

void display(struct node*head){
    struct node*tmp=head;
    for(;tmp!=NULL;tmp=tmp->next){
        printf("%d. %d %d f->%d\n",tmp->index,tmp->data,tmp->friend_index,tmp->friend->data);
    }
}

int main(){

    struct node*head=NULL;
    struct node*new_node=NULL;
    struct node*prev_node=NULL;

    int n,i,value,index,friend_index;
    scanf("%d",&n);

    for(i=0;i<n;i++){
        index=i+1;
        scanf("%d%d",&value,&friend_index);
        new_node=getnode(value,index,friend_index);
        if(head==NULL){
            head=new_node;
            prev_node=new_node;
        }
        else{
            prev_node->next=new_node;
            prev_node=new_node;
        }
    }
    

    struct node*tmp=head;
    struct node*tmp2=head;
    for(;tmp!=NULL;tmp=tmp->next){
        for(tmp2=head;tmp2!=NULL;tmp2=tmp2->next){
            if(tmp->friend_index==tmp2->index){
                tmp->friend=tmp2;
                break;
            }
        }
    }
    
    display(head);
    return 0;
}

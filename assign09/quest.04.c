#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    int rank;
    struct node*parent;
};

struct pool {
    int key;//not required
    struct node*value;
    struct pool*next;
};
struct pool *head=NULL;

struct pool*createpool(int key,struct node*value){
    struct pool*tmp=(struct pool*)malloc(sizeof(struct pool));
    tmp->key=key;
    tmp->value=value;
    tmp->next=NULL;
    return tmp;
}

void insert(int key, struct node*value){
    if(head==NULL){
        head=createpool(key,value);
    }
    else {
        struct pool*tmp=head;
        for(;tmp->next!=NULL;tmp=tmp->next);
        tmp->next=createpool(key,value);
    }
}

struct node*get(int data){
    struct pool*tmp=head;
    for(;tmp!=NULL;tmp=tmp->next){
        if(tmp->value->data==data)//if(tmp->key==data) 
            return tmp->value;
    }
    return NULL;
}

struct node*createnode(int data){
    struct node*tmp=(struct node*)malloc(sizeof(struct node));
    tmp->rank=0;
    tmp->data=data;
    tmp->parent=NULL;
    return tmp;
}

void makeset(int data){
    struct node*tmp=createnode(data);
    tmp->parent=tmp;
    insert(data,tmp);
}

struct node*findset(struct node*item){
    struct node*p=item->parent;
    if(p == item)
        return p;
    item->parent=findset(item->parent);//path compression
    return item->parent;
}
int findsetbyelement(int data){
    return findset(get(data))->data;
}

void unionset(int data1,int data2){ //union by rank
    struct node*n1=get(data1);
    struct node*n2=get(data2);
    struct node*p1=findset(n1);
    struct node*p2=findset(n2);
    if(p1->data==p2->data)  
        return;
    if(p1->rank >= p2->rank)
    {
        p1->rank=(p1->rank == p2->rank)?p1->rank+1:p1->rank;
        p2->parent=p1;
    }
    else {
        p1->parent=p2;
    }

}


int main(){
    for(int i=0;i<10;i++)
        makeset(i);
    unionset(1,5);
    unionset(3,7);
    unionset(1,4);
    unionset(5,7);
    unionset(0,8);
    unionset(6,9);
    unionset(3,9);

    for(int i=0;i<10;i++){
        struct node*p=get(i);
        printf("%d -> %d -> %d\n",i,p->parent->data,findsetbyelement(i));
    }
}

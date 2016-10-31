#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node * left;
    struct node * right;
};

struct node * createnode(int data){
    struct node*tmp=malloc(sizeof(struct node));
    tmp->data=data;
    tmp->left=NULL;
    tmp->right=NULL;
    return tmp;
}

void insert(struct node**root,int data){
    struct node*newnode=createnode(data);
    if(*root==NULL){
        *root=newnode;
    }
    else
    {
        struct node*parent=NULL,*child=*root;
        for(;child!=NULL;){
            parent=child;
            if(data <= child->data)
                child=child->left;
            else
                child=child->right;
        }
        if(data <= parent->data)
            parent->left=newnode;
        else
            parent->right=newnode;
    }
}

void knode(struct node*root,int k){
    if(root){
        if(k==0){
            printf("%d ",root->data);
            return;
        }
        knode(root->left,k-1);
        knode(root->right,k-1);
            
    }
}


int main(){
    struct node*root=NULL;
    int n,key,data;
    scanf("%d%d",&n,&key);
    for(int i=0;i<n;i++){
        scanf("%d",&data);
        insert(&root,data);
    }
    knode(root,key);
}

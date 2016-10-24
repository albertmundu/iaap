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


int successor(struct node*root,int key){
    struct node*child=NULL,*parent=NULL;
    int suc=-1;
    for(child=root;child!=NULL;){
        parent=child;
        if(key == child->data){
            break;
        }
        if(key < child->data)
            child=child->left;
        else
            child=child->right;
    }
    if(child!=NULL){
        child=parent->right;
        for(;child!=NULL;){
            suc=child->data;
            child=child->left;
        }
    }
    return suc;
}

int predecessor(struct node*root,int key){
    struct node*child=NULL,*parent=NULL;
    int pred=-1;
    for(child=root;child!=NULL;){
        parent=child;
        if(key == child->data){
            break;
        }
        if(key < child->data)
            child=child->left;
        else
            child=child->right;
    }
    if(child!=NULL){
        child=parent->left;
        for(;child!=NULL;){
            pred=child->data;
            child=child->right;
        }
    }
    return pred;

}
int main(){
    struct node*root=NULL;
    int n,key,data;
    scanf("%d%d",&n,&key);
    for(int i=0;i<n;i++){
        scanf("%d",&data);
        insert(&root,data);
    }
    printf("%d\n",successor(root,key));
    printf("%d\n",predecessor(root,key));
}

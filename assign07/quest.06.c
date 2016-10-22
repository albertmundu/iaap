#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node*left;
    struct node*right;
};

struct node*createnode(int data){
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
    else{
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
        else parent->right=newnode;
    }
}

void post_order(struct node*root,unsigned *counter){
    if(root){
        post_order(root->left,counter);
        post_order(root->right,counter);
        if(root->left==root->right)
            *counter=*counter+root->data;
    }
}

int main(){
    struct node*root=NULL;
    int n,data;
    unsigned counter=0;
    scanf("%d",&n);
    while(n--){
        scanf("%d",&data);
        insert(&root,data);
    }
    post_order(root,&counter);
    printf("%d\n",counter);
    return 0;
}

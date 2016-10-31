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

void ancestorsk(struct node*root,int k){
    if(root){
        if(k == root->data)
            return;
        printf("%d ",root->data);
        if(k <= root->data)
            ancestorsk(root->left,k);
        else
            ancestorsk(root->right,k);
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
    ancestorsk(root,key);
    printf("\n");
    return 0;
}

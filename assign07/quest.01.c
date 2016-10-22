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
    struct node*new_node=createnode(data);
    if(*root==NULL)
        *root=new_node;
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
            parent->left=new_node;
        else
            parent->right=new_node;

    }
}

int search(struct node*root,int k){
    struct node*child=root;
    for(;child!=NULL;){
        if(k == child->data)
            return 1;
        if(k <= child->data)
            child=child->left;
        else
            child=child->right;
    }
    return 0;
}

int main(){
    struct node*root=NULL;
    int n,data;
    scanf("%d",&n);
    while(n--){
        scanf("%d",&data);
        insert(&root,data);
    }
    scanf("%d",&n);
    while(n--){
        scanf("%d",&data);
        if(search(root,data))
            printf("y\n");
        else
            printf("n\n");
    }
    return 0;
}

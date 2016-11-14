#include <stdio.h>
#include <stdlib.h>


struct node {
    int data;
    int height;
    struct node *left;
    struct node *right;
};

struct node*createnode(int data){
    struct node*tmp=(struct node*)malloc(sizeof(struct node));
    tmp->data=data;
    tmp->height=1;
    tmp->left=NULL;
    tmp->right=NULL;
    return tmp;
}

int max(int a,int b){
    return (a>b)?a:b;
}

int get_height(struct node*root){
    if(root)
        return root->height;
    return 0;
}

int get_balance_factor(struct node*root){
    return get_height(root->left)-get_height(root->right);
}


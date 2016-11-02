#include <stdio.h>
#include <stdlib.h>


struct node {
    int data;
    struct node * left;
    struct node * right;
};

#define swap(a,b){struct node*t=a;a=b;b=t;}

struct node* createnode(int data){
    struct node*tmp=malloc(sizeof(struct node));
    tmp->data=data;
    tmp->left=NULL;
    tmp->right=NULL;
    return tmp;
}

void insert(struct node **root,int data){
    struct node*newnode=createnode(data);
    if(*root==NULL)
        *root=newnode;
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
        else
            parent->right=newnode;
    }
}
void mirror(struct node*root){
    if(root){
        mirror(root->left);
        mirror(root->right);
        swap(root->left,root->right);
    }
}

void inorder_traversal(struct node*root){
    if(root){
        inorder_traversal(root->left);
        printf("%d ",root->data);
        inorder_traversal(root->right);
    }
}

int main(){
    struct node*root=NULL;
    int n,data;
    scanf("%d",&n);
    for(int i=0;i<n;i++)
    {
        scanf("%d",&data);
        insert(&root,data);
    }
    inorder_traversal(root);
    mirror(root);
    inorder_traversal(root);
    printf("\n");
    return 0;
}

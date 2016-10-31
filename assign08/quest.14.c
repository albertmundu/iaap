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

void inorder_traversal(struct node*root){
    if(root){
        inorder_traversal(root->left);
        printf("%d ",root->data);
        inorder_traversal(root->right);
    }
}
void terminal_delete(struct node*root,struct node*parent){
    if(root){
        if(root->left==root->right){
            if(parent->left == root)
                parent->left = NULL;
            else if(parent->right == root)
                parent->right = NULL;
            free(root);
        }
        terminal_delete(root->left,root);
        terminal_delete(root->right,root);
    }
}

int main(){
    struct node*root=NULL;
    int n,data;
    scanf("%d",&n);
    for(int i=0;i<n;i++){
        scanf("%d",&data);
        insert(&root,data);
    }
    terminal_delete(root,NULL);
    inorder_traversal(root);
    printf("\n");
    return 0;
}

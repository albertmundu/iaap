#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node*left;
    struct node*right;
};

struct node *createnode(int data){
    struct node*tmp=(struct node*)malloc(sizeof(struct node));
    tmp->data=data;
    tmp->right=NULL;
    tmp->left=NULL;
    return tmp;
}

struct node*insert(struct node*root,int data){
    if(root==NULL)
        return createnode(data);
    if(data <= root->data)
        root->left=insert(root->left,data);
    else
        root->right=insert(root->right,data);
    return root;
}

struct node*left_rotate(struct node*root){
    struct node*r=root->right;
    struct node*rl=r->left;
    r->left=root;
    root->right=rl;
    return r;
}

void preorder(struct node*root){
    if(root){
        printf("%d ",root->data);
        preorder(root->left);
        preorder(root->right);
    }
}
void inorder(struct node*root){
    if(root){
        inorder(root->left);
        printf("%d ",root->data);
        inorder(root->right);
    }
}


int main(){
    int n,data;
    struct node*root=NULL;
    scanf("%d",&n);
    for(int i=0;i<n;i++){
        scanf("%d",&data);
        root=insert(root,data);
    }
    inorder(root);
    printf("\n");
    root=left_rotate(root);
    preorder(root);
    printf("\n");
    return 0;
}

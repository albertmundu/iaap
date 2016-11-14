#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node*left;
    struct node*right;
};

struct node*createnode(int data){
    struct node*tmp=(struct node*)malloc(sizeof(struct node));
    tmp->data=data;
    tmp->left=NULL;
    tmp->right=NULL;
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

struct node*right_rotate(struct node*root){
    struct node*l=root->left;
    struct node*lr=l->right;
    l->right=root;
    root->left=lr;
    return l;
}
void inorder(struct node*root){
    if(root){
        inorder(root->left);
        printf("%d ",root->data);
        inorder(root->right);
    }
}
void preorder(struct node*root){
    if(root){
        printf("%d ",root->data);
        preorder(root->left);
        preorder(root->right);
    }
}

int main(){
    struct node*root=NULL;
    int n,data;
    scanf("%d",&n);
    for(int i=0;i<n;i++){
        scanf("%d",&data);
        root=insert(root,data);
    }
    inorder(root);
    printf("\n");
    root=right_rotate(root);
    preorder(root);
    printf("\n");
    return 0;
}

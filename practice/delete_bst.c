#include <stdio.h>
#include <stdlib.h>


typedef struct node {
    int data;
    struct node *left;
    struct node *right;
} node_t;

node_t* createnode(int data){
    node_t*tmp=(node_t*)malloc(sizeof(node_t));
    tmp->data=data;
    tmp->right=NULL;
    tmp->left=NULL;
    return tmp;
}

node_t* insert(node_t*root,int data){
    if(root==NULL)
        return createnode(data);
    if(data <= root->data)
        root->left=insert(root->left,data);
    else
        root->right=insert(root->right,data);
    return root;
}
node_t* find_minimum(node_t*root){
    while(root->left!=NULL)
        root=root->left;
    return root;
}
node_t* delete(node_t*root,int key){
    if(root==NULL)
        return root;
    if(key < root->data)
        root->left=delete(root->left,key);
    else if(key > root->data)
        root->right=delete(root->right,key);
    else {
        if(root->left==root->right){
            free(root);
            root=NULL;
        }
        else if(root->left==NULL){
            node_t*tmp=root;
            root=root->right;
            free(tmp);
        }
        else if(root->right==NULL){
            node_t*tmp=root;
            root=root->left;
            free(tmp);
        }
        else {
            node_t*min=find_minimum(root->right);
            root->data=min->data;
            root->right=delete(root->right,root->data);
        }
    }
    return root;
}

void preorder(node_t*root){
    if(root){
        printf("%d ",root->data);
        preorder(root->left);
        preorder(root->right);
    }
}

int main(){
    node_t*root=NULL;
    int n,data,k;
    scanf("%d",&n);
    while(n--){
        scanf("%d",&data);
        root=insert(root,data);
    }
    preorder(root);
    printf("\n");
    scanf("%d",&k);
    root=delete(root,k);
    preorder(root);
    printf("\n");
}

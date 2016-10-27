#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

struct node {
    int data;
    struct node * left;
    struct node * right;
};

struct node*createnode(int data){
    struct node*tmp=malloc(sizeof(struct node));
    tmp->data=data;
    tmp->left=NULL;
    tmp->right=NULL;
    return tmp;
}

struct node*make_binary_tree(int *arr,int index,int n){
    struct node*root=NULL;
    if(index<n && arr[index]!=-1){
        root=createnode(arr[index]);
        root->left=make_binary_tree(arr,2*index+1,n);
        root->right=make_binary_tree(arr,2*index+2,n);
    }
    return root;
}

void inorder_traversal(struct node*root){
    if(root){
        inorder_traversal(root->left);
        printf("%d ",root->data);
        inorder_traversal(root->right);
    }
}

int isBST(struct node*root,int min,int max){
    if(root){
        if(root->data > max || root->data < min)
            return 0;
        return isBST(root->left,min,root->data) && isBST(root->right,root->data,max);
        
    }
    return 1;
}

int main(){
    int n,*arr=NULL;
    scanf("%d",&n);
    arr=malloc(sizeof(int)*n);
    for(int i=0;i<n;i++)
        scanf("%d",&arr[i]);
    struct node*root=make_binary_tree(arr,0,n);
    inorder_traversal(root);
    printf("\n");
    if(isBST(root,INT_MIN,INT_MAX))
        printf("IS BST\n");
    else
        printf("IS NOT BST\n");
    return 0;
}

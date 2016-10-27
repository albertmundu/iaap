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

struct node* insert(struct node*root,int data){
    if(root==NULL){
        root=createnode(data);
    }
    else {
        if(data <= root->data)
            root->left=insert(root->left,data);
        else if(data > root->data)
            root->right=insert(root->right,data);
    }
    return root;
}

void delete_bst(struct node**root){
    if(*root){
        delete_bst(&((*root)->left));
        delete_bst(&((*root)->right));
        if((*root)->left==(*root)->right){
            //free(root);
            *root=NULL;
        }
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
    for(int i=0;i<n;i++){
        scanf("%d",&data);
        root=insert(root,data);
    }
    inorder_traversal(root);
    printf("\n");
    delete_bst(&root);
    inorder_traversal(root);
    printf("\n");
    return 0;
}

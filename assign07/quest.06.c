#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node*left;
    struct node*right;
};

struct node *create_node(int data){
    struct node*tmp=(struct node*)malloc(sizeof(struct node));
    tmp->data=data;
    tmp->left=NULL;
    tmp->right=NULL;
    return tmp;
}

struct node*make_binary_tree(int *arr,int index,int n){ //for building complete binary tree
    struct node*root=NULL;
    if(index<n){
        root=create_node(arr[index]);
        root->left=make_binary_tree(arr,2*index+1,n);
        root->right=make_binary_tree(arr,2*index+2,n);
    }
    return root;
}

void postorder_delete(struct node*root){
    if(root){
        postorder_delete(root->left);
        postorder_delete(root->right);
        free(root);
    }
}

int ismaxheap(struct node*root){
    if(root==NULL)//not required
        return 1;
    if(root->left==root->right || (root->left!=NULL && root->right==NULL && root->data>=root->left->data))
        return 1;
    else
        return 0;
    return (root->data >= root->left->data && root->data >= root->right->data) && ismaxheap(root->left) && ismaxheap(root->right);
}

int main(){
    int t,n,*arr=NULL;
    struct node*root=NULL;
    scanf("%d",&t);
    while(t--){
        scanf("%d",&n);
        arr=(int*)malloc(sizeof(int)*n);
        for(int i=0;i<n;i++)
            scanf("%d",&arr[i]);
        root=make_binary_tree(arr,0,n);
        if(ismaxheap(root))
            printf("yes\n");
        else
            printf("no\n");
        postorder_delete(root);
        free(arr);
        arr=NULL;
        root=NULL;
    }

}

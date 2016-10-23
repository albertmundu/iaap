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
    struct node*newnode=createnode(data);
    if(*root==NULL){
        *root=newnode;
    }
    else {
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

int find(int *arr,int s, int e,int k){
    for(int i=s;i<=e;i++)
        if(arr[i]==k)
            return i;
    return -1;
}

struct node*make_binary_tree(int*inorder,int*postorder,int in_start,int in_end,int post_start,int post_end){
    if(in_start > in_end || post_start > post_end)
        return NULL;

    int root_data=postorder[post_end];
    int root_index=find(inorder,in_start,in_end,root_data);
    struct node*root=createnode(root_data);

    if(in_start==in_end){
        return root;
    }
    root->left=make_binary_tree(inorder,postorder,in_start,root_index-1,post_start,post_start+root_index-(in_start+1));
    root->right=make_binary_tree(inorder,postorder,root_index+1,in_end,post_start+root_index-in_start,post_end-1);
    return root;
}

void inorder_traversal(struct node*root){
    if(root){
        inorder_traversal(root->left);
        printf("%d ",root->data);
        inorder_traversal(root->right);
    }

}


int main(){
    int *inorder=NULL,*postorder=NULL;
    int in,post;
    scanf("%d",&in);
    inorder=malloc(sizeof(int)*in);
    for(int i=0;i<in;i++)
        scanf("%d",&inorder[i]);

    scanf("%d",&post);
    postorder=malloc(sizeof(int)*post);
    for(int i=0;i<post;i++)
        scanf("%d",&postorder[i]);

    struct node*root=make_binary_tree(inorder,postorder,0,in-1,0,post-1);
    inorder_traversal(root);
    printf("\n");
    return 0;

}

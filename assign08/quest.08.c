#include <stdio.h>
#include <stdlib.h>


struct node {
    int data;
    struct node * left;
    struct node * right;
};

struct node* createnode(int data){
    struct node*tmp=malloc(sizeof(struct node));
    tmp->data=data;
    tmp->left=NULL;
    tmp->right=NULL;
    return tmp;
}

int find(int *arr,int start,int end,int key){
    for(int i=start;i<=end;i++)
        if(arr[i]==key)
            return i;
    return -1;
}
struct node*make_binary_tree(int *pre,int *post,int pre_start,int pre_end,int post_start,int post_end){
    if(pre_start > pre_end || post_start > post_end)
        return NULL;
    int root_data=pre[pre_start];
    struct node*root=createnode(root_data);
    pre_start++;
    if(post_start==post_end)
        return root;
    int next_root_index=find(post,post_start,post_end-1,pre[pre_start]);
    root->left=make_binary_tree(pre,post,pre_start,pre_start+next_root_index-post_start,post_start,next_root_index);
    root->right=make_binary_tree(pre,post,pre_start+next_root_index-post_start+1,pre_end,next_root_index+1,post_end-1);
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
    int n;
    int *pre=NULL,*post=NULL;
    scanf("%d",&n);
    pre=malloc(sizeof(int)*n);
    post=malloc(sizeof(int)*n);
    for(int i=0;i<n;i++)
        scanf("%d",&pre[i]);
    for(int i=0;i<n;i++)
        scanf("%d",&post[i]);
    struct node*root=make_binary_tree(pre,post,0,n-1,0,n-1);
    inorder_traversal(root);
    printf("\n");
    return 0;
}

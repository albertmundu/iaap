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

struct node*make_binary_tree(int*arr,int index,int n){
    struct node*root=NULL;
    if(index<n && arr[index]!=-1){
        root=createnode(arr[index]);
        root->left=make_binary_tree(arr,2*index+1,n);
        root->right=make_binary_tree(arr,2*index+2,n);
    }
    return root;
}

int isSumTree(struct node*root){
    if(root){
        int lsum=isSumTree(root->left);
        int rsum=isSumTree(root->right);
        int sum=lsum+rsum;
        if(root->left==root->right)
        {
            return root->data;
        }
        if(sum==root->data)
        {
            return root->data;
        }
    }
    return 0;
}
int checkSumTree(struct node*root){
    if(root->data==isSumTree(root))
        return 1;
    return 0;
}

int main(){
    struct node*root=NULL;
    int n,*arr=NULL;
    scanf("%d",&n);
    arr=(int*)malloc(sizeof(int)*n);
    for(int i=0;i<n;i++)
        scanf("%d",&arr[i]);
    root=make_binary_tree(arr,0,n);
    if(checkSumTree(root))
        printf("Yes\n");
    else
        printf("No\n");
    return 0;
}

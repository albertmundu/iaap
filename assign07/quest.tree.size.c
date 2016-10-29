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

struct node* insert(struct node*root,int data){
    if(root==NULL)
        root=createnode(data);
    else
    {
        if(data <=root->data)
            root->left=insert(root->left,data);
        else if(data > root->data)
            root->right=insert(root->right,data);
    }
    return root;
}


void size(struct node*root,int *count){
    if(root){
        size(root->left,count);
        (*count)++;
        size(root->right,count);
    }
}
int __size(struct node*root){
    static int count;
    if(root){
        __size(root->left);
        count++;
        __size(root->right);
    }
    return count;
}
int _size(struct node*root){
    if(root==NULL)
        return 0;
    else
        return _size(root->left) + _size(root->right) + 1;
}

int main(){
    struct node*root=NULL;
    int n,data;
    int count=0;
    scanf("%d",&n);
    for(int i=0;i<n;i++){
        scanf("%d",&data);
        root=insert(root,data);
    }
    size(root,&count);
    printf("%d\n",count);
    printf("%d\n",__size(root));
    printf("%d\n",_size(root));
    return 0;
}

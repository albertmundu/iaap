#include <stdio.h>
#include <stdlib.h>
#include <limits.h>


struct node {
    int data;
    struct node*left;
    struct node*right;
};

struct node * createnode(int data){
    struct node*tmp=(struct node*)malloc(sizeof(struct node));
    tmp->data=data;
    tmp->left=NULL;
    tmp->right=NULL;
    return tmp;
}

void insert(struct node**root,int data){
    if(*root==NULL)
        *root=createnode(data);
    else {
        struct node*parent=NULL,*child=*root;
        for(;child!=NULL;){
            parent=child;
            if(data <= parent->data)
                child=child->left;
            else if(data > parent->data)
                child=child->right;
        }
        if(data <= parent->data)
            parent->left=createnode(data);
        else if(data > parent->data)
            parent->right=createnode(data);
    }
}

int count(struct node*root,int data){
    struct node*child=root;
    int cnt=0;
    for(;child!=NULL;cnt++){
        if(data == child->data)
            return cnt;
        if(data < child->data)
            child=child->left;
        else if(data > child->data)
            child=child->right;
    }
    return -1;
}
struct node* common_ancestor(struct node*root,int k1,int k2){
    if(root==NULL)
        return NULL;

    if(k1<root->data && k2<root->data)
        return common_ancestor(root->left,k1,k2);
    else if(k1>root->data && k2>root->data)
        return common_ancestor(root->right,k1,k2);
    else
        return root;
}
int distance(struct node*root,int k1,int k2){
    struct node*common=common_ancestor(root,k1,k2);
    return count(common,k1)+count(common,k2);
}
int main(){
    struct node*root=NULL;
    int n,data,k1,k2;
    scanf("%d",&n);
    while(n--){scanf("%d",&data);insert(&root,data);}
    scanf("%d%d",&k1,&k2);
    printf("%d\n",distance(root,k1,k2));
    return 0;
}

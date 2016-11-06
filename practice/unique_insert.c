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

void insert(struct node**root,int data){
    if(*root==NULL)
        *root=createnode(data);
    else {
        struct node*child=*root,*parent=NULL;
        for(;child!=NULL;){
            parent=child;
            if(data == parent->data)
                return;
            if(data < parent->data)
                child=child->left;
            else
                child=child->right;
        }
        if(data < parent->data)
            parent->left=createnode(data);
        else
            parent->right=createnode(data);
    }
}


void inorder(struct node*root){
    if(root){
        inorder(root->left);
        printf("%d ",root->data);
        inorder(root->right);
    }
}

int count(struct node*root){
    if(root){
        return count(root->left)+count(root->right)+1;
    }
    return 0;
}

int main(){
    struct node*root=NULL;
    int n,data;
    scanf("%d",&n);
    while(n--){
        scanf("%d",&data);
        insert(&root,data);
    }
    inorder(root);
    printf("\n");
    printf("No. of unique elements: %d\n",count(root));
    return 0;
}

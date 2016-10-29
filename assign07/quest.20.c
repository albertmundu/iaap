/**Depth First Search**/
#include <stdio.h>
#include <stdlib.h>
#define nl printf("\n")
struct node {
    int data;
    struct node*left;
    struct node*right;
};

struct node*insert(struct node*root,int data);
struct node* createnode(int data);
void inorder(struct node*root);
void postorder(struct node*root);
void preorder(struct node*root);

int main(){
    struct node*root=NULL;
    int n,data;
    scanf("%d",&n);
    for(int i=0;i<n;i++)
    {
        scanf("%d",&data);
        root=insert(root,data);
    }
    inorder(root);nl;
    postorder(root);nl;
    preorder(root);nl;
    return 0;
}

struct node*createnode(int data){
    struct node*tmp=(struct node*)malloc(sizeof(struct node));
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

void inorder(struct node*root){
    if(root){
        inorder(root->left);
        printf("%d ",root->data);
        inorder(root->right);
    }
}
void postorder(struct node*root){
    if(root){
        postorder(root->left);
        postorder(root->right);
        printf("%d ",root->data);
    }
}
void preorder(struct node*root){
    if(root){
        printf("%d ",root->data);
        preorder(root->left);
        preorder(root->right);
    }
}

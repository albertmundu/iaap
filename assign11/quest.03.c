#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    int height;
    struct node*left;
    struct node*right;
};

struct node*createnode(int data){
    struct node*tmp=(struct node*)malloc(sizeof(struct node));
    tmp->data=data;
    tmp->left=NULL;
    tmp->right=NULL;
    tmp->height=1;
    return tmp;
}
int height(struct node*root){
    if(root)
        return root->height;
    return 0;
}
int max(int a,int b){
    return (a > b) ? a : b;
}

struct node*right_rotate(struct node*root){
    struct node*l=root->left;
    struct node*lr=l->right;
    l->right=root;
    root->left=lr;

    root->height=max(height(root->left),height(root->right))+1;
    l->height=max(height(l->left),height(l->right))+1;
    return l;
}

struct node*left_rotate(struct node*root){
    struct node*r=root->right;
    struct node*rl=r->left;
    //perform rotation
    r->left=root;
    root->right=rl;

    //update heights
    root->height=max(height(root->left),height(root->right))+1;
    r->height=max(height(r->left),height(r->right))+1;
    return r;
}

int get_balance_factor(struct node*root){
    if(root){
        return height(root->left)-height(root->right);
    }
    return 0;
}
struct node*insert(struct node*root,int data){
    // perform normal bst insertion
    if(root==NULL)
        return createnode(data);
    if(data <= root->data)
        root->left=insert(root->left,data);
    else
        root->right=insert(root->right,data);
    //update the height of this ancestor node
    root->height=max(height(root->left),height(root->right))+1;

    int balance=get_balance_factor(root);

    //LL case
    if(balance > 1 && data < root->left->data)
        return right_rotate(root);
    //RR case
    if(balance < -1 && data > root->right->data)
        return left_rotate(root);
    //LR case
    if(balance > 1 && data > root->left->data)
    {
        root->left=left_rotate(root->left);
        return right_rotate(root);
    }

    //RL case
    if(balance < -1 && data < root->right->data){
        root->right=right_rotate(root->right);
        return left_rotate(root);
    }

    return root;
}

void preorder(struct node*root){
    if(root){
        printf("%d ",root->data);
        preorder(root->left);
        preorder(root->right);
    }
}
void inorder(struct node*root){
    if(root){
        inorder(root->left);
        printf("%d ",root->data);
        inorder(root->right);
    }
}
int main(){
    struct node*root=NULL;
    int n,data,t;
    scanf("%d",&t);
    while(t--){
        scanf("%d",&n);
        for(int i=0;i<n;i++){
            scanf("%d",&data);
            root=insert(root,data);
        }
        preorder(root);
        root=NULL;
        printf("\n");
    }
}

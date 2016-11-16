#include <stdio.h>
#include <stdlib.h>


typedef struct node {
    int data;
    int height;
    struct node *left;
    struct node *right;
} node_t;

node_t* createnode(int data){
    node_t*tmp=(node_t*)malloc(sizeof(node_t));
    tmp->data=data;
    tmp->right=NULL;
    tmp->left=NULL;
    tmp->height=0;
    return tmp;
}

int get_height(node_t*root)
{
    if(root)
        return root->height;
    return -1;
}

int max(int a,int b){
    return (a>b)?a:b;
}

int get_balance_factor(node_t*root){
    if(root)
        return get_height(root->left)-get_height(root->right);
    return 0;
}

node_t* right_rotate(node_t*root){
    node_t*l=root->left;
    node_t*lr=l->right;

    l->right=root;
    root->left=lr;

    root->height=max(get_height(root->left),get_height(root->right))+1;
    l->height=max(get_height(l->left),get_height(l->right))+1;
    return l;
}

node_t* left_rotate(node_t*root){
    node_t*r=root->right;
    node_t*rl=r->left;

    r->left=root;
    root->right=rl;

    root->height=max(get_height(root->left),get_height(root->right))+1;
    r->height=max(get_height(r->left),get_height(r->right))+1;
    return r;
}

node_t* insert(node_t*root,int data){
    if(root==NULL)
        return createnode(data);
    if(data <= root->data)
        root->left=insert(root->left,data);
    else
        root->right=insert(root->right,data);

    root->height=max(get_height(root->left),get_height(root->right))+1;
    int balance = get_balance_factor(root);

    if(balance > 1 && data <= root->left->data)
        return right_rotate(root);
    if(balance > 1 && data > root->left->data)
    {
        root->left=left_rotate(root->left);
        return right_rotate(root);
    }
    if(balance < -1 && data > root->right->data)
        return left_rotate(root);
    if(balance < -1 && data <= root->right->data)
    {
        root->right=right_rotate(root->right);
        return left_rotate(root);
    }
    return root;
}
node_t* find_minimum(node_t*root){
    while(root->left!=NULL)
        root=root->left;
    return root;
}
node_t* delete(node_t*root,int key){
    if(root==NULL)
        return root;
    if(key < root->data)
        root->left=delete(root->left,key);
    else if(key > root->data)
        root->right=delete(root->right,key);
    else {
        if(root->left==root->right){
            free(root);
            root=NULL;
        }
        else if(root->left==NULL){
            node_t*tmp=root;
            root=root->right;
            free(tmp);
        }
        else if(root->right==NULL){
            node_t*tmp=root;
            root=root->left;
            free(tmp);
        }
        else {
            node_t*min=find_minimum(root->right);
            root->data=min->data;
            root->right=delete(root->right,root->data);
        }
    }

    if(root==NULL)
        return root;
    root->height=max(get_height(root->left),get_height(root->right))+1;
    int balance = get_balance_factor(root);

    if(balance > 1 && get_balance_factor(root->left) >=0 )
        return right_rotate(root);
    if(balance > 1 && get_balance_factor(root->left) < 0 )
    {
        root->left=left_rotate(root->left);
        return right_rotate(root);
    }
    if(balance < -1 && get_balance_factor(root->right) <= 0)
        return left_rotate(root);
    if(balance < -1 && get_balance_factor(root->right) > 0){
        root->right=right_rotate(root->right);
        return left_rotate(root);
    }
    return root;
}

void preorder(node_t*root){
    if(root){
        printf("%d ",root->data);
        preorder(root->left);
        preorder(root->right);
    }
}

int main(){
    node_t*root=NULL;
    int n,data,k;
    scanf("%d",&n);
    while(n--){
        scanf("%d",&data);
        root=insert(root,data);
    }
    preorder(root);
    printf("\n");
    scanf("%d",&k);
    root=delete(root,k);
    preorder(root);
    printf("\n");
}

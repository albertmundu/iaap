#include <stdio.h>
#include <stdlib.h>


struct node {
    int data;
    int height;
    struct node *left;
    struct node *right;
};

struct node*createnode(int data){
    struct node*tmp=(struct node*)malloc(sizeof(struct node));
    tmp->data=data;
    tmp->height=1;
    tmp->left=NULL;
    tmp->right=NULL;
    return tmp;
}

int max(int a,int b){
    return (a>b)?a:b;
}

int get_height(struct node*root){
    if(root)
        return root->height;
    return 0;
}

int get_balance_factor(struct node*root){
    return get_height(root->left)-get_height(root->right);
}

struct node*right_rotate(struct node*root){
    struct node*l=root->left;
    struct node*lr=l->right;

    l->right=root;
    root->left=lr;

    root->height=max(get_height(root->left),get_height(root->right))+1;
    l->height=max(get_height(l->left),get_height(l->right))+1;

    return l;

}

struct node*left_rotate(struct node*root){
    struct node*r=root->right;
    struct node*rl=r->left;

    r->left=root;
    root->right=rl;

    root->height=max(get_height(root->left),get_height(root->left))+1;
    r->height=max(get_height(r->left),get_height(r->right))+1;

    return r;
}

struct node*insert(struct node*root,int data){
    if(root==NULL)
        return createnode(data);
    if(data <=root->data)
        root->left=insert(root->left,data);
    else
        root->right=insert(root->right,data);
    
    root->height=max(get_height(root->left),get_height(root->right))+1;

    int bal=get_balance_factor(root);

    if(bal > 1 && data < root->left->data)
        return right_rotate(root);
    
    if(bal < -1 && data > root->right->data)
        return left_rotate(root);

    if(bal > 1 && data > root->left->data){
        root->left=left_rotate(root->left);
        return right_rotate(root);
    }

    if(bal < -1 && data < root->right->data){
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

struct node*find_minimum(struct node*root){
    while(root->left!=NULL)
        root=root->left;
    return root;
}

struct node*delete(struct node*root,int key){
    if(root==NULL)
        return root;
    if(key < root->left->data)
        root->left=delete(root->left,key);
    else if(key > root->right->data)
        root->right=delete(root->right,key);
    else{
        if(root->left==root->right)
        {
            free(root);
            root=NULL;
        }
        else if(root->left==NULL){
            struct node*tmp=root;
            root=root->right;
            free(tmp);
        }
        else if(root->right==NULL){
            struct node*tmp=root;
            root=root->left;
            free(tmp);
        }
        else{
            struct node*tmp=find_minimum(root->right);
            root->data=tmp->data;
            root->right=delete(root->right,tmp->data);  
        }
    }

    if(!root)
        return root;

    root->height=max(get_height(root->left),get_height(root->right))+1;

    int balance=get_balance_factor(root);

    
}

int main(){
    struct node*root=NULL;
    int n,data,k;
    scanf("%d",&n);
    while(n--){
        scanf("%d",&data);
        root=insert(root,data);
    }
    scanf("%d",&k);
    preorder(root);
    while(k--){
        scanf("%d",&data);
        delete(root,data);
        preorder(root);
    }
}


#include <stdio.h>
#include <stdlib.h>


typedef struct node_s
{
    int val;
    struct node_s* left;
    struct node_s* right;
    int ht;
} node;

node * createnode(int val){
    node*tmp=(node*)malloc(sizeof(node));
    tmp->val=val;
    tmp->left=NULL;
    tmp->right=NULL;
    tmp->ht=0;
    return tmp;
}

int get_height(node*root){
    if(root)
        return root->ht;
    return -1;
}

int max(int a,int b){
    return (a>b)?a:b;
}

int get_balance_factor(node*root){
    if(root)
        return get_height(root->left)-get_height(root->right);
    return 0;
}

node* right_rotate(node*root){
    node*l=root->left;
    node*lr=l->right;
    
    l->right=root;
    root->left=lr;
    
    root->ht=max(get_height(root->left),get_height(root->right))+1;
    l->ht=max(get_height(l->left),get_height(l->right))+1;
    return l;
}
node* left_rotate(node*root){
    node*r=root->right;
    node*rl=r->left;
    
    r->left=root;
    root->right=rl;
    
    root->ht=max(get_height(root->left),get_height(root->right))+1;
    r->ht=max(get_height(r->left),get_height(r->right))+1;
    return r;
}


node * insert(node * root,int val)
{
   if(root==NULL)
       return createnode(val);
   if(val <= root->val)
       root->left=insert(root->left,val);
   else
       root->right=insert(root->right,val);
   root->ht=max(get_height(root->left),get_height(root->right))+1;
   int bal=get_balance_factor(root);
    
   if(bal > 1 && val < root->left->val)
       return right_rotate(root);
   if(bal > 1 && val > root->left->val){
       root->left=left_rotate(root->left);
       return right_rotate(root);
   }
   if(bal < -1 && val > root->right->val)
       return left_rotate(root);
   if(bal < -1 && val < root->right->val)
   {
       root->right=right_rotate(root->right);
       return left_rotate(root);
   }
    return root;
  
}

void preorder(node*root){
    if(root){
        printf("%d -> %d, ",root->val,get_balance_factor(root));
        preorder(root->left);
        preorder(root->right);
    }
}
int main(){
    node*root=NULL;
    int n,data;
    scanf("%d",&n);
    for(int i=0;i<n;i++){
        scanf("%d",&data);
        root=insert(root,data);
    }
    preorder(root);
    printf("\n");
}
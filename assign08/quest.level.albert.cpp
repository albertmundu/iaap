#include <cstdio>
#include <cstdlib>
#include <iostream>

struct node {
    int data;
    struct node*left;
    struct node*right;
};
struct node*createnode(int data){
    struct node*tmp=malloc(sizeof(struct node));
    tmp->data=data;
    tmp->left=NULL;
    tmp->right=NULL;
    return tmp;
}

struct node*insert(struct node*root,int data){
    if(root==NULL)
        root=createnode(data);
    else {
        if(data <= root->data)
            root->left=insert(root->left,data);
        else
            root->right=insert(root->right,data);
    }
    return root;
}

void inorder_traversal(struct node*root){
    if(root){
        inorder_traversal(root->left);
        printf("%d ",root->data);
        inorder_traversal(root->right);
    }
}

void levelorder_traversal(struct node*root){
    if(root==NULL) return;
    queue<struct node*> Q;
    Q.push(root);
    while(!Q.empty()){
        struct node*current=Q.front();
        cout<<current->data<<endl;
        if(current->left!=NULL) Q.push(current->left);
        if(current->right!=NULL) Q.push(current->right);
        Q.pop();
    }

}

int main(){
    struct node*root=NULL;
    int n,data;
    scanf("%d",&n);
    for(int i=0;i<n;i++)
    {
        scanf("%d",&data);
        root=insert(root,data);
    }
    inorder_traversal(root);
    printf("\n");
    return 0;
}

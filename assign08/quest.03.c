#include <stdio.h>
#include <stdlib.h>
#define nl printf("\xa")

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
    struct node*new_node=createnode(data);
    if(*root==NULL){
        *root=new_node;
    }
    else{
        struct node*parent=NULL,*child=*root;
        for(;child!=NULL;){
            parent=child;
            if(data <= child->data)
                child=child->left;
            else
                child=child->right;
        }
        if(data <= parent->data)
            parent->left=new_node;
        else
            parent->right=new_node;

    }

}

void inorder_traversal(struct node*root){
    if(root){
        inorder_traversal(root->left);
        printf("%d ",root->data);
        inorder_traversal(root->right);
    }
}
void delete(struct node*root){
    if(root){
        delete(root->left);
        delete(root->right);
        free(root);
    }
}
int checker(struct node*root1,struct node*root2){
    if(root1==NULL || root2==NULL)
        return root1==root2;
    return (root1->data == root2->data && checker(root1->left,root2->left) && checker(root1->right,root2->right));
}

int main(){
    struct node*root1=NULL,*root2=NULL;
    int n,data,t;
    scanf("%d",&t);
    scanf("%d",&n);
    while(t--){
        for(int i=0;i<n;i++){
            scanf("%d",&data);
            insert(&root1,data);
        }
        for(int i=0;i<n;i++){
            scanf("%d",&data);
            insert(&root2,data);
        }
        if(checker(root1,root2))
            printf("y\n");
        else
            printf("n\n");
        
        delete(root1);delete(root2);
        root1=NULL;
        root2=NULL;
    }
    //inorder_traversal(root1);
    //nl;
    //inorder_traversal(root2);
    //nl;
    return 0;
}

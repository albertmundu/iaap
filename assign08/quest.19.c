#include <stdio.h>
#include <stdlib.h>


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

int post(struct node*root,int depth){
    if(root){
        int lheight=post(root->left,depth+1);
        int rheight=post(root->right,depth+1);
        int height=0;
        if(lheight>=rheight)
            height=lheight;
        else
            height=rheight;
        printf("node: %d height: %d depth: %d\n",root->data,height,depth);

        return height+1;
    }
    return 0;
}

int main(){
    struct node*root=NULL;
    int n,data;
    scanf("%d",&n);
    while(n--){scanf("%d",&data);insert(&root,data);}
    post(root,0);
    printf("\n");
    return 0;
}

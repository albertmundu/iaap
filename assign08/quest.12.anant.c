#include<stdio.h>
#include<stdlib.h>

struct node {
    int data;
    struct node* left;
    struct node* right;
};

struct node* createNewNode(int data)
{
    struct node* temp = (struct node*) malloc(sizeof(struct node));
    temp->data = data;
    temp->left=NULL;
    temp->right=NULL;
    return temp;
}

void insert(struct node** root, int data)
{
    if(!*root)
        *root=createNewNode(data);
    else {
        if(data<(*root)->data)
            insert(&(*root)->left,data);
        else 
            insert(&(*root)->right,data);
    }
}

void printin(struct node* root,struct node* p, int k)
{
    if(root) {
        if(root->data==key) {

            printf("%d ",root->data);
        }else {
            printk(root->left,k-1);
            printk(root->right,k-1);
        }
    }
}

int main()
{
    int n,i,key,data;
    struct node* root=NULL;
    scanf("%d",&n);
    for(i=0;i<n;i++) {
        scanf("%d",&data);
        insert(&root,NULL,data);
    }
    scanf("%d",&key);
    printin(root,key);

return 0;
}

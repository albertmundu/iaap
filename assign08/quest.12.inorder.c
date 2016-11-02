#include <stdio.h>
#include <stdlib.h>

struct node {
	int data;
	struct node*left;
	struct node*right;
};

struct node* createnode(int data){
	struct node*tmp=(struct node*)malloc(sizeof(struct node));
	tmp->data=data;
	tmp->left=NULL;
	tmp->right=NULL;
	return tmp;
}


void insert(struct node**root,int data){
	struct node*newnode=createnode(data);
	if(*root==NULL){
		*root=newnode;
	}
	else{
		struct node*parent=NULL,*child=NULL;
		for(child=*root;child!=NULL;){
			parent=child;
			if(child->data > data){
				child=child->left;
			}
			else{
				child=child->right;
			}
		}
		if(data <= parent->data){
			parent->left=newnode;
		}
		else
			parent->right=newnode;

		}
}

int search(struct node*root,int k){
	if(root!=NULL){
		if(k==root->data)
			return 1;
		if(k<root->data)
			return search(root->left,k);
		else 
			return search(root->right,k);
	}
	return 0;
}
void inorder(struct node*root,struct node**pre,struct node**key, struct node**suc, int k){
	if(root)
	{
		inorder(root->left,pre,key,suc,k);
		if(!*suc) {
            if(*key) {
                *suc=root;    
            } else {
                if(root->data==k) {
                    *key=root;
                } else {
                    *pre=root;
                }
            }
        }
        else return;
		inorder(root->right,pre,key,suc,k);
	}
}



int main(){
	struct node*root=NULL;
    struct node*pre=NULL;
    struct node*key=NULL;
    struct node*suc=NULL;
	int n,data,k;
	scanf("%d",&n);
	for(int i=0;i<n;i++){
		scanf("%d",&data);
		insert(&root,data);
	}
	scanf("%d",&k);
    inorder(root,&pre,&key,&suc,k);
    if(key) {
        if(pre)
            printf("%d ",pre->data);
        if(suc)    
            printf("%d ",suc->data);
    } else {
        printf("INFO: No key=%d in BST\n",k);
    }

	return 0;
}

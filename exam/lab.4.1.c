#include <stdio.h>
#include <stdlib.h>

struct node {
	int data;
	struct node * left;
	struct node * right;
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
	else{
		struct node*child=*root,*parent=NULL;
		for(;child!=NULL;){
			parent=child;
			if(data <= child->data)
				child=child->left;
			else
				child=child->right;
		}
		if(data <= parent->data)
			parent->left=createnode(data);
		else
			parent->right=createnode(data);
	}
}
void preorder(struct node*root){
	if(root){
		printf("%d ",root->data);
		preorder(root->left);
		preorder(root->right);
	}
}

int kdes(struct node*root,int k){
	if(root){
		int lh=kdes(root->left,k);
		int lr=kdes(root->right,k);
		int knodes=0;
		knodes=lh+lr;
		if(knodes==k){
			printf("%d ",root->data);
		}
		return knodes+1;

	}
	return 0;
}

int main(){
	struct node*root=NULL;
	int n,data,k;
	scanf("%d",&n);
	while(n--){
		scanf("%d",&data);
		insert(&root,data);
	}
	scanf("%d",&k);
	//preorder(root);
	//printf("\n");
	kdes(root,k);
	printf("\n");
	return 0;
}

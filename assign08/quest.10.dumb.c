#include <stdio.h>
#include <stdlib.h>

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

void insert(struct node**head,int data){
	if(*head==NULL){
		*head=createnode(data);
	}
	else{
		struct node*child=*head,*parent=NULL;
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

int search(struct node*root,int k){
	struct node*child=root;
	for(;child!=NULL;){
		if(k==child->data)
			return 1;
		if(k< child->data) child=child->left;
		else if(k>child->data) child=child->right;
	}
	return 0;
}

void mirror_insert(struct node**head,int data){
	if(*head==NULL){
		*head=createnode(data);
	}
	else{
		struct node*child=*head,*parent=NULL;
		for(;child!=NULL;){
			parent=child;
			if(data <= child->data)
				child=child->right;
			else 
				child=child->left;
		}
		if(data <= parent->data)
			parent->right=createnode(data);
		else
			parent->left=createnode(data);
	}

}

void mirror(struct node**dest,struct node*root){
	if(root){
		mirror_insert(dest,root->data);
		mirror(dest,root->left);
		mirror(dest,root->right);
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
	struct node*root1=NULL,*root2=NULL;
	int n,data;
	scanf("%d",&n);
	while(n--){scanf("%d",&data);insert(&root1,data);}
	inorder(root1);
	printf("\n");
	mirror(&root2,root1);
	inorder(root2);
	printf("\n");
}

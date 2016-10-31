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

int main(){
	struct node*root=NULL;
	int n,data;
	scanf("%d",&n);
	for(int i=0;i<n;i++){
		scanf("%d",&data);
		insert(&root,data);
	}
	scanf("%d",&n);
	for(int i=0;i<n;i++){
		scanf("%d",&data);
		if(search(root,data))
			printf("Y\n");
		else
			printf("N\n");
	}
	return 0;
}

#include "linkedlist.h"
#include <stdio.h>
#include <stdlib.h>

struct node* createnode(int data){
	struct node*tmp=(struct node*)malloc(sizeof(struct node));
	tmp->data=data;
	tmp->next=NULL;
	return tmp;
}

void displaylist(struct node*head){
	struct node*tmp=head;
	for(;tmp!=NULL;tmp=tmp->next){
		printf("%d->",tmp->data);
	}
	printf("\n");
}

int getlistlength(struct node*head){
	struct node*tmp=head;
	int count=0;
	for(;tmp!=NULL;tmp=tmp->next)
		count++;
	return count;
}

int getlistsize(struct node*head){
	int length=getlistlength(head);
	return length*sizeof(struct node);
}

void deletefirstnode(struct node**head){
	struct node*tmp=(*head);
	(*head)=(*head)->next;
	free(tmp);
}

void insert(struct node**head,struct node**tail,int data){
	struct node*new_node=createnode(data);
	if((*head)==NULL){
		(*head)=new_node;
		(*tail)=new_node;
	}
	else {
		(*tail)->next=new_node;
		(*tail)=new_node;
	}

}

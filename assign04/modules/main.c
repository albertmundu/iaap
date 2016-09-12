#include <stdio.h>
#include "linkedlist.h"


int main(int argc,char*argv[]){
	struct node*head=NULL;
	struct node*tail=NULL;

	int n,i,data;
	printf("Enter the size of the list: ");
	scanf("%d",&n);

	for(i=0;i<n;i++){
		scanf("%d",&data);
		insert(&head,&tail,data);
	}

	displaylist(head);
	deletefirstnode(&head);
	displaylist(head);
	return 0;
}
